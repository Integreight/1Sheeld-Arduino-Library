/*

  Project:       1Sheeld Library 
  File:          ShieldParent.cpp
                 
  Version:       1.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"

OneSheeldClass * ShieldParent::oneSheeldInstance=NULL;
bool ShieldParent::oneSheeldInstanceAvailable=false;

ShieldParent::ShieldParent(byte shieldNo)
{
	shieldID = shieldNo ;
	isCallBackSet=false;
	OneSheeldClass::addToShieldsArray(this);
}

void ShieldParent::select()
{
	OneSheeld.sendShieldFrame(shieldID,0x00,SELECT_SHIELD,0x00);
}

void ShieldParent::deselect()
{
	OneSheeld.sendShieldFrame(shieldID,0x00,DESELECT_SHIELD,0x00);
}

void ShieldParent::setOnSelected(void (*userFunction)(void))
{
	OneSheeld.sendShieldFrame(shieldID,0x00,QUERY_SELECTED,0x00);
	isCallBackSet=true;
	selectedCallBack=userFunction;
}

byte ShieldParent::getShieldId()
{
	return shieldID;
}

void ShieldParent::enteringACallback()
{
  OneSheeld.enteringACallback();
}

void ShieldParent::exitingACallback()
{
  OneSheeld.exitingACallback();
}

bool ShieldParent::isInACallback()
{
  return OneSheeld.isInACallback();
}

void ShieldParent::setOneSheeldInstance(OneSheeldClass & instance)
{
	oneSheeldInstance=&instance;
	oneSheeldInstanceAvailable=true;
}

void ShieldParent::unSetOneSheeldInstance()
{
	oneSheeldInstance=NULL;
	oneSheeldInstanceAvailable=false;
}

OneSheeldClass & ShieldParent::getOneSheeldInstance()
{
	if(oneSheeldInstanceAvailable)return *oneSheeldInstance;
	else return OneSheeld;
}

void ShieldParent::processFrame()
{
	if(shieldID!=getOneSheeldInstance().getShieldId())return;
	byte functionID = getOneSheeldInstance().getFunctionId();

	if(functionID == CHECK_SELECTED)
	{
		if(isCallBackSet && !isInACallback())
		{
				enteringACallback();
				(*selectedCallBack)();
				exitingACallback();
		}
	}
	else processData();
}