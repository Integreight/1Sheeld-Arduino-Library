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

#define MAX_NO_OF_REQUESTS					20

#include "ShieldParent.h"
#include "HttpResponse.h"
#include "HttpRequest.h"


//Output Function ID's for Internet calss
#define INTERNET_GET						0x09
#define INTERNET_POST						0x0A
#define INTERNET_PUT						0x0B
#define INTERNET_DELETE						0x0C
#define INTERNET_CANCEL_ALL_REQUESTS		0x0D
#define INTERNET_SET_AUTHENTICATION			0x0E
#define INTERNET_CLEAR_AUTHENTICATIOM		0x0F
#define INTERNET_SET_DEFAULT_MAX_RESPONSE	0x10
#define INTERNET_GET_ERROR					0x06
#define INTERNET_QUERY_JSON					0x14
#define INTERNET_QUERY_JSON_ARRAY_LENGTH	0x17




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
	void clearBasicAuthentication();
	void setDefaultMaxResponseBytesCount(int );
	//Set on for userFunction
	void setOnError(void (*)(int,int));
private:
	bool isSetOnErrorCallBackAssigned;
	void processData();
	bool addToRequestsArray(HttpRequest &);
	void (*internetErrorCallBack)(int,int);
	HttpRequest * requestsArray[MAX_NO_OF_REQUESTS];
friend class HttpRequest;
};
//Extern Object
extern InternetShield Internet;
#endif