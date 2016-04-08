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
		// 签约合作者身份ID
		std::string orderInfo = "partner=\"abcdefg\"";

		// 签约卖家支付宝账号
		orderInfo += "&seller_id=\"1234567890\"";

		// 商户网站唯一订单号
		orderInfo += "&out_trade_no=\"201603231441630\"";

		// 商品名称
		orderInfo += "&subject=";
		orderInfo += name;

		// 商品详情
		orderInfo += "&body=";
		orderInfo += description;

		// 商品金额
		orderInfo += "&total_fee=";
		orderInfo += price;

		// 服务器异步通知页面路径
		orderInfo += "&notify_url=\"http://notify.msp.hk/notify.htm\"";

		// 服务接口名称， 固定值
		orderInfo += "&service=\"mobile.securitypay.pay\"";

		// 支付类型， 固定值
		orderInfo += "&payment_type=\"1\"";

		// 参数编码， 固定值
		orderInfo += "&_input_charset=\"utf-8\"";

		// 设置未付款交易的超时时间
		// 默认30分钟，一旦超时，该笔交易就会自动被关闭。
		// 取值范围：1m～15d。
		// m-分钟，h-小时，d-天，1c-当天（无论交易何时创建，都在0点关闭）。
		// 该参数数值不接受小数点，如1.5h，可转换为90m。
		orderInfo += "&it_b_pay=\"30m\"";

		// extern_token为经过快登授权获取到的alipay_open_id,带上此参数用户将使用授权的账户进行支付
		// orderInfo += "&extern_token=" + "\"" + extern_token + "\"";

		// 支付宝处理完请求后，当前页面跳转到商户指定页面的路径，可空
		orderInfo += "&return_url=\"m.alipay.com\"";

		// 调用银行卡支付，需配置此参数，参与签名， 固定值 （需要签约《无线银行卡快捷支付》才能使用）
		// orderInfo += "&paymethod=\"expressGateway\"";

		return orderInfo;
	}





};




