package com.alipay.sdk.pay;

import com.alipay.sdk.app.PayTask;
import com.alipay.sdk.util.H5PayResultModel;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.DialogInterface.OnClickListener;
import android.text.TextUtils;
import android.view.View;
import android.view.Window;
import android.webkit.WebSettings;
import android.webkit.WebSettings.RenderPriority;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.LinearLayout;
import android.widget.LinearLayout.LayoutParams;

@SuppressLint({ "SetJavaScriptEnabled", "InlinedApi" })
public class H5Pay{

	private Context mContext;
	private WebView mWebView;
	private String mUrl;
	
	public void init(Activity activity) {
		mContext = activity;
	}
	
	public void setUrl(String url) {
		mUrl = url;
	}
	
	public String getUrl() {
		return mUrl;
	}	
	
	public void h5Pay() {
		if (TextUtils.isEmpty(mUrl)) {
			// 测试H5支付，必须设置要打开的url网站
			new AlertDialog.Builder(mContext).setTitle("警告")
					.setMessage("必须配置需要打开的url 站点，请在PayDemoActivity类的h5Pay中配置")
					.setPositiveButton("确定", new OnClickListener() {

						@Override
						public void onClick(DialogInterface arg0, int arg1) {
							((Activity)mContext).finish();
						}
					}).show();

		}
		((Activity)mContext).requestWindowFeature(Window.FEATURE_NO_TITLE);
		LinearLayout layout = new LinearLayout(mContext);
		LayoutParams params = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT);
		layout.setOrientation(LinearLayout.VERTICAL);
		((Activity)mContext).setContentView(layout, params);

		mWebView = new WebView(mContext);
		params.weight = 1;
		mWebView.setVisibility(View.VISIBLE);
		layout.addView(mWebView, params);

		WebSettings settings = mWebView.getSettings();
		settings.setUserAgentString(
				"User-Agent:Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_6_8; en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50");
		settings.setRenderPriority(RenderPriority.HIGH);
		settings.setSupportMultipleWindows(true);
		settings.setJavaScriptEnabled(true);
		settings.setSavePassword(false);
		settings.setJavaScriptCanOpenWindowsAutomatically(true);
		settings.setMinimumFontSize(settings.getMinimumFontSize() + 8);
		settings.setAllowFileAccess(false);
		settings.setTextSize(WebSettings.TextSize.NORMAL);
		mWebView.setVerticalScrollbarOverlay(true);
		mWebView.setWebViewClient(new MyWebViewClient());
		mWebView.loadUrl(mUrl);		
	}

	private class MyWebViewClient extends WebViewClient {

		@Override
		public boolean shouldOverrideUrlLoading(final WebView view, String url) {
			final PayTask task = new PayTask((Activity)mContext);
			final String ex = task.fetchOrderInfoFromH5PayUrl(url);
			if (!TextUtils.isEmpty(ex)) {
				new Thread(new Runnable() {
					public void run() {
						H5PayResultModel result = task.h5Pay(ex, true);
						if (!TextUtils.isEmpty(result.getReturnUrl())) {
							view.loadUrl(result.getReturnUrl());
						}
					}
				}).start();
			} else {
				view.loadUrl(url);
			}
			return true;
		}
	}

}
