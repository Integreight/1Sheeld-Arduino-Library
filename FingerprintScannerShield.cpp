/*

  Project:       1Sheeld Library 
  File:          FingerprintScannerShield.cpp
                 
  Version:       1.9.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.11

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "FingerprintScannerShield.h"


//Constructor 
FingerprintScannerShield::FingerprintScannerShield() : ShieldParent(FINGERPRINT_ID)
{
	isNewFingerprintScanned= false;
	isErrorCallbackAssigned= false;
	lastVerified = true;
}

void FingerprintScannerShield::start()
{
	OneSheeld.sendShieldFrame(FINGERPRINT_ID,0,FINGERPRINT_START,0);
}


bool FingerprintScannerShield::isVerified()
{
	if(!lastVerified)
	{
		lastVerified = true;
		return isNewFingerprintScanned;

	}else
	{
		isNewFingerprintScanned = false;
		return isNewFingerprintScanned;
	}
}

//Process Input Data
void FingerprintScannerShield::processData()
{
	byte functionID = getOneSheeldInstance().getFunctionId();

	if(functionID==FINGERPRINT_GET)
	{
		isNewFingerprintScanned = true;
		lastVerified = false;
	}
	else if(functionID==FINGERPRINT_GET_ERROR && !isInACallback())
	{
		byte errorNumber=getOneSheeldInstance().getArgumentData(0)[0];
		//Invoke User Function
		if(isErrorCallbackAssigned)
		{
			enteringACallback();
			(*errorCallback)(errorNumber);
			exitingACallback();
		}
	}
}

void FingerprintScannerShield::setOnError(void (*userFunction)(byte))
{
	errorCallback=userFunction;
	isErrorCallbackAssigned=true;
}

