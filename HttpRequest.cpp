/*

  Project:       1Sheeld Library 
  File:          HttpRequest.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/

#include "OneSheeld.h"
#include "InternetShield.h"


int HttpRequest::totalRequests = 0;
HttpRequest::HttpRequest(const char * _url)
{
	int reqId=++totalRequests;
	localRequestId[0] = reqId & 0xFF;
	localRequestId[1] = (reqId >> 8) & 0xFF;
	started = false;
	finished = false;
	callbacksRequested = 0;
	url = NULL;
	response.requestId = getId();
	if(!OneSheeldClass::isInitialized())
	{
		int urlLength=strlen(_url);
		url = (char*)malloc(sizeof(char)*(urlLength+1));
		for (int j=0; j<urlLength; j++)
		{
			url[j]=_url[j];
		}
		url[urlLength]='\0';
		OneSheeldClass::addToUnSentRequestsArray(this);
		isInitFrameSent=false;
	}
	else
	{
		sendInitFrame(_url);
	}
}

void HttpRequest::sendInitFrame()
{
	if(!isInitFrameSent)
	{
		sendInitFrame(url);
		free (url);
	}
}

void HttpRequest::sendInitFrame(char * _url)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_REQUEST_URL,2,new FunctionArg(sizeof(int),(byte*)localRequestId),new FunctionArg(strlen(_url),(byte*)_url));
	isInitFrameSent=true;
}

void HttpRequest::setUrl(char * urlName)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_SET_URL,2,
						 new FunctionArg(sizeof(int),localRequestId),
						 new FunctionArg(strlen(urlName),(byte*)urlName));
}



void HttpRequest::addHeader(char * headerName,char * data)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_ADD_HEADER,3,
		                 new FunctionArg(sizeof(int),localRequestId),
		                 new FunctionArg(strlen(headerName),(byte*)headerName),
		                 new FunctionArg(strlen(data),(byte*)data));
}


void HttpRequest::addParameter(char * paramName,char * data)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_ADD_PARAMETER,3,
		                 new FunctionArg(sizeof(int),localRequestId),
		                 new FunctionArg(strlen(paramName),(byte*)paramName),
		                 new FunctionArg(strlen(data),(byte*)data));
}

void HttpRequest::addRawData(char * data)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_ADD_RAW_DATA,2,
						 new FunctionArg(sizeof(int),localRequestId),
						 new FunctionArg(strlen(data),(byte*)data));
}

int HttpRequest::getId(void)
{
	return (localRequestId[1] << 8) | localRequestId[0];
}

void HttpRequest::deleteHeaders(void)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_DELETE_HEADER,1,new FunctionArg(sizeof(int),localRequestId));
}

void HttpRequest::deleteParameters(void)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_DELETE_PARAMETER,1,new FunctionArg(sizeof(int),localRequestId));
}

void HttpRequest::deleteCallBacks(void)
{
	callbacksRequested=0;
}

void HttpRequest::setContentType(char * contentType)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_SET_CONTENT_TYPE,2,
						 new FunctionArg(sizeof(int),localRequestId),
						 new FunctionArg(strlen(contentType),(byte*)contentType));
}

void HttpRequest::setParametersContentEncoding(char * contentEncoding)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_SET_CONTENT_ENCODING,2,
						 new FunctionArg(sizeof(int),localRequestId),
						 new FunctionArg(strlen(contentEncoding),(byte*)contentEncoding));
}

void HttpRequest::ignoreResponse(void)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_IGNORE_REQUEST,1,new FunctionArg(sizeof(int),localRequestId));
}

bool HttpRequest::isStarted()
{
	return started;
}

bool HttpRequest::isFinished()
{
	return finished;
}

void HttpRequest::setOnSuccess(void (*userFunction)(HttpResponse &))
{
	callbacksRequested |= SUCCESS_CALLBACK_BIT;
	successCallBack=userFunction;
}

void HttpRequest::setOnFailure(void (*userFunction)(HttpResponse &))
{
	callbacksRequested |= FAILURE_CALLBACK_BIT;
	failureCallBack=userFunction;
}

void HttpRequest::setOnStart(void (*userFunction)())
{
	callbacksRequested |= START_CALLBACK_BIT;
	startCallBack=userFunction;
}

void HttpRequest::setOnFinish(void (*userFunction)())
{
	callbacksRequested |= FINISH_CALLBACK_BIT;
	finishCallBack=userFunction;
}


HttpResponse & HttpRequest::getResponse()
{
	return response;
}

HttpRequest::~HttpRequest()
{
	for (int i = 0; i < MAX_NO_OF_REQUESTS; i++)
	{
		if(Internet.requestsArray[i] == this)
			{
				Internet.requestsArray[i]=NULL;
				return;
			}
	}
};