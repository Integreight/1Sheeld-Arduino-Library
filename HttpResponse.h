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
//Bit Setters
#define RESPONSE_INPUT_GET_HEADER_BIT		0x01
#define	RESPONSE_GET_ERROR_BIT				0x02
#define RESPONSE_GET_NEXT_RESPONSE_BIT		0x04
#define RESPONSE_GET_JSON_BIT				0x08


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
	JsonKeyChain operator[](int );
	JsonKeyChain operator[](const char *);
	//Setters
	void dispose(bool=true);
	void resetIndex(unsigned long= 0);
	//Getters
	void getNextBytes(int=64);
	void getTheseBytes(unsigned long ,int);
	void getHeader(char * , void (*)(char * ,float ));
	void getHeader(char * , void (*)(char * ,char * ));
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

friend class InternetShield;
friend class HttpRequest;
};

#endif
