/*

  Project:       1Sheeld Library 
  File:          HttpResponse.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/

#include "OneSheeld.h"
#include "InternetShield.h"


HttpResponse::HttpResponse()
{
	isInit=false;
	isDisposedTriggered=false;
	statusCode=0;
	totalBytesCount=0;
	bytes=NULL;
	bytesCount = 0;
	requestId = 0;
	index =0;
	callbacksRequested = 0;
}

int HttpResponse::getStatusCode()
{
	return statusCode;
}

int HttpResponse::getBytesCount()
{
	return bytesCount;
}

char * HttpResponse::getBytes()
{
	return bytes;
}

unsigned long HttpResponse::getTotalBytesCount()
{
	return totalBytesCount;
}

unsigned long HttpResponse::getCurrentIndex()
{
	return index;
}

void HttpResponse::getTheseBytes(unsigned long start,int size)
{
	if(isInit)
	{
		index=start;
		byte startArray[4] ;
	  	startArray[0] = start & 0xFF;
	  	startArray[1] = (start >> 8) & 0xFF;
	  	startArray[2] = (start >> 16) & 0xFF;
	  	startArray[3] = (start >> 24) & 0xFF;
		
	  	byte sizeArray[2] ;
	  	sizeArray[1] = (size >> 8) & 0xFF;
	  	sizeArray[0] = size & 0xFF;

	  	byte reqId[2] ;
	  	reqId[1] = (requestId >> 8) & 0xFF;
	  	reqId[0] = requestId & 0xFF;
		
		OneSheeld.sendPacket(INTERNET_ID,0,RESPONSE_GET_NEXT_BYTES,3,new FunctionArg(sizeof(int),reqId),
																	 new FunctionArg(sizeof(unsigned long),startArray),
																	 new FunctionArg(sizeof(int),sizeArray));
	}
	
}

void HttpResponse::getNextBytes(int size)
{
	getTheseBytes(index,size);
}

void HttpResponse::setOnNextResponseBytesUpdate(void (*userFunction)(HttpResponse &))
{
	callbacksRequested |= RESPONSE_GET_NEXT_RESPONSE_BIT;
	getNextCallBack = userFunction;
}

void HttpResponse::setOnError(void (*userFunction)(int errorNumber))
{
	callbacksRequested |= RESPONSE_GET_ERROR_BIT;
	getErrorCallBack = userFunction;
}

void HttpResponse::setOnJsonResponse(void (*userFunction)(JsonKeyChain & chain,char * data))
{
	callbacksRequested |= RESPONSE_GET_JSON_BIT;
	getJsonCallBack = userFunction;
}

bool HttpResponse::isSentFully()
{
	return (totalBytesCount-index==0);
}

void HttpResponse::dispose(bool sendFrame)
{
	isDisposedTriggered = true;
	if(isInit && bytesCount!=0 && bytes!=NULL)
	{
		free(bytes);
	}
	isInit=false;
	bytes=NULL;
	index = 0;
	bytesCount = 0;
	statusCode = 0;
	totalBytesCount = 0;
	byte reqId[2] ;
  	reqId[1] = (requestId >> 8) & 0xFF;
  	reqId[0] = requestId & 0xFF;
	
	if(sendFrame)OneSheeld.sendPacket(INTERNET_ID,0,RESPONSE_DISPOSE,1,new FunctionArg(sizeof(int),reqId));
}

bool HttpResponse::isDisposed()
{
	return isDisposedTriggered;
}

void HttpResponse::resetIndex(int x)
{
	index=x;
}

void HttpResponse::getHeader(char * headerName , void (*userFunction)(char * incomingheaderName ,char * IncomingHeaderValue))
{
	if(isInit)
	{
		callbacksRequested |= RESPONSE_INPUT_GET_HEADER_BIT;
		getHeaderCallBack = userFunction;
		OneSheeld.sendPacket(INTERNET_ID,0,RESPONSE_INPUT_GET_HEADER,1,new FunctionArg(strlen(headerName),(byte *)headerName));	
	}
	
}

JsonKeyChain HttpResponse::operator[](int key)
{
    JsonKeyChain chain;
    return chain[key];
}

JsonKeyChain HttpResponse::operator[](const char *key)
{
    JsonKeyChain chain;
    return chain[key];
}

HttpResponse::~HttpResponse()
{
	if(isInit && bytesCount!=0)free(bytes);
}