/*

  Project:       1Sheeld Library 
  File:          HttpResponse.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/

#ifndef HttpResponse_h
#define HttpResponse_h
#include "JsonKeyChain.h"
//Output Function ID's for Response class
#define RESPONSE_DISPOSE					0x11
#define RESPONSE_GET_NEXT_BYTES				0x12
#define RESPONSE_GET_HEADER					0x13
//Input Function ID's for Response class
#define RESPONSE_INPUT_GET_HEADER			0x07
#define	RESPONSE_GET_ERROR					0x08
#define RESPONSE_GET_NEXT_RESPONSE			0x09
#define RESPONSE_GET_JSON					0x0A
#define RESPONSE_GET_JSON_ARRAY_LENGTH		0x0B
//Bit Setters
#define RESPONSE_INPUT_GET_HEADER_BIT		0x01
#define	RESPONSE_GET_ERROR_BIT				0x02
#define RESPONSE_GET_NEXT_RESPONSE_BIT		0x04
#define RESPONSE_GET_JSON_BIT				0x08
#define RESPONSE_GET_JSON_ARRAY_LENGTH_BIT	0x10


class HttpResponse
{
public:
	HttpResponse();
	//Checkers
	bool isSentFully();
	bool isDisposed(); 
	//Set On for userFunctions
	void setOnNextResponseBytesUpdate(void (*)(HttpResponse&));
	void setOnError(void (*)(int ));
	void setOnJsonResponse(void (*)(JsonKeyChain & ,char *));
	void setOnJsonArrayLengthResponse(void (*)(JsonKeyChain & ,unsigned long));
	JsonKeyChain operator[](int );
	JsonKeyChain operator[](const char *);
	//Setters
	void dispose(bool=true);
	void resetIndex(unsigned long= 0);
	//Getters
	void getNextBytes(int=64);
	void getTheseBytes(unsigned long ,int);
	void getHeader(const char * , void (*)(char * ,float ));
	void getHeader(const char * , void (*)(char * ,char * ));
	int getStatusCode();
	int getBytesCount();
	unsigned long getTotalBytesCount();
	unsigned long getCurrentIndex();
	char * getBytes();
	~HttpResponse();
private:
	bool isInit;
	bool isDisposedTriggered;
	int statusCode;
	unsigned long totalBytesCount;
	char * bytes;
	int bytesCount;
	int requestId;
	unsigned long index;
	byte callbacksRequested;

	void (*getNextCallBack)(HttpResponse &);
	void (*getHeaderCallBack)(char * ,char *);
	void (*getErrorCallBack)(int);
	void (*getJsonCallBack)(JsonKeyChain & , char *);
	void (*getJsonArrayLengthCallBack)(JsonKeyChain & , unsigned long);

friend class InternetShield;
friend class HttpRequest;
};

#endif
