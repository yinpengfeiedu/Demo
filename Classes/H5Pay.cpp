#include "H5Pay.h"


extern "C"{

	static pthread_key_t s_threadKey;

	static void detach_current_thread(void *env) {
		JniHelper::getJavaVM()->DetachCurrentThread();
	}

	static bool getEnv(JNIEnv **env)
	{
		bool bRet = false;

		switch (JniHelper::getJavaVM()->GetEnv((void**)env, JNI_VERSION_1_4))
		{
		case JNI_OK:
			bRet = true;
			break;
		case JNI_EDETACHED:
			pthread_key_create(&s_threadKey, detach_current_thread);
			if (JniHelper::getJavaVM()->AttachCurrentThread(env, 0) < 0)
			{
				CCLog("Failed to get the environment using AttachCurrentThread()");
				break;
			}
			if (pthread_getspecific(s_threadKey) == NULL)
				pthread_setspecific(s_threadKey, env);
			bRet = true;
			break;
		default:
			CCLog("Failed to get the environment using GetEnv()");
			break;
		}

		return bRet;
	}



}





namespace PaySdk
{

	bool H5Pay::Init()
	{
		bool result = false;
		JNIEnv *pEnv = 0;
		bool ret = getEnv(&pEnv);
		if (ret && pEnv)
		{
			jmethodID methodObjID = 0;
			j_mClass = pEnv->FindClass("com/alipay/sdk/pay/H5Pay");
			methodObjID = pEnv->GetMethodID(j_mClass, "<init>", "()V");
			if (j_mClass && methodObjID)
			{
				j_mObj = pEnv->NewObject(j_mClass, methodObjID);
				result = true;
			}
		}
		return result;
	}

	void H5Pay::SetUrl(std::string url)
	{		
		JNIEnv *pEnv = 0;		
		bool ret = getEnv(&pEnv);
		if (ret && pEnv)
		{
			jfieldID fieldID = 0;
			fieldID = pEnv->GetFieldID(j_mClass, "mUrl", "Ljava/lang/String;");
			if (fieldID)
			{
				pEnv->SetObjectField(j_mObj, fieldID, pEnv->NewStringUTF(url.c_str()));
			}
		}
	}

	std::string H5Pay::GetUrl()
	{
		JNIEnv *pEnv = 0;
		bool ret = getEnv(&pEnv);
		std::string str;
		if (ret && pEnv)
		{
			jmethodID methodID = pEnv->GetMethodID(j_mClass, "getUrl", "()Ljava/lang/String;");
			jstring j_string = (jstring)pEnv->CallObjectMethod(j_mObj, methodID);
			str = JniHelper::jstring2string(j_string);
			pEnv->DeleteLocalRef(j_string);
		}
		return str;
	}

	ErrorValue H5Pay::DoH5Pay()
	{
		int result = 0;
		JNIEnv *pEnv = 0;
		bool ret = getEnv(&pEnv);
		if (ret && pEnv)
		{
			jmethodID methodID = 0;
			methodID = pEnv->GetMethodID(j_mClass, "h5Pay", "()I");
			if (methodID)
			{
				result = (int)pEnv->CallObjectMethod(j_mObj, methodID);
			}
		}
		CCLog("ret=%d", result);
		return (ErrorValue)result;
	}	



};




