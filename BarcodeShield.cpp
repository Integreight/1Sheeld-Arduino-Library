/*

  Project:       1Sheeld Library 
  File:          BarcodeShield.cpp
                 
  Version:       1.9.3

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.10

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "BarcodeShield.h"


//Constructor 
BarcodeShield::BarcodeShield() : ShieldParent(BARCODE_ID)
{
	isNewBarcode= false;
	is1DCallbackAssigned= false;
	is2DCallbackAssigned= false;
	isNextDataResponseCallbackAssigned= false;
	isParameterCallbackAssigned= false;
	isErrorCallbackAssigned= false;
	barcodeDataLength= 0;
	barcodeFormat= 0;
	twoDBarcodeLength= 0;
	twoDBarcodeCategory= 0;
	errorNumber= 0;
	barcodeMaxLength= 0;
	index= 0;
	barcodeData= '\0';
}

void BarcodeShield::queryBarcodeNextBytes(byte length)
{
	OneSheeld.sendShieldFrame(BARCODE_ID,0,BARCODE_QUERY_2D_NEXT_BYTES,1,new FunctionArg(1,&length));
}

void BarcodeShield::query2DBarcodeParameterValue(const char * parameter)
{
	OneSheeld.sendShieldFrame(BARCODE_ID,0,BARCODE_QUERY_PARAMETER,1,new FunctionArg(strlen(parameter),(byte *)parameter));	
}

void BarcodeShield::enableBarcodeInterrupt()
{
	OneSheeld.sendShieldFrame(BARCODE_ID,0,BARCODE_ENABLE_INTERRUPT,0);	
}

void BarcodeShield::disableBarcodeInterrupt()
{
	OneSheeld.sendShieldFrame(BARCODE_ID,0,BARCODE_DISABLE_INTERRUPT,0);	
}

char * BarcodeShield::getBarcodeData()
{
	isNewBarcode=false;
	return barcodeData;
}

int BarcodeShield::getBarcodeMaxDataLength()
{
	return barcodeMaxLength;
} 

bool BarcodeShield::isNewBarcodeScanned()
{
	return isNewBarcode;
}

bool BarcodeShield::isFullySent()
{
	return (index>=barcodeMaxLength);
}

byte BarcodeShield::get2DBarcodeCategory()
{
	isNewBarcode=false;
	return twoDBarcodeCategory;
}

byte BarcodeShield::getBarcodeFormat()
{
	isNewBarcode=false;
	return barcodeFormat;
}

//Process Input Data
void BarcodeShield::processData()
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
			if(is1DCallbackAssigned)
			{
				enteringACallback();
				(*OneDBarcodeCallback)(barcodeFormat,barcodeMaxLength,barcodeData);
				exitingACallback();
			}
		}

	}
	else if(functionID==BARCODE_GET_2D)
	{
		isNewBarcode = true;
		barcodeFormat = getOneSheeldInstance().getArgumentData(0)[0];
		twoDBarcodeCategory = getOneSheeldInstance().getArgumentData(1)[0];
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
			if(is2DCallbackAssigned)
			{
				enteringACallback();
				(*twoDBarcodeCallback)(barcodeFormat,twoDBarcodeCategory,barcodeMaxLength,barcodeData);
				exitingACallback();
			}
		}
	}
	else if(functionID==BARCODE_GET_NEXT && !isInACallback())
	{
		byte dataLength = getOneSheeldInstance().getArgumentLength(0);
		index+=dataLength;
		char data[dataLength+1];
		
		for (int j=0; j<dataLength; j++)
		{
			data[j]=getOneSheeldInstance().getArgumentData(0)[j];
		}
		data[dataLength]='\0';
		//Invoke User Function
		if(isNextDataResponseCallbackAssigned)
		{
			enteringACallback();
			(*nextDataResponseCallback)(dataLength,data);
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
void BarcodeShield::on1DBarcodeScanned(void (*userFunction)(byte ,int ,char* ))
{
	OneDBarcodeCallback=userFunction;
	is1DCallbackAssigned=true;
}

void BarcodeShield::on2DBarcodeScanned(void (*userFunction)(byte , byte , int ,char*))
{
	twoDBarcodeCallback=userFunction;
	is2DCallbackAssigned=true;
}

void BarcodeShield::onNextDataResponse(void (*userFunction)(byte, char *))
{
	nextDataResponseCallback=userFunction;
	isNextDataResponseCallbackAssigned=true;
}

void BarcodeShield::onParameterValueResponse(void (*userFunction)(char * , char *))
{
	parameterValueCallback=userFunction;
	isParameterCallbackAssigned=true;
}

void BarcodeShield::onCodeError(void (*userFunction)(byte))
{
	errorCallback=userFunction;
	isErrorCallbackAssigned=true;
}

