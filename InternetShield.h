/*

  Project:       1Sheeld Library 
  File:          InternetShield.h
                 
  Version:       1.4

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/
#ifndef	InternetShield_h
#define InternetShield_h

#include "ShieldParent.h"

//Output Function ID's for HTTP Request class
#define HTTP_REQUEST_URL					0x01
#define HTTP_SET_URL						0x02
#define HTTP_ADD_HEADER						0x03
#define	HTTP_ADD_PARAMETER					0x04
#define HTTP_DELETE_HEADER					0x05
#define HTTP_DELETE_PARAMETER				0x06
#define HTTP_SET_CONTENT_TYPE				0x07
#define HTTP_IGNORE_REQUEST					0x08
//Output Function ID's for Internet calss
#define INTERNET_GET						0x09
#define INTERNET_POST						0x0A
#define INTERNET_PUT						0x0B
#define INTERNET_DELETE						0x0C
#define INTERNET_CANCEL_ALL_REQUESTS		0x0D
#define INTERNET_SET_AUTHENTICATION			0x0E
#define INTERNET_CLEAR_AUTHENTICATIOM		0x0F
#define INTERNET_SET_DEFAULT_MAX_RESPONSE	0x10
//Output Function ID's for Response class
#define RESPONSE_DISPOSE					0x11
#define RESPONSE_GET_NEXT_BYTES				0x12
#define RESPONSE_GET_HEADER					0x13

//Input Function ID's for HTTP Request class
#define HTTP_GET_SUCCESS					0x01
#define HTTP_GET_FAILURE					0x02
#define HTTP_GET_STARTED					0x03
#define HTTP_GET_ON_PROGRESS				0x04
#define HTTP_GET_ON_FINISH					0x05
//Input Function ID's for Internet class
#define INTERNET_GET_ERROR					0x06
//Input Function ID's for Response class
#define RESPONSE_INPUT_GET_HEADER			0x07
#define	RESPONSE_GET_ERROR					0x08
#define RESPONSE_GET_NEXT_RESPONSE			0x09

#define SUCCESS_CALLBACK_BIT				0x01
#define FAILURE_CALLBACK_BIT				0x02
#define START_CALLBACK_BIT					0x04
#define FINISH_CALLBACK_BIT					0x08
#define PROGRESS_CALLBACK_BIT				0x10
#define RESPONSE_INPUT_GET_HEADER_BIT		0x01
#define	RESPONSE_GET_ERROR_BIT				0x02
#define RESPONSE_GET_NEXT_RESPONSE_BIT		0x04

#define MAX_NO_OF_REQUESTS					20



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
	void dispose();
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

	~HttpResponse()
	{
		if(isInit&&bytesCount!=0)free(bytes);
	}
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


class HttpRequest 
{
public:
	//Constructors
	HttpRequest(char *);
	HttpRequest(String);
	//Setters
	void setUrl(char *);
	void setUrl(String);
	//Adders
	void addHeader(char * ,float);
	void addHeader(char * ,char *);
	void addHeader(String ,float);
	void addHeader(String ,String);
	//Adders
	void addParameter(char * ,float);
	void addParameter(char * ,char *);
	void addParameter(String ,float);
	void addParameter(String ,String);
	//Getters
	int getRequestId();
	//Deleters
	void deleteHeaders(void);
	void deleteParameters(void);
	void deleteCallBacks();
	//Setters
	void setContentType(char * );
	void setContentType(String );
	//Deleter
	void ignoreResponse(void);
	//Checkers
	bool isStarted();
	bool isFinished();
	//Set On for userFunctions 
	void setOnSuccess(void (*)(HttpResponse&));
	void setOnFailure(void (*)(HttpResponse&));
	void setOnStart(void (*)());
	void setOnProgress(void (*)(int ,int));
	void setOnFinish(void (*)());
	~HttpRequest(){};
private:
	bool started;
	bool finished;
	int localRequestId;
	void (*successCallBack)(HttpResponse &);
	void (*failureCallBack)(HttpResponse &);
	void (*startCallBack)();
	void (*finishCallBack)();
	void (*progressCallback)(int,int);
	byte callbacksRequested;
	// byte callbacksReceived;
	HttpResponse response;
	static int totalRequests;
friend class InternetShield;
};



class InternetShield : public ShieldParent
{
public:
	//Constructor 
	InternetShield();
	//Senders 
	bool performGet(HttpRequest &);
	bool performPost(HttpRequest &);
	bool performPut(HttpRequest &);
	bool performDelete(HttpRequest &);
	void cancelAllRequests();
	void ignoreResponse(HttpRequest &);
	void setBasicAuthentication(char * ,char *);
	void setBasicAuthentication(String ,String);
	void clearBasicAuthentication();
	void setDefaultMaxResponseBytesCount(int );
	//Set on for userFunction
	void setOnError(void (*)(int));
private:
	bool isSetOnErrorCallBackAssigned;
	void processData();
	void (*internetErrorCallBack)(int);
	HttpRequest * requestsArray[MAX_NO_OF_REQUESTS];

};
//Extern Object
extern InternetShield Internet;
#endif