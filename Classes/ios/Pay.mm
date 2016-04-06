#include "Pay.h"
#include "Alipay.h"

namespace PaySdk
{

	void Pay::SetPartner(std::string pID)
	{
		[Alipay defaultPay] setPartner(NSString StringwithString(pID));
	}

	std::string Pay::getPartner()
	{
		std::string str = [[NSString cStringUTF] [Alipay defaultPay] getPartner()];
		return str;
	}

	void Pay::SetSeller(std::string accountNo)
	{
		[Alipay defaultPay] setPartner(NSString StringwithString(pID));
	}

	std::string Pay::getSeller()
	{
		std::string str = [[NSString cStringUTF][Alipay defaultPay] getPartner()];
		return str;
	}

	void Pay::SetRsaPrivate(std::string priKey)
	{
		[Alipay defaultPay] setPartner(NSString StringwithString(pID));
	}

	std::string Pay::getRsaPrivate()
	{
		std::string str = [[NSString cStringUTF][Alipay defaultPay] getPartner()];
		return str;
	}

	void Pay::SetRsaPublic(std::string pubKey)
	{
		[Alipay defaultPay] setPartner(NSString StringwithString(pID));
	}

	std::string Pay::getRsaPublic()
	{
		std::string str = [[NSString cStringUTF][Alipay defaultPay] getPartner()];
		return str;
	}

	void Pay::setOrderInfo(std::string order)
	{
		[Alipay defaultPay] setPartner(NSString StringwithString(pID));
	}

	std::string Pay::getOrderInfo()
	{
		std::string str = [[NSString cStringUTF][Alipay defaultPay] getPartner()];
		return str;
	}

	void Pay::setSignValue(std::string sign)
	{
		[Alipay defaultPay] setPartner(NSString StringwithString(pID));
	}

	std::string Pay::getSignValue()
	{
		std::string str = [[NSString cStringUTF][Alipay defaultPay] getPartner()];
		return str;
	}

	void Pay::setSignType(std::string type)
	{
		[Alipay defaultPay] setPartner(NSString StringwithString(pID));
	}

	std::string Pay::getSignType()
	{
		std::string str = [[NSString cStringUTF][Alipay defaultPay] getPartner()];
		return str;
	}

	ErrorValue Pay::DoPay()
	{
		[Alipay defaultPay] setPartner(NSString StringwithString(pID));
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


}