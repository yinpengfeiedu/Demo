
#include "FirstViewController.h"
#include "PaySdk.h"
#include "H5Pay.h"
#include "umSDK.h"


using namespace PaySdk;

FirstViewController::FirstViewController()
{

}

FirstViewController::~FirstViewController()
{
	
}

void FirstViewController::viewDidLoad()
{
	DRect winRect = this->getView()->getBounds();

	CALabel* label = CALabel::createWithCenter(winRect);
	CAButton *pPayButton = CAButton::createWithFrame(DRect(50,50,200,200),CAButtonTypeCustom);
	pPayButton->setTitleForState(CAControlStateAll,"Pay");
	this->getView()->addSubview(pPayButton);
	pPayButton->addTarget(this,SEL_CAControl(&FirstViewController::OnClickPayBtn),CAControlEventTouchUpInSide);

	CAButton *pH5PayButton = CAButton::createWithFrame(DRect(350, 50, 300, 200), CAButtonTypeCustom);
	pH5PayButton->setTitleForState(CAControlStateAll, "H5Pay");
	this->getView()->addSubview(pH5PayButton);
	pH5PayButton->addTarget(this, SEL_CAControl(&FirstViewController::OnClickH5PayBtn), CAControlEventTouchUpInSide);
}

void FirstViewController::viewDidUnload()
{
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

void FirstViewController::OnClickPayBtn(CAControl *pControl, DPoint pt)
{
	CCLog("starting pay......");
	Pay::SetPartner("abcdefg123456");
	Pay::SetRsaPrivate("abcdefg");
	Pay::SetSeller("1234567890");
	Pay::setOrderInfo("ddd");
	CCLog("parnter:%s----rsaprivate:%s----seller:%s----order:%s",
		Pay::getPartner().c_str(), Pay::getRsaPrivate().c_str(), Pay::getSeller().c_str(), Pay::getOrderInfo().c_str());
	int ret = Pay::DoPay();
	CCLog("end pay......");

	if (ret == 10000)
	{
		CCLog("calling pay of paySdk is successful!");
	}
	else if (ret == 0)
	{
		CCLog("No Pid , AccouontNo or RsaKey!");
	}
	else if (ret == 1)
	{
		CCLog("No url!");
	}
	else
	{
		CCLog("Unknow error!");
	}
}

void FirstViewController::OnClickH5PayBtn(CAControl *pControl, DPoint pt)
{
	CCLog("starting h5pay......");
	H5Pay::SetUrl("www.baidu.com");
	CCLog("url:%s",H5Pay::GetUrl().c_str());
	int ret = H5Pay::DoH5Pay();
	CCLog("end h5pay......");

	if (ret == 10000)
	{
		CCLog("calling pay of paySdk is successful!");
	}
	else if (ret == 0)
	{
		CCLog("No Pid , AccouontNo or RsaKey!");
	}
	else if (ret == 1)
	{
		CCLog("No url!");
	}
	else
	{
		CCLog("Unknow error!");
	}
}
