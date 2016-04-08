#include "Pay.h"

#if (CC_TARGET_PLATFORM != CC_PLATFORM_MAC && CC_TARGET_PLATFORM != CC_PLATFORM_IOS)
#include "platform/android/jni/JniHelper.h"
#else
#include "Alipay.h"
#endif



namespace PaySdk
{
    Pay *Pay::mPay = NULL;
    
    Pay *Pay::GetInstance()
    {
        if (mPay == NULL)
        {
            mPay = new Pay();
        }
        return mPay;
    }

	void Pay::SetPartner(std::string pID)
	{
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setPartner", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(pID.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
		}
#else
        NSString *nstring = [NSString stringWithCString:pID.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setPid : nstring];
#endif
	}

	std::string Pay::getPartner()
	{
        std::string str;
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getPartner", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
        }
#else
        NSString *nstring = [[Alipay defaultPay] getPid];
        str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
#endif
		return str;
	}

	void Pay::SetSeller(std::string accountNo)
	{
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setSeller", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(accountNo.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
        }
#else
        NSString *nstring = [NSString stringWithCString:accountNo.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setAccountNo: nstring];
#endif
	}

	std::string Pay::getSeller()
	{
        std::string str;
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getSeller", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
        }
#else
        NSString *nstring = [[Alipay defaultPay] getAccountNo];
        str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
#endif
		return str;
	}

	void Pay::SetRsaPrivate(std::string priKey)
	{
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setRsaPrivate", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(priKey.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
        }
#else
        NSString *nstring = [NSString stringWithCString:priKey.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setPrivateKey: nstring];
#endif
	}

	std::string Pay::getRsaPrivate()
	{
        std::string str;
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getRsaPrivate", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
        }
#else
        NSString *nstring = [[Alipay defaultPay] getPrivateKey];
        str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
#endif
		return str;
	}

	void Pay::SetRsaPublic(std::string pubKey)
	{
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setRsaPublic", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(pubKey.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
        }
#else
        NSString *nstring = [NSString stringWithCString:pubKey.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setPublicKey: nstring];
#endif
	}

	std::string Pay::getRsaPublic()
	{
        std::string str;
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getRsaPublic", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
        }
#else
        NSString *nstring = [[Alipay defaultPay] getPublicKey];
        str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
#endif
		return str;
	}

	void Pay::setOrderInfo(std::string order)
	{
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setOrderInfo", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(order.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
        }
#else
        NSString *nstring = [NSString stringWithCString:order.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setOrder: nstring];
#endif
	}

	std::string Pay::getOrderInfo()
	{
        std::string str;
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getOrderInfo", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
        }
#else
        NSString *nstring = [[Alipay defaultPay] getOrder];
        str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
#endif
		return str;
	}

	void Pay::setSignValue(std::string sign)
	{
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setSignValue", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(sign.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
        }
#else
        NSString *nstring = [NSString stringWithCString:sign.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setSignValue: nstring];
#endif
	}

	std::string Pay::getSignValue()
	{
        std::string str;
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getSignValue", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
        }
#else
        NSString *nstring = [[Alipay defaultPay] getSignValue];
        str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
#endif
		return str;
	}

	void Pay::setSignType(std::string type)
	{
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "setSignType", "(Ljava/lang/String;)V"))
		{
			jstring j_id = jni.env->NewStringUTF(type.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_id);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_id);
        }
#else
        NSString *nstring = [NSString stringWithCString:type.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setSignType: nstring];
#endif
	}

	std::string Pay::getSignType()
	{
        std::string str;
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		std::string str;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "getSignType", "()Ljava/lang/String;"))
		{
			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			str = JniHelper::jstring2string(j_string);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_string);
        }
#else
        NSString *nstring = [[Alipay defaultPay] getSignType];
        str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
#endif
		return str;
	}

	ErrorValue Pay::DoPay()
	{
        int ret = 0;
#if CC_TARGET_PLATFORM == CC_TARGET_ANDROID
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/Pay", "pay", "()I"))
		{
			ret = (int)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			CCLog("----------****%d", ret);
			jni.env->DeleteLocalRef(jni.classID);
        }
#else
        ret = [[Alipay defaultPay] pay];
#endif
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




