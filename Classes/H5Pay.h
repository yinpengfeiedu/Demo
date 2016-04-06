#ifndef __H5Pay_H__
#define __H5Pay_H__


#include "platform/android/jni/JniHelper.h"
#include "CrossApp.h"
#include "DataStruct.h"

namespace PaySdk{

	class H5Pay
	{
	public:
		H5Pay(){}
		~H5Pay(){}
	public:
		bool Init();
		void SetUrl(std::string url);
		std::string GetUrl();
		ErrorValue DoH5Pay();
	private:
		jclass j_mClass;
		jobject j_mObj;
	};


}

#endif // !__PayResult_H__
