#ifndef __H5Pay_H__
#define __H5Pay_H__

#include "DataStruct.h"

namespace PaySdk{

	class H5Pay
	{
	public:
		H5Pay(){}
        
		~H5Pay(){}
	public:
        static H5Pay *GetInstance();
        
		void SetUrl(std::string url);
        
		std::string GetUrl();
        
		ErrorValue DoH5Pay();
        
    private:
        static H5Pay *mH5Pay;
	};


}

#endif // !__PayResult_H__
