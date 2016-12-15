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
	isFingerVerified = false;
	isNewFingerprintScanned= false;
	isErrorCallbackAssigned= false;
	isFingerprintCallbackAssigned = false;
}

void FingerprintScannerShield::scan()
{
	OneSheeld.sendShieldFrame(FINGERPRINT_ID,0,FINGERPRINT_SCAN,0);
}

bool FingerprintScannerShield::isNewFingerScanned()
{
	return isNewFingerprintScanned;
}

bool FingerprintScannerShield::isVerified()
{
	isNewFingerprintScanned = false;
	return isFingerVerified;
}

//Process Input Data
void FingerprintScannerShield::processData()
{
	byte functionID = getOneSheeldInstance().getFunctionId();

	if(functionID==FINGERPRINT_GET)
	{
		isNewFingerprintScanned = true;
		isFingerVerified = getOneSheeldInstance().getArgumentData(0)[0];
		//Invoke User Function
		if(!isInACallback())
		{
			if(isFingerprintCallbackAssigned)
			{
				enteringACallback();
				(*fingerprintCallback)(isFingerVerified);
				exitingACallback();
			}
		}
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

void FingerprintScannerShield::setOnNewFingerScanned(void (*userFunction)(bool))
{
	fingerprintCallback=userFunction;
	isFingerprintCallbackAssigned=true;
}
