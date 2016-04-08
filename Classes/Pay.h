#ifndef __Pay_H__
#define __Pay_H__

#include "DataStruct.h"

namespace PaySdk{
	
	class Pay
	{
	public:
		Pay(){}
		~Pay(){}
	public:
        static Pay *GetInstance();
        
		void SetPartner(std::string pID);

		std::string getPartner();

		void SetSeller(std::string accountNo);

		std::string getSeller();

		void SetRsaPrivate(std::string priKey);

		std::string getRsaPrivate();

		void SetRsaPublic(std::string pubKey);

		std::string getRsaPublic();

		void setOrderInfo(std::string order);

		std::string getOrderInfo();

		void setSignValue(std::string sign);

		std::string getSignValue();

		void setSignType(std::string type);

		std::string getSignType();

		ErrorValue DoPay();

		std::string GetSampleOrderInfo(std::string name, std::string description, std::string price);
        
    private:
        static Pay *mPay;

	};



}

#endif // !__Pay_H__
