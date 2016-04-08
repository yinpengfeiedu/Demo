
#include "FirstViewController.h"
#include "umSDK.h"
#include "PaySdk.h"
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
	CAButton *pPayButton = CAButton::createWithFrame(DRect(50,50,150,150),CAButtonTypeCustom);
	pPayButton->setTitleForState(CAControlStateAll,"pay");
	this->getView()->addSubview(pPayButton);
	pPayButton->addTarget(this,SEL_CAControl(&FirstViewController::OnClickPayBtn),CAControlEventTouchUpInSide);

    
    Pay *pay = Pay::GetInstance();
    if (pay)
    {
        pay->SetPartner("1234567890");
        CCLog("parnter:%s",pay->getPartner().c_str());
    }
   
	int ret = 0;
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

void FirstViewController::viewDidUnload()
{
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

void FirstViewController::OnClickPayBtn(CAControl *pControl, DPoint pt)
{
	CCLog("aaaaaaaaaaaaaaaaaaaa");

	int ret = 0;
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
