#import "H5Pay.h"
#import "Alipay.h"

namespace PaySdk
{

    H5Pay *H5Pay::mH5Pay = NULL;
    
	H5Pay *H5Pay::GetInstance()
	{
        if (mH5Pay == NULL)
        {
            mH5Pay = new H5Pay();
        }
        return mH5Pay;
    }

	void H5Pay::SetUrl(std::string url)
	{		
        NSString *nstring = [NSString stringWithCString:url.c_str() encoding:[NSString defaultCStringEncoding]];
        [[Alipay defaultPay] setUrl : nstring];
	}

	std::string H5Pay::GetUrl()
	{
        NSString *nstring = [[Alipay defaultPay] getUrl];
        std::string str = [nstring cStringUsingEncoding:[NSString defaultCStringEncoding]];
        return str;
	}

	ErrorValue H5Pay::DoH5Pay()
	{
		int result = 0;
		result = [[Alipay defaultPay] doH5Pay];
		return (ErrorValue)result;
	}



};


