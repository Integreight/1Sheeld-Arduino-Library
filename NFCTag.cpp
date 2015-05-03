/*

  Project:       1Sheeld Library 
  File:          NFCTag.cpp
                 
  Version:       1.5

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.3

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "NFCTag.h"


NFCRecord NFCTag::nullRecord;

NFCTag::NFCTag(byte * _tagId,byte tagIdLength, int _tagSize, int _tagMaxSize, byte _recordsNumber)
{
	isTypeCallBackAssigned= false;
	isDataCallBackAssigned= false;
	isParsedDataCallBackAssigned= false;
	tagId=NULL;
	if(tagIdLength!=0)
	{
		tagId = (byte *) malloc(sizeof(byte)*(tagIdLength));
		memcpy(tagId,_tagId,tagIdLength);
	}

	tagSize =_tagSize;
	tagMaxSize =_tagMaxSize;
 	recordsNumber =_recordsNumber;
 	if(recordsNumber>0)
	{
		recordsArray = (NFCRecord **) malloc(sizeof(NFCRecord*)*recordsNumber);
		for (int i = 0; i < recordsNumber; i++)
		{
			recordsArray[i]=new NFCRecord(i);
		}
	}
}

NFCTag::NFCTag()
{
	isTypeCallBackAssigned= false;
	isDataCallBackAssigned= false;
	isParsedDataCallBackAssigned= false;
	tagId=NULL;
	tagSize=0;
	tagMaxSize=0;
	recordsNumber=0;
	recordsArray=NULL;
}

NFCRecord & NFCTag::getRecord(int index)
{
	if(index>=recordsNumber)return NFCTag::nullRecord;
	return *(recordsArray[index]);
}

int NFCTag::getSize()
{
	return tagSize;
}

int NFCTag::getMaxSize()
{
	return tagMaxSize;
}

byte NFCTag::getNumberOfRecords()
{
	return recordsNumber;
}

bool NFCTag::isEmpty()
{
	return !recordsNumber;
}
byte NFCTag::getIdLength()
{
	return tagIdLength;
}
byte * NFCTag::getId()
{
	return tagId;
}


void NFCTag::setOnRecordTypeResponse(void (*userFunction)(byte id, byte data[], byte typeLength))
{
	isTypeCallBackAssigned =true;
	recordTypeCallBack = userFunction;
}

void NFCTag::setOnRecordParsedDataResponse(void (*userFunction)(byte id, char data[]))
{
	isParsedDataCallBackAssigned =true;
	recordParsedCallBack = userFunction;
}

void NFCTag::setOnRecordDataResponse(void (userFunction)(byte id,byte data [], byte dataLength))
{
	isDataCallBackAssigned =true;
	recordDataCallBack = userFunction;
}

bool NFCTag::isNull()
{
	return tagMaxSize==0;
}

NFCTag::~NFCTag()
{
	if(recordsNumber>0&&recordsArray!=NULL)
	{
		for(int i=0;i<recordsNumber;i++)
			delete recordsArray[i];
		free (recordsArray);
	}
	if(tagId!=NULL)free (tagId);
}