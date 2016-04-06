#include "Pay.h"

namespace PaySdk
{

	void Pay::SetPartner(std::string pID)
	{
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setPartner", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(pID.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
		}
	}

	std::string Pay::getPartner()
	{
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getPartner", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
		}
		return str;
	}

	void Pay::SetSeller(std::string accountNo)
	{
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setSeller", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(accountNo.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
		}
	}

	std::string Pay::getSeller()
	{
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getSeller", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
		}
		return str;
	}

	void Pay::SetRsaPrivate(std::string priKey)
	{
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setRsaPrivate", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(priKey.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
		}
	}

	std::string Pay::getRsaPrivate()
	{
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getRsaPrivate", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
		}
		return str;
	}

	void Pay::SetRsaPublic(std::string pubKey)
	{
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setRsaPublic", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(pubKey.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
		}
	}

	std::string Pay::getRsaPublic()
	{
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getRsaPublic", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
		}
		return str;
	}

	void Pay::setOrderInfo(std::string order)
	{
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setOrderInfo", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(order.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
		}
	}

	std::string Pay::getOrderInfo()
	{
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getOrderInfo", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
		}
		return str;
	}

	void Pay::setSignValue(std::string sign)
	{
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setSignValue", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(sign.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
		}
	}

	std::string Pay::getSignValue()
	{
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getSignValue", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
		}
		return str;
	}

	void Pay::setSignType(std::string type)
	{
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setSignType", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(type.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
		}
	}

	std::string Pay::getSignType()
	{
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getSignType", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
		}
		return str;
	}

	ErrorValue Pay::DoPay()
	{
		int ret = 0;
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "pay", "()I"))
		{
			ret = (int)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			CCLog("----------****%d", ret);
			jni.env->DeleteLocalRef(jni.classID);
		}
		return (ErrorValue)ret;
	}

	std::string Pay::GetSampleOrderInfo(std::string name, std::string description, std::string price)
	{
		// 签约合作者身份ID
		std::string orderInfo = "partner=\"abcdefg\"";

		// 签约卖家支付宝账号
		orderInfo += "&seller_id=\"1234567890\"";

		// 商户网站唯一订单号
		orderInfo += "&out_trade_no=\"201603231441630\"";

		// 商品名称
		orderInfo += "&subject=";
		orderInfo += name;

		// 商品详情
		orderInfo += "&body=";
		orderInfo += description;

		// 商品金额
		orderInfo += "&total_fee=";
		orderInfo += price;

		// 服务器异步通知页面路径
		orderInfo += "&notify_url=\"http://notify.msp.hk/notify.htm\"";

		// 服务接口名称， 固定值
		orderInfo += "&service=\"mobile.securitypay.pay\"";

		// 支付类型， 固定值
		orderInfo += "&payment_type=\"1\"";

		// 参数编码， 固定值
		orderInfo += "&_input_charset=\"utf-8\"";

		// 设置未付款交易的超时时间
		// 默认30分钟，一旦超时，该笔交易就会自动被关闭。
		// 取值范围：1m～15d。
		// m-分钟，h-小时，d-天，1c-当天（无论交易何时创建，都在0点关闭）。
		// 该参数数值不接受小数点，如1.5h，可转换为90m。
		orderInfo += "&it_b_pay=\"30m\"";

		// extern_token为经过快登授权获取到的alipay_open_id,带上此参数用户将使用授权的账户进行支付
		// orderInfo += "&extern_token=" + "\"" + extern_token + "\"";

		// 支付宝处理完请求后，当前页面跳转到商户指定页面的路径，可空
		orderInfo += "&return_url=\"m.alipay.com\"";

		// 调用银行卡支付，需配置此参数，参与签名， 固定值 （需要签约《无线银行卡快捷支付》才能使用）
		// orderInfo += "&paymethod=\"expressGateway\"";

		return orderInfo;
	}





};




