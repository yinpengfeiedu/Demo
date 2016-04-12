#ifndef __H5Pay_H__
#define __H5Pay_H__

#include "DataStruct.h"

namespace PaySdk{

	class H5Pay
	{
	private:
		H5Pay(){}        
		~H5Pay(){}
	public:
        
		static void SetUrl(std::string url);
        
		static std::string GetUrl();
        
		static ErrorValue DoH5Pay();
        
    private:
	};


}

#endif // !__PayResult_H__
