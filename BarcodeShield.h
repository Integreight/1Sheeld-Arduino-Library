/*

  Project:       1Sheeld Library 
  File:          BarcodeShield.h
                 
  Version:       1.9.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.10

*/
#ifndef	BarcodeShield_h
#define BarcodeShield_h

#include "ShieldParent.h"

//Output  function ID's
#define BARCODE_QUERY_PARAMETER	    0x01
#define BARCODE_QUERY_2D_NEXT_BYTES	0x02
#define BARCODE_ENABLE_INTERRUPT	0x03
#define BARCODE_DISABLE_INTERRUPT	0x04

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
#define CODE_URL	 0x01
#define CODE_TXT	 0x02
#define CODE_EMAIL	 0x03
#define CODE_VCARD	 0x04
#define CODE_SMS 	 0x05
#define CODE_CALL 	 0x06
#define CODE_GEO 	 0x07
#define CODE_WIFI	 0x08
#define CODE_EVENT	 0x09


class BarcodeShield : public ShieldParent
{
public:
	//Constructor 
	BarcodeShield();
	bool isNewBarcodeScanned();
	bool isFullySent();
	byte getBarcodeFormat();
	byte get2DBarcodeCategory();
	int getBarcodeMaxDataLength();
	char * getBarcodeData();
	void queryBarcodeNextBytes(byte=64);
	void query2DBarcodeParameterValue(const char *);
	void enableBarcodeInterrupt();
	void disableBarcodeInterrupt();
	void on1DBarcodeScanned(void (*)(byte ,int ,char* ));
	void on2DBarcodeScanned(void (*)(byte , byte , int ,char*));
	void onNextDataResponse(void (*)(byte, char *));
	void onParameterValueResponse(void (*)(char * , char *));
	void onCodeError(void (*)(byte));

private:
	bool isNewBarcode;
	bool is1DCallbackAssigned;
	bool is2DCallbackAssigned;
	bool isNextDataResponseCallbackAssigned;
	bool isParameterCallbackAssigned;
	bool isErrorCallbackAssigned;
	byte barcodeDataLength;
	byte barcodeFormat;
	byte twoDBarcodeLength;
	byte twoDBarcodeCategory;
	byte errorNumber;
	int  barcodeMaxLength;
	int  index;
	char * barcodeData;

	void (*OneDBarcodeCallback)(byte,int,char *);
	void (*twoDBarcodeCallback)(byte ,byte,int,char*);
	void (*nextDataResponseCallback)(byte,char*);
	void (*parameterValueCallback)(char*,char*);
	void (*errorCallback)(byte);
	void processData();
};
//Extern Object
extern BarcodeShield Barcode;
#endif