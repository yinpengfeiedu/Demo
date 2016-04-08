#import "Pay.h"
#import "Alipay.h"


namespace PaySdk
{
    Pay *Pay::mPay = NULL;
    
    Pay *Pay::GetInstance()
    {
        if (mPay == NULL)
        {
            mPay = new Pay();
        }
        return mPay;
    }

	void Pay::SetPartner(std::string pID)
	{
        NSString *nstring = [NSString stringWithCString:pID.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setPid : nstring];
	}

	std::string Pay::getPartner()
	{
        NSString *nstring = [[Alipay defaultPay] getPid];
        std::string str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
		return str;
	}

	void Pay::SetSeller(std::string accountNo)
	{
        NSString *nstring = [NSString stringWithCString:accountNo.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setAccountNo: nstring];
	}

	std::string Pay::getSeller()
	{
        NSString *nstring = [[Alipay defaultPay] getAccountNo];
        std::string str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
		return str;
	}

	void Pay::SetRsaPrivate(std::string priKey)
	{
        NSString *nstring = [NSString stringWithCString:priKey.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setPrivateKey: nstring];
	}

	std::string Pay::getRsaPrivate()
	{
        NSString *nstring = [[Alipay defaultPay] getPrivateKey];
        std::string str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
		return str;
	}

	void Pay::SetRsaPublic(std::string pubKey)
	{
        NSString *nstring = [NSString stringWithCString:pubKey.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setPublicKey: nstring];
	}

	std::string Pay::getRsaPublic()
	{
        NSString *nstring = [[Alipay defaultPay] getPublicKey];
        std::string str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
		return str;
	}

	void Pay::setOrderInfo(std::string order)
	{
        NSString *nstring = [NSString stringWithCString:order.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setOrder: nstring];
	}

	std::string Pay::getOrderInfo()
	{
        NSString *nstring = [[Alipay defaultPay] getOrder];
        std::string str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
		return str;
	}

	void Pay::setSignValue(std::string sign)
	{
        NSString *nstring = [NSString stringWithCString:sign.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setSignValue: nstring];
	}

	std::string Pay::getSignValue()
	{
        NSString *nstring = [[Alipay defaultPay] getSignValue];
        std::string str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
		return str;
	}

	void Pay::setSignType(std::string type)
	{
        NSString *nstring = [NSString stringWithCString:type.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setSignType: nstring];
	}

	std::string Pay::getSignType()
	{
        NSString *nstring = [[Alipay defaultPay] getSignType];
        std::string str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
		return str;
	}

	ErrorValue Pay::DoPay()
	{
        int ret = [[Alipay defaultPay] pay];
		return (ErrorValue)ret;
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





};




