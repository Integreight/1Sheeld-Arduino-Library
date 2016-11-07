/*

  Project:       1Sheeld Library 
  File:          BarcodeScannnerShield.h
                 
  Version:       1.9.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.10

*/
#ifndef	BarcodeScannerShield_h
#define BarcodeScannerShield_h

#include "ShieldParent.h"

//Output  function ID's
#define BARCODE_QUERY_PARAMETER	    0x01
#define BARCODE_QUERY_NEXT_BYTES	0x02

//Input Function ID's 
#define BARCODE_GET_1D 				0x01
#define BARCODE_GET_2D			    0x02
#define BARCODE_GET_NEXT			0x03
#define BARCODE_GET_PARAMETER		0x04
#define BARCODE_GET_ERROR			0x05

//Errors messages 
#define BARCODE_NOT_SUPPORTED	0x01
#define BARCODE_SCANNING_ERROR 	0x02
#define WRONG_PARAMETER			0x03
#define NOT_ENOUGH_BYTES		0x04
#define CATEGORY_NOT_SUPPORTED	0x05

//Barcode_Formats
#define UPC_A		0x01
#define UPC_E		0x02
#define EAN8		0x03
#define EAN13		0x04
#define CODE39  	0x05
#define CODE93		0x06
#define CODE128		0x07
#define PDF417		0x08
#define QRCODE  	0x09
#define AZTEC		0x0A
#define ITF			0x0B
#define ITF14		0x0C
#define DATA_MATRIX	0x0D 

//2D Barcode Categories
#define NO_CATEGORY	 0x00
#define CODE_URL	 0x01
#define CODE_TXT	 0x02
#define CODE_EMAIL	 0x03
#define CODE_VCARD	 0x04
#define CODE_SMS 	 0x05
#define CODE_CALL 	 0x06
#define CODE_GEO 	 0x07
#define CODE_WIFI	 0x08
#define CODE_EVENT	 0x09


class BarcodeScannerShield : public ShieldParent
{
public:
	//Constructor 
	BarcodeScannerShield();
	bool isNewBarcodeScanned();
	bool isFullySent();
	bool isNextDataBytesReceived();
	byte getFormat();
	byte getCategory();
	byte getDataLength();
	int getMaxDataLength();
	char * getData();
	void queryNextDataBytes(byte=128);
	void queryParameterValue(const char *);
	void setOnNewBarcodeScanned(void (*)(byte , byte , int ,char*));
	void setOnNextDataResponse(void (*)(byte, char *));
	void setOnParameterValueResponse(void (*)(char * , char *));
	void setOnError(void (*)(byte));

private:
	bool isNewBarcode;
	bool isCallbackAssigned;
	bool isNextDataResponseCallbackAssigned;
	bool isParameterCallbackAssigned;
	bool isErrorCallbackAssigned;
	bool isNext;
	byte barcodeDataLength;
	byte barcodeFormat;
	byte barcodeCategory;
	byte errorNumber;
	int  barcodeMaxLength;
	int  index;
	char * barcodeData;

	void (*barcodeCallback)(byte ,byte,int,char*);
	void (*nextDataResponseCallback)(byte,char*);
	void (*parameterValueCallback)(char*,char*);
	void (*errorCallback)(byte);
	void processData();
};
//Extern Object
extern BarcodeScannerShield BarcodeScanner;
#endif