/*

  Project:       1Sheeld Library 
  File:          NFCRecord.cpp
                 
  Version:       1.5

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.3

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "NFCRecord.h"



NFCRecord::NFCRecord(byte _recordNumber)
{
	recordType =0;
	recordTypeLength =0;
	recordDataLength =0;
	recordNumber = _recordNumber;
	isRecordNull = false;
}

NFCRecord::NFCRecord()
{
	recordType =0;
	recordTypeLength =0;
	recordDataLength =0;
	recordNumber = 0;
	isRecordNull = true;
}

bool NFCRecord::isNull()
{
	return isRecordNull;
}

byte NFCRecord::getTypeCategory()
{
	return recordType;
}
	
int NFCRecord::getTypeLength()
{
	return recordTypeLength;
}

int NFCRecord::getDataLength()
{
	return recordDataLength;
}

void NFCRecord::queryData(int start,byte size)
{
	byte startArray[2] ;
 	startArray[1] = (start >> 8) & 0xFF;
 	startArray[0] = start & 0xFF;

 	if(!isRecordNull)
	OneSheeld.sendShieldFrame(NFC_ID,0,NFC_RECORD_QUERY_DATA,3,new FunctionArg(1,&recordNumber),
														  new FunctionArg(2,startArray),
														  new FunctionArg(1,&size));
}

void NFCRecord::queryType(int start,byte size)
{
	byte startArray[2] ;
	startArray[1] = (start >> 8) & 0xFF;
	startArray[0] = start & 0xFF;
	
 	if(!isRecordNull)  	
	OneSheeld.sendShieldFrame(NFC_ID,0,NFC_RECORD_QUERY_TYPE,3,new FunctionArg(1,&recordNumber),
														  new FunctionArg(2,startArray),
														  new FunctionArg(1,&size));

}

void NFCRecord::queryParsedData()
{ 	
	if(!isRecordNull)
	OneSheeld.sendShieldFrame(NFC_ID,0,NFC_RECORD_QUERY_PARSED_DATA,1,new FunctionArg(1,&recordNumber));
}