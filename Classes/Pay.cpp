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
		// ǩԼ���������ID
		std::string orderInfo = "partner=\"abcdefg\"";

		// ǩԼ����֧�����˺�
		orderInfo += "&seller_id=\"1234567890\"";

		// �̻���վΨһ������
		orderInfo += "&out_trade_no=\"201603231441630\"";

		// ��Ʒ����
		orderInfo += "&subject=";
		orderInfo += name;

		// ��Ʒ����
		orderInfo += "&body=";
		orderInfo += description;

		// ��Ʒ���
		orderInfo += "&total_fee=";
		orderInfo += price;

		// �������첽֪ͨҳ��·��
		orderInfo += "&notify_url=\"http://notify.msp.hk/notify.htm\"";

		// ����ӿ����ƣ� �̶�ֵ
		orderInfo += "&service=\"mobile.securitypay.pay\"";

		// ֧�����ͣ� �̶�ֵ
		orderInfo += "&payment_type=\"1\"";

		// �������룬 �̶�ֵ
		orderInfo += "&_input_charset=\"utf-8\"";

		// ����δ����׵ĳ�ʱʱ��
		// Ĭ��30���ӣ�һ����ʱ���ñʽ��׾ͻ��Զ����رա�
		// ȡֵ��Χ��1m��15d��
		// m-���ӣ�h-Сʱ��d-�죬1c-���죨���۽��׺�ʱ����������0��رգ���
		// �ò�����ֵ������С���㣬��1.5h����ת��Ϊ90m��
		orderInfo += "&it_b_pay=\"30m\"";

		// extern_tokenΪ���������Ȩ��ȡ����alipay_open_id,���ϴ˲����û���ʹ����Ȩ���˻�����֧��
		// orderInfo += "&extern_token=" + "\"" + extern_token + "\"";

		// ֧��������������󣬵�ǰҳ����ת���̻�ָ��ҳ���·�����ɿ�
		orderInfo += "&return_url=\"m.alipay.com\"";

		// �������п�֧���������ô˲���������ǩ���� �̶�ֵ ����ҪǩԼ���������п����֧��������ʹ�ã�
		// orderInfo += "&paymethod=\"expressGateway\"";

		return orderInfo;
	}





};




