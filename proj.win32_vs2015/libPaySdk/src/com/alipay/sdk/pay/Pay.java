package com.alipay.sdk.pay;

import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import com.alipay.sdk.app.PayTask;
import android.annotation.SuppressLint;
import android.app.Activity;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.widget.Toast;

public class Pay{

	private static Activity mContext;	
	
	
	// 商户PID
	public static String PARTNER;
	// 商户收款账号
	public static String SELLER;
	// 商户私钥，pkcs8格式
	public static String RSA_PRIVATE;
	// 支付宝公钥
	public static String RSA_PUBLIC;
	//支付类型
	private static final int SDK_PAY_FLAG = 1;
	//订单信息
	private static String mOrderInfo;
	//签名值
	private static String mSignValue;
	//签名类型
	private static String mSignType;
	
	public static void init(Activity activity) {
		mContext = activity;
	}
	
	public static void setPartner(String pID) {
		PARTNER = pID;
	}
	
	public static String getPartner() {
		return PARTNER;
	}
	
	public static void setSeller(String accountNo) {
		SELLER = accountNo;
	}
	
	public static String getSeller() {
		return SELLER;
	}
	
	public static void setRsaPrivate(String priKey) {
		RSA_PRIVATE = priKey;
	}
	
	public static String getRsaPrivate() {
		return RSA_PRIVATE;
	}
	
	public static void setRsaPublic(String pubKey) {
		RSA_PUBLIC = pubKey;
	}
	
	public static String getRsaPublic() {
		return RSA_PUBLIC;
	}

	public static void setOrderInfo(String order) {
		mOrderInfo = order;
	}
	
	public static String getOrderInfo() {
		return mOrderInfo;
	}
	
	public static void setSignValue(String sign) {
		try {
			mSignValue = URLEncoder.encode(sign, "UTF-8");
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static String getSignValue() {
		return mSignValue;
	}
	
	public static void setSignType(String type) {
		mSignType = type;
	}
	
	public static String getSignType() {
		return mSignType;
	}
	
	
	@SuppressLint("HandlerLeak")
	private static Handler mHandler = new Handler() {
		@SuppressWarnings("unused")
		public void handleMessage(Message msg) {
			switch (msg.what) {
			case SDK_PAY_FLAG: {
				PayResult payResult = new PayResult((String) msg.obj);
				/**
				 * 同步返回的结果必须放置到服务端进行验证（验证的规则请看https://doc.open.alipay.com/doc2/
				 * detail.htm?spm=0.0.0.0.xdvAU6&treeId=59&articleId=103665&
				 * docType=1) 建议商户依赖异步通知
				 */
				String resultInfo = payResult.getResult();// 同步返回需要验证的信息

				String resultStatus = payResult.getResultStatus();
				// 判断resultStatus 为“9000”则代表支付成功，具体状态码代表含义可参考接口文档
				if (TextUtils.equals(resultStatus, "9000")) {
					Toast.makeText(mContext, "支付成功", Toast.LENGTH_SHORT).show();
				} else {
					// 判断resultStatus 为非"9000"则代表可能支付失败
					// "8000"代表支付结果因为支付渠道原因或者系统原因还在等待支付结果确认，最终交易是否成功以服务端异步通知为准（小概率状态）
					if (TextUtils.equals(resultStatus, "8000")) {
						Toast.makeText(mContext, "支付结果确认中", Toast.LENGTH_SHORT).show();

					} else {
						// 其他值就可以判断为支付失败，包括用户主动取消支付，或者系统返回的错误
						Toast.makeText(mContext, "支付失败", Toast.LENGTH_SHORT).show();
					}
				}
				break;
			}
			default:
				break;
			}
		};
	};

	/**
	 * call alipay sdk pay. 调用SDK支付
	 * 
	 */
	
	public static int pay() {		
		if (TextUtils.isEmpty(PARTNER) || TextUtils.isEmpty(RSA_PRIVATE) || TextUtils.isEmpty(SELLER)) {
			return 0;
		}
		
		/**
		 * 完整的符合支付宝参数规范的订单信息
		 */
		final String payInfo = mOrderInfo + "&sign=\"" + mSignValue + "\"&" + mSignType;

		Runnable payRunnable = new Runnable() {

			@Override
			public void run() {
				// 构造PayTask 对象
				PayTask alipay = new PayTask(mContext);
				// 调用支付接口，获取支付结果
				String result = alipay.pay(payInfo, true);

				Message msg = new Message();
				msg.what = SDK_PAY_FLAG;
				msg.obj = result;
				mHandler.sendMessage(msg);
			}
		};

		// 必须异步调用
		Thread payThread = new Thread(payRunnable);
		payThread.start();
		return 1;
	}	

}
