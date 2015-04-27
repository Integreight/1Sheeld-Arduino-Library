/*

  Project:       1Sheeld Library 
  File:          NFCRecord.h
                 
  Version:       1.5

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.3

*/

#ifndef NFCRecord_h
#define NFCRecord_h

//Output Function ID
#define NFC_RECORD_QUERY_DATA 0x01
#define NFC_RECORD_QUERY_TYPE 0x02
#define NFC_RECORD_QUERY_PARSED_DATA 0x03

//Literals
#define TNF_UNKNOWN				0x00
#define TNF_EMPTY				0x01
#define TNF_EXTERNAL_TYPE		0x02
#define TNF_MIME_MEDIA			0x03
#define TNF_UNCHANGED			0x04
#define TNF_ABSOLUTE_URI		0x05
#define RTD_TEXT				0x06
#define RTD_URI					0x07
#define RTD_UNSUPPORTED			0x08

class NFCRecord
{
public:
	NFCRecord(byte );
	NFCRecord();
	byte getTypeCategory();
	int getTypeLength();
	int getDataLength();
	void queryData(int=0 ,byte=64);
	void queryType(int=0 ,byte=64);
	void queryParsedData();
	bool isNull();
private:
	bool isRecordNull;
	byte recordType;
	int recordTypeLength;
	int recordDataLength;
	byte recordNumber;
friend class NFCShield;
};

#endif