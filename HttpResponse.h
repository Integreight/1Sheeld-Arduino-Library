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

//Output Function ID's for Response class
#define RESPONSE_DISPOSE					0x11
#define RESPONSE_GET_NEXT_BYTES				0x12
#define RESPONSE_GET_HEADER					0x13
#define RESPONSE_INPUT_GET_HEADER			0x07
//Input Function ID's for Response class
#define	RESPONSE_GET_ERROR					0x08
#define RESPONSE_GET_NEXT_RESPONSE			0x09
//Bit Setters
#define RESPONSE_INPUT_GET_HEADER_BIT		0x01
#define	RESPONSE_GET_ERROR_BIT				0x02
#define RESPONSE_GET_NEXT_RESPONSE_BIT		0x04


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
	//Setters
	void dispose(bool=true);
	void resetIndex(int= 0);
	//Getters
	void getNextBytes(int=255);
	void getTheseBytes(int ,int);
	void getHeader(char * , void (*)(char * ,float ));
	void getHeader(char * , void (*)(char * ,char * ));
	// void getHeader(String , void (*)(String ,float ));
	// void getHeader(String , void (*)(String ,String ));
	int getStatusCode();
	int getBytesCount();
	unsigned long getTotalBytesCount();
	char * getBytes();
	String getBytesAsStrings();
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

friend class InternetShield;
friend class HttpRequest;
};

#endif
