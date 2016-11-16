/*

  Project:       1Sheeld Library 
  File:          FingerprintScannerShield.h
                 
  Version:       1.9.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.11

*/
#ifndef	FingerprintScannerShield_h
#define FingerprintScannerShield_h

#include "ShieldParent.h"

//Output  function ID's
#define FINGERPRINT_START	    0x01

//Input Function ID's 
#define FINGERPRINT_GET 			0x01
#define FINGERPRINT_GET_ERROR			0x02

//Errors messages 
#define AUTHENTICATIONFAILED	0x01
#define USERCANCEL              0x02
#define USERFALLBACK            0x03
#define SYSTEMCANCEL            0x04
#define PASSCODENOTSET          0x05
#define TOUCHIDNOTAVAILABLE		0x06
#define TOUCHIDNOTENROLLED      0x07
#define TOUCHIDLOCKOUT          0x08
#define APPCANCEL               0x09
#define INVALIDCONTEXT          0x0A


class FingerprintScannerShield : public ShieldParent
{
public:
	//Constructor 
	FingerprintScannerShield();
	bool isVerified();
	void start();
	void setOnError(void (*)(byte));

private:
	bool isNewFingerprintScanned;
	bool isErrorCallbackAssigned;
	bool lastVerified;
	void (*errorCallback)(byte);
	void processData();
};
//Extern Object
extern FingerprintScannerShield FingerprintScanner;
#endif