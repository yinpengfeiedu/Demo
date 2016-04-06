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

	private static Activity mContext;
	private WebView mWebView;
	private String mUrl;
	
	public static void init(Activity activity) {
		mContext = activity;
	}
	
	public void setUrl(String url) {
		mUrl = url;
		System.out.println("ggggggggggggggggggg:" + mUrl);
	}
	
	public String getUrl() {
		return mUrl;
	}	
	
	public int h5Pay() {
		if (TextUtils.isEmpty(mUrl)) {
			System.out.println("ggggggggggggggggggg");
			return 1;
		}
		((Activity)mContext).requestWindowFeature(Window.FEATURE_NO_TITLE);
		LinearLayout layout = new LinearLayout(mContext);
		LayoutParams params = new LayoutParams(LayoutParams.MATCH_PARENT, LayoutParams.MATCH_PARENT);
		layout.setOrientation(LinearLayout.VERTICAL);
		((Activity)mContext).setContentView(layout, params);
		System.out.println("0000000000000000000");
		mWebView = new WebView(mContext);
		params.weight = 1;
		mWebView.setVisibility(View.VISIBLE);
		layout.addView(mWebView, params);
		System.out.println("1111111111111111111");
		WebSettings settings = mWebView.getSettings();
		//settings.setUserAgentString(
				//"User-Agent:Mozilla/5.0 (Macintosh; U; Intel Mac OS X 10_6_8; en-us) AppleWebKit/534.50 (KHTML, like Gecko) Version/5.1 Safari/534.50");
		settings.setRenderPriority(RenderPriority.HIGH);
		settings.setSupportMultipleWindows(true);
		settings.setJavaScriptEnabled(true);
		settings.setSavePassword(false);
		settings.setJavaScriptCanOpenWindowsAutomatically(true);
		settings.setMinimumFontSize(settings.getMinimumFontSize() + 8);
		settings.setAllowFileAccess(false);
		System.out.println("222222222222222222222");
		settings.setTextSize(WebSettings.TextSize.NORMAL);
		mWebView.setVerticalScrollbarOverlay(true);
		System.out.println("33333333333333333");
		mWebView.setWebViewClient(new MyWebViewClient());
		System.out.println("44444444444444444444");
		mWebView.loadUrl(mUrl);
		return 10000;
	}

	private class MyWebViewClient extends WebViewClient {

		@Override
		public boolean shouldOverrideUrlLoading(final WebView view, String url) {
			final PayTask task = new PayTask(mContext);
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
