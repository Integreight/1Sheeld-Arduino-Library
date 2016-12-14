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
#define FINGERPRINT_SCAN	    0x01

//Input Function ID's 
#define FINGERPRINT_GET 			0x01
#define FINGERPRINT_GET_ERROR			0x02

//Errors messages 
#define AUTHENTICATION_FAILED	0x01
#define USER_CANCEL              0x02
#define USER_FALLBACK            0x03
#define SYSTEM_CANCEL            0x04
#define PASSCODE_NOT_SET          0x05
#define TOUCHID_NOT_AVAILABLE		0x06
#define TOUCHID_NOT_ENROLLED      0x07
#define TOUCHID_LOCKOUT          0x08
#define APP_CANCEL               0x09
#define INVALID_CONTEXT          0x0A


class FingerprintScannerShield : public ShieldParent
{
public:
	//Constructor 
	FingerprintScannerShield();
	bool isVerified();
	bool isNewFingerScanned();
	void scan();
	void setOnError(void (*)(byte));
	void setOnNewFingerScanned(void (*)(bool));

private:
	bool isFingerVerified;
	bool isNewFingerprintScanned;
	bool isErrorCallbackAssigned;
	bool isFingerprintCallbackAssigned;
	void (*errorCallback)(byte);
	void (*fingerprintCallback)(bool);
	void processData();
};
//Extern Object
extern FingerprintScannerShield FingerprintScanner;
#endif