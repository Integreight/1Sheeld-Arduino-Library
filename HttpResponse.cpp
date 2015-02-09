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
	isDisposedTriggered=false;
	bytes=NULL;
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

void HttpResponse::getTheseBytes(int start,int size)
{
	if(isInit)
	{
		index=start;
		byte startArray[2] ;
	  	startArray[1] = (start >> 8) & 0xFF;
	  	startArray[0] = start & 0xFF;

	  	byte sizeArray[2] ;
	  	sizeArray[1] = (size >> 8) & 0xFF;
	  	sizeArray[0] = size & 0xFF;

	  	byte reqId[2] ;
	  	reqId[1] = (requestId >> 8) & 0xFF;
	  	reqId[0] = requestId & 0xFF;
		
		OneSheeld.sendPacket(INTERNET_ID,0,RESPONSE_GET_NEXT_BYTES,3,new FunctionArg(sizeof(int),reqId),
																	 new FunctionArg(sizeof(int),startArray),
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

bool HttpResponse::isSentFully()
{
	return (totalBytesCount-index==0);
}

void HttpResponse::dispose(bool sendFrame)
{
	isDisposedTriggered = true;
	if(isInit && bytesCount!=0)
	{
		free(bytes);
	}
	isInit=false;
	bytes=NULL;
	callbacksRequested = 0;
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

HttpResponse::~HttpResponse()
{
	if(isInit && bytesCount!=0)free(bytes);
}