/*

  Project:       1Sheeld Library 
  File:          BarcodeScannerShield.cpp
                 
  Version:       1.9.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.10

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "BarcodeScannerShield.h"


//Constructor 
BarcodeScannerShield::BarcodeScannerShield() : ShieldParent(BARCODE_ID)
{
	isNewBarcode= false;
	isCallbackAssigned= false;
	isNextDataResponseCallbackAssigned= false;
	isParameterCallbackAssigned= false;
	isErrorCallbackAssigned= false;
	isNext=false;
	barcodeDataLength= 0;
	barcodeFormat= 0;
	barcodeCategory= 0;
	errorNumber= 0;
	barcodeMaxLength= 0;
	index= 0;
	barcodeData= '\0';
}

void BarcodeScannerShield::queryNextDataBytes(byte length)
{
	OneSheeld.sendShieldFrame(BARCODE_ID,0,BARCODE_QUERY_NEXT_BYTES,1,new FunctionArg(1,&length));
}

void BarcodeScannerShield::queryParameterValue(const char * parameter)
{
	OneSheeld.sendShieldFrame(BARCODE_ID,0,BARCODE_QUERY_PARAMETER,1,new FunctionArg(strlen(parameter),(byte *)parameter));	
}

char * BarcodeScannerShield::getData()
{
	isNewBarcode=false;
	isNext=false;
	return barcodeData;
}

int BarcodeScannerShield::getMaxDataLength()
{
	return barcodeMaxLength;
} 

bool BarcodeScannerShield::isNewBarcodeScanned()
{
	return isNewBarcode;
}

bool BarcodeScannerShield::isFullySent()
{
	return (index>=barcodeMaxLength);
}

bool BarcodeScannerShield::isNextDataBytesReceived()
{
	return isNext;
}

byte BarcodeScannerShield::getCategory()
{
	isNewBarcode=false;
	return barcodeCategory;
}

byte BarcodeScannerShield::getFormat()
{
	isNewBarcode=false;
	return barcodeFormat;
}

byte BarcodeScannerShield::getDataLength()
{
	return barcodeDataLength;
}

//Process Input Data
void BarcodeScannerShield::processData()
{
	byte functionID = getOneSheeldInstance().getFunctionId();

	if(functionID==BARCODE_GET_1D)
	{
		isNewBarcode = true;
		barcodeFormat = getOneSheeldInstance().getArgumentData(0)[0];
		barcodeMaxLength = getOneSheeldInstance().getArgumentData(1)[0]|((getOneSheeldInstance().getArgumentData(1)[1])<<8);

		if (barcodeData!=0)
		{
			free(barcodeData);
		}
		
		barcodeDataLength=getOneSheeldInstance().getArgumentLength(2);
		index = barcodeDataLength;
		barcodeData = (char*)malloc(sizeof(char)*(barcodeDataLength+1));
		for (int j=0; j<barcodeDataLength; j++)
		{
			barcodeData[j]=getOneSheeldInstance().getArgumentData(2)[j];
		}
		barcodeData[barcodeDataLength]='\0';
		//Invoke Users function
		if(!isInACallback())
		{
			if(isCallbackAssigned)
			{
				enteringACallback();
				(*barcodeCallback)(barcodeFormat,NO_CATEGORY,barcodeMaxLength,barcodeData);
				exitingACallback();
			}
		}

	}
	else if(functionID==BARCODE_GET_2D)
	{
		isNewBarcode = true;
		barcodeFormat = getOneSheeldInstance().getArgumentData(0)[0];
		barcodeCategory = getOneSheeldInstance().getArgumentData(1)[0];
		barcodeMaxLength = getOneSheeldInstance().getArgumentData(2)[0]|((getOneSheeldInstance().getArgumentData(2)[1])<<8);

		if (barcodeData!=0)
		{
			free(barcodeData);
		}
		
		barcodeDataLength=getOneSheeldInstance().getArgumentLength(3);
		index= barcodeDataLength;
		barcodeData = (char*)malloc(sizeof(char)*(barcodeDataLength+1));
		for (int j=0; j<barcodeDataLength; j++)
		{
			barcodeData[j]=getOneSheeldInstance().getArgumentData(3)[j];
		}
		barcodeData[barcodeDataLength]='\0';

		//Invoke Users function
		if(!isInACallback())
		{
			if(isCallbackAssigned)
			{
				enteringACallback();
				(*barcodeCallback)(barcodeFormat,barcodeCategory,barcodeMaxLength,barcodeData);
				exitingACallback();
			}
		}
	}
	else if(functionID==BARCODE_GET_NEXT && !isInACallback())
	{
		isNext= true;
		if (barcodeData!=0)
		{
			free(barcodeData);
		}
		barcodeDataLength=getOneSheeldInstance().getArgumentLength(0);
		index+=barcodeDataLength;
		barcodeData = (char*)malloc(sizeof(char)*(barcodeDataLength+1));
		for (int j=0; j<barcodeDataLength; j++)
		{
			barcodeData[j]=getOneSheeldInstance().getArgumentData(0)[j];
		}
		barcodeData[barcodeDataLength]='\0';
		//Invoke User Function
		if(isNextDataResponseCallbackAssigned)
		{
			enteringACallback();
			(*nextDataResponseCallback)(barcodeDataLength,barcodeData);
			exitingACallback();
		}
	}
	else if(functionID==BARCODE_GET_PARAMETER && !isInACallback())
	{
		byte parameterLength = getOneSheeldInstance().getArgumentLength(0);
		byte valueLength = getOneSheeldInstance().getArgumentLength(1);
		char  parameter[parameterLength+1];
		char  value[valueLength+1];
		
		for (int j=0; j<parameterLength; j++)
		{
			parameter[j]=getOneSheeldInstance().getArgumentData(0)[j];
		}
		parameter[parameterLength]='\0';
		for (int j=0; j<valueLength; j++)
		{
			value[j]=getOneSheeldInstance().getArgumentData(1)[j];
		}
		value[valueLength]='\0';
		//Invoke User Function
		if(isParameterCallbackAssigned)
		{
			enteringACallback();
			(*parameterValueCallback)(parameter,value);
			exitingACallback();
		}
	} 
	else if(functionID==BARCODE_GET_ERROR && !isInACallback())
	{
		errorNumber=getOneSheeldInstance().getArgumentData(0)[0];
		//Invoke User Function
		if(isErrorCallbackAssigned)
		{
			enteringACallback();
			(*errorCallback)(errorNumber);
			exitingACallback();
		}
	}
}
//Users Function Setter 
void BarcodeScannerShield::setOnNewBarcodeScanned(void (*userFunction)(byte , byte , int ,char*))
{
	barcodeCallback=userFunction;
	isCallbackAssigned=true;
}

void BarcodeScannerShield::setOnNextDataResponse(void (*userFunction)(byte, char *))
{
	nextDataResponseCallback=userFunction;
	isNextDataResponseCallbackAssigned=true;
}

void BarcodeScannerShield::setOnParameterValueResponse(void (*userFunction)(char * , char *))
{
	parameterValueCallback=userFunction;
	isParameterCallbackAssigned=true;
}

void BarcodeScannerShield::setOnError(void (*userFunction)(byte))
{
	errorCallback=userFunction;
	isErrorCallbackAssigned=true;
}

