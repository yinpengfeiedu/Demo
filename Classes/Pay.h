#ifndef __Pay_H__
#define __Pay_H__

#include "DataStruct.h"

namespace PaySdk{
	
	class Pay
	{
	private:
		Pay(){}
		~Pay(){}
	public:
        
		static void SetPartner(std::string pID);

		static std::string getPartner();

		static void SetSeller(std::string accountNo);

		static std::string getSeller();

		static void SetRsaPrivate(std::string priKey);

		static std::string getRsaPrivate();

		static void SetRsaPublic(std::string pubKey);

		static std::string getRsaPublic();

		static void setOrderInfo(std::string order);

		static std::string getOrderInfo();

		static void setSignValue(std::string sign);

		static std::string getSignValue();

		static void setSignType(std::string type);

		static std::string getSignType();

		static ErrorValue DoPay();

		static std::string GetSampleOrderInfo(std::string name, std::string description, std::string price);
        
    private:


	};



}

#endif // !__Pay_H__
