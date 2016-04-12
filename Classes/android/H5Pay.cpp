#include "H5Pay.h"
#include "CrossApp.h"
#include "platform/android/jni/JniHelper.h"


namespace PaySdk
{

	void H5Pay::SetUrl(std::string url)
	{		
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/H5Pay", "setUrl", "(Ljava/lang/String;)V"))
		{
			jstring j_str = jni.env->NewStringUTF(url.c_str());;
			jni.env->CallStaticVoidMethod(jni.classID, jni.methodID, j_str);
			jni.env->DeleteLocalRef(jni.classID);
			jni.env->DeleteLocalRef(j_str);
		}
	}

	std::string H5Pay::GetUrl()
	{
		std::string str;
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/H5Pay", "getUrl", "()Ljava/lang/String;"))
		{
 			jstring j_string = (jstring)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
  			str = JniHelper::jstring2string(j_string);
 			jni.env->DeleteLocalRef(jni.classID);
 			jni.env->DeleteLocalRef(j_string);
		}
		return str;
	}

	ErrorValue H5Pay::DoH5Pay()
	{
		int ret = 0;
		JniMethodInfo jni;
		if (JniHelper::getStaticMethodInfo(jni, "com/alipay/sdk/pay/H5Pay", "h5Pay", "()I"))
		{
			ret = (int)jni.env->CallStaticObjectMethod(jni.classID, jni.methodID);
			CCLog("ret=%d", ret);
			jni.env->DeleteLocalRef(jni.classID);
		}
		return (ErrorValue)ret;
	}	



};



