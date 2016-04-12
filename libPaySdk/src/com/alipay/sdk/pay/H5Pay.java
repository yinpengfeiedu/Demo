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
	private static String mUrl;
	
	public static void init(Activity activity) {
		mContext = activity;
	}
	
	public static void setUrl(String url) {
		mUrl = url;
	}
	
	public static String getUrl() {
		return mUrl;
	}	
	
	public static int h5Pay() {
		int ret = 0;
		if (TextUtils.isEmpty(mUrl)) {
			System.out.println("url is emtpty!");
			ret = 1;
		}
		
		final PayTask task = new PayTask(mContext);
		final String ex = task.fetchOrderInfoFromH5PayUrl(mUrl);
		if (!TextUtils.isEmpty(ex)) {
			new Thread(new Runnable() {
				public void run() {
					H5PayResultModel result = task.h5Pay(ex, true);					
				}
			}).start();
		}
		ret = 10000;
		return ret;
	}


}
