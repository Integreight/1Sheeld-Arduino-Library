/*

  Project:       1Sheeld Library 
  File:          NFCShield.cpp
                 
  Version:       1.5

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.3

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "NFCShield.h"

NFCTag NFCShield::nullTag;
NFCShield::NFCShield():ShieldParent(NFC_ID)
{
	isErrorAssigned =false;
	isNewTag =false;
	isNewTagSetOnAssigned =false;
	isReadingInProgress=false;
	isTagInterruptsEnabled=false;
	tag=NULL;
}

NFCTag & NFCShield::getLastTag()
{
	isNewTag=false;
	isReadingInProgress=true;
	if(tag!=NULL)return *tag;
	return NFCShield::nullTag;
}

bool NFCShield::isNewTagScanned()
{
	return isNewTag;
}

void NFCShield::finishedReading()
{
	isReadingInProgress=false;
}

void NFCShield::enableTagInterrupts()
{
	isTagInterruptsEnabled=true;
}

void NFCShield::disableTagInterrupts()
{
	isTagInterruptsEnabled=false;
}

void NFCShield::setOnNewTagScanned(void (*userFunction)(NFCTag &))
{
	isNewTagSetOnAssigned =true;
	newTagCallBack = userFunction;
}

void NFCShield::setOnError(void (*userFunction)(byte errorNumber))
{
	isErrorAssigned =true;
	errorCallBack = userFunction;
}

void NFCShield::processData()
{
	byte functionId = getOneSheeldInstance().getFunctionId();

	if(functionId == NFC_GET_BASIC_INFO && (!isTagInterruptsEnabled || (!isReadingInProgress && isTagInterruptsEnabled)))
	{
		isNewTag = true;

		int tagIdLength = getOneSheeldInstance().getArgumentLength(0);
		byte tagId[tagIdLength];

		if(tagIdLength!=0)
		{
			for (int i = 0; i < tagIdLength; i++)
			{
				tagId[i] = getOneSheeldInstance().getArgumentData(0)[i];
			}
		}
		
		int tagMaxSize = getOneSheeldInstance().getArgumentData(1)[0]|((getOneSheeldInstance().getArgumentData(1)[1])<<8);

		byte recordsNumber = getOneSheeldInstance().getArgumentData(2)[0];

		int tagSize = getOneSheeldInstance().getArgumentData(3)[0]|((getOneSheeldInstance().getArgumentData(3)[1])<<8);

		if(tag!=NULL){delete tag;tag=NULL;}
		tag=new NFCTag(tagId,tagIdLength,tagSize,tagMaxSize,recordsNumber);

		tag->tagIdLength= tagIdLength;
		if(tag->recordsNumber>0)
		{
			byte argumentNo = getOneSheeldInstance().getArgumentNo();
			for(int i=4 ;i<argumentNo; i++)
			{
				tag->getRecord(i-4).recordType = getOneSheeldInstance().getArgumentData(i)[0];
				tag->getRecord(i-4).recordTypeLength = getOneSheeldInstance().getArgumentData(i)[1]|(getOneSheeldInstance().getArgumentData(i)[2]<<8);
				tag->getRecord(i-4).recordDataLength = getOneSheeldInstance().getArgumentData(i)[3]|(getOneSheeldInstance().getArgumentData(i)[4]<<8);
			}		
		}

		if(isNewTagSetOnAssigned && !isInACallback())
		{
			enteringACallback();
			(newTagCallBack)(*tag);
			exitingACallback();
		}		
	}
	else if(functionId == NFC_ON_ERROR)
	{
		if(isErrorAssigned && !isInACallback())
		{
			byte errorNumber = getOneSheeldInstance().getArgumentData(0)[0];
			enteringACallback();
			(errorCallBack)(errorNumber);
			exitingACallback();
		}
	}
	else if(functionId == NFC_TAG_ON_PARSED )
	{
		if(tag != NULL && tag->isParsedDataCallBackAssigned && !isInACallback())
		{
			byte recordNumber = getOneSheeldInstance().getArgumentData(0)[0];

			byte parsedDataLength = getOneSheeldInstance().getArgumentLength(1);
			
			char incomingData[parsedDataLength+1];

			for (int i = 0; i < parsedDataLength; i++)
			{
				incomingData[i] = getOneSheeldInstance().getArgumentData(1)[i];
			}
			incomingData[parsedDataLength]='\0';

			enteringACallback();
			tag->recordParsedCallBack(recordNumber,incomingData);
			exitingACallback();
		}
	}
	else if(functionId == NFC_TAG_ON_TYPE)
	{
		if(tag != NULL && tag->isTypeCallBackAssigned && !isInACallback())
		{
			byte recordNumber = getOneSheeldInstance().getArgumentData(0)[0];

			byte typeDataLength = getOneSheeldInstance().getArgumentLength(1);
			byte incomingType[typeDataLength];

			for (int i = 0; i < typeDataLength; i++)
			{
				incomingType[i] = getOneSheeldInstance().getArgumentData(1)[i];
			}

			enteringACallback();
			tag->recordTypeCallBack(recordNumber,incomingType,typeDataLength);
			exitingACallback();
		}
	}
		else if(functionId == NFC_TAG_ON_DATA)
	{
		if(tag != NULL && tag->isDataCallBackAssigned && !isInACallback())
		{

			byte recordNumber = getOneSheeldInstance().getArgumentData(0)[0];

			byte dataLength = getOneSheeldInstance().getArgumentLength(1);
			byte incomingData[dataLength];

			for (int i = 0; i < dataLength; i++)
			{
				incomingData[i] = getOneSheeldInstance().getArgumentData(1)[i];
			}

			enteringACallback();
			tag->recordDataCallBack(recordNumber,incomingData,dataLength);
			exitingACallback();
		}
	}
}
