/*

  Project:       1Sheeld Library 
  File:          NFCShield.h
                 
  Version:       1.5

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.3

*/
  
#ifndef NFCShield_h
#define NFCShield_h

// Input Function ID 
#define NFC_GET_BASIC_INFO 0x01
#define NFC_ON_ERROR	   0x02

//Error Literals 
#define INDEX_OUT_OF_BOUNDS			0x00
#define RECORD_CAN_NOT_BE_PARSED	0x01
#define TAG_NOT_SUPPORTED			0x02
#define NO_ENOUGH_BYTES				0x03
#define TAG_READING_ERROR			0x04
#define RECORD_NOT_FOUND			0x05
  
#include "ShieldParent.h"
#include "NFCTag.h"
#include "NFCRecord.h"

class NFCShield : public ShieldParent
{
public:
	NFCShield();
	NFCTag & getLastTag();
	bool isNewTagScanned();
	void finishedReading();
	void enableTagInterrupts();
	void disableTagInterrupts();
	void setOnNewTagScanned(void (*)(NFCTag &));
	void setOnError(void (*)(byte));
	
private:
	bool isErrorAssigned;
	bool isNewTag;
	bool isNewTagSetOnAssigned;
	bool isReadingInProgress;
	bool isTagInterruptsEnabled;
	NFCTag * tag;
	void processData();
	void (*errorCallBack)(byte);
	void (*newTagCallBack)(NFCTag &);
	static NFCTag nullTag;
};

//Extern Object
extern NFCShield NFC;
#endif