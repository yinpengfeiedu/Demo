#include "H5Pay.h"
#include "CrossApp.h"
#include "platform/android/jni/JniHelper.h"

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
	H5Pay *H5Pay::mH5Pay = NULL;

	static jclass m_jH5PayClass = NULL;

	static jobject m_jH5PayObject = NULL;

	H5Pay *H5Pay::GetInstance()
	{
		if (mH5Pay == NULL)
		{
			mH5Pay = new H5Pay();
			if (!mH5Pay->Init())
			{
				delete mH5Pay;
				mH5Pay = NULL;
			}
		}
		return mH5Pay;
	}

	void H5Pay::SetUrl(std::string url)
	{		
		JNIEnv *pEnv = 0;		
		bool ret = getEnv(&pEnv);
		if (ret && pEnv)
		{
			jfieldID fieldID = 0;
			fieldID = pEnv->GetFieldID(m_jH5PayClass, "mUrl", "Ljava/lang/String;");
			if (fieldID)
			{
				pEnv->SetObjectField(m_jH5PayObject, fieldID, pEnv->NewStringUTF(url.c_str()));
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
			jmethodID methodID = pEnv->GetMethodID(m_jH5PayClass, "getUrl", "()Ljava/lang/String;");
			jstring j_string = (jstring)pEnv->CallObjectMethod(m_jH5PayObject, methodID);
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
			methodID = pEnv->GetMethodID(m_jH5PayClass, "h5Pay", "()I");
			if (methodID)
			{
				result = (int)pEnv->CallObjectMethod(m_jH5PayObject, methodID);
			}
		}
		CCLog("ret=%d", result);
		return (ErrorValue)result;
	}	

	bool H5Pay::Init()
	{
		bool result = false;
		JNIEnv *pEnv = 0;
		bool ret = getEnv(&pEnv);
		if (ret && pEnv)
		{
			jmethodID methodID = 0;
			m_jH5PayClass = pEnv->FindClass("com/alipay/sdk/pay/H5Pay");
			methodID = pEnv->GetMethodID(m_jH5PayClass, "<init>", "()V");
			if (m_jH5PayClass && methodID)
			{
				m_jH5PayObject = pEnv->NewObject(m_jH5PayClass, methodID);
				result = true;
			}
		}
		return result;
	}



};



