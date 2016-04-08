#ifndef __PayResult_H__
#define __PayResult_H__

#include "DataStruct.h"

namespace PaySdk{

	class PayResult
	{
	public:
		PayResult(){}
		~PayResult(){}
	public:
		PayResult(std::string rawResult);
		std::string GetResultStatus();
		std::string GetMemo();
		std::string GetResult();
	};



}

#endif // !__PayResult_H__
