/*

  Project:       1Sheeld Library 
  File:          VoiceRecognitionShield.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/
#include "OneSheeld.h"
#include "InternetShield.h"

/***************************HttpRequest************************/
/**************************************************************/
/*************************************************************/
int HttpRequest::totalRequests = 0;

HttpRequest::HttpRequest(char * url)
{
	localRequestId = ++totalRequests;
	started = 0;
	finished = 0;
	response.requestId = localRequestId;
	//OneSheeld.sendPacket(INTERNET_ID,0,HTTP_REQUEST_URL,2,new FunctionArg(sizeof(int),(byte*)OneSheeld.convertIntegerToBytes(totalRequests)),new FunctionArg(strlen(url),(byte*)url));
}

void HttpRequest::setUrl(char * urlName)
{
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = localRequestId & 0xFF;
	
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_SET_URL,2,
						 new FunctionArg(sizeof(int),idIntegerArray),
						 new FunctionArg(strlen(urlName),(byte*)urlName));
}


void HttpRequest::addHeader(char * headerName,float value)
{
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = localRequestId & 0xFF;

	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_ADD_HEADER,3,
		                 new FunctionArg(sizeof(int),idIntegerArray),
		                 new FunctionArg(strlen(headerName),(byte*)headerName),
		                 new FunctionArg(sizeof(float),(byte*)OneSheeld.convertFloatToBytes(value)));
}


void HttpRequest::addHeader(char * headerName,char * data)
{
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = localRequestId & 0xFF;

	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_ADD_HEADER,3,
		                 new FunctionArg(sizeof(int),idIntegerArray),
		                 new FunctionArg(strlen(headerName),(byte*)headerName),
		                 new FunctionArg(strlen(data),(byte*)data));
}

void HttpRequest::addParameter(char * paramName,float value)
{
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = localRequestId & 0xFF;

	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_ADD_PARAMETER,3,
		                 new FunctionArg(sizeof(int),idIntegerArray),
		                 new FunctionArg(strlen(paramName),(byte*)paramName),
		                 new FunctionArg(sizeof(float),(byte*)OneSheeld.convertFloatToBytes(value)));
}


void HttpRequest::addParameter(char * paramName,char * data)
{
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = localRequestId & 0xFF;

	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_ADD_PARAMETER,3,
		                 new FunctionArg(sizeof(int),idIntegerArray),
		                 new FunctionArg(strlen(paramName),(byte*)paramName),
		                 new FunctionArg(strlen(data),(byte*)data));
}

int HttpRequest::getRequestId(void)
{
	return localRequestId;
}

void HttpRequest::deleteHeaders(void)
{
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = localRequestId & 0xFF;

	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_DELETE_HEADER,1,new FunctionArg(sizeof(int),idIntegerArray));
}

void HttpRequest::deleteParameters(void)
{
	byte idIntegerArray[2] ;
	idIntegerArray[1] = (localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = (localRequestId & 0xFF);

	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_DELETE_PARAMETER,1,new FunctionArg(sizeof(int),idIntegerArray));
}

void HttpRequest::deleteCallBacks(void)
{
	callbacksRequested=0;
}

void HttpRequest::setContentType(char * contentType)
{
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = localRequestId & 0xFF;
	
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_SET_CONTENT_TYPE,2,
						 new FunctionArg(sizeof(int),idIntegerArray),
						 new FunctionArg(strlen(contentType),(byte*)contentType));
}

void HttpRequest::ignoreResponse(void)
{
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = localRequestId & 0xFF;
	
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_IGNORE_REQUEST,1,new FunctionArg(sizeof(int),idIntegerArray));
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

void HttpRequest::setOnProgress(void (*userFunction)(int,int))
{
	callbacksRequested |= PROGRESS_CALLBACK_BIT;
	progressCallback=userFunction;
}

/***************************HttpResponse************************/
/**************************************************************/
/*************************************************************/
HttpResponse::HttpResponse()
{
	isDisposedTriggered=false;
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
	index=start;
	byte idIntegerArray1[2] ;
  	idIntegerArray1[1] = (start >> 8) & 0xFF;
  	idIntegerArray1[0] = start & 0xFF;

  	byte idIntegerArray2[2] ;
  	idIntegerArray2[1] = (size >> 8) & 0xFF;
  	idIntegerArray2[0] = size & 0xFF;

  	byte idIntegerArray3[2] ;
  	idIntegerArray3[1] = (requestId >> 8) & 0xFF;
  	idIntegerArray3[0] = requestId & 0xFF;
	
	OneSheeld.sendPacket(INTERNET_ID,0,RESPONSE_GET_NEXT_BYTES,3,new FunctionArg(sizeof(int),idIntegerArray1),
																 new FunctionArg(sizeof(int),idIntegerArray2),
																 new FunctionArg(sizeof(int),idIntegerArray3));
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

void HttpResponse::dispose()
{
	isDisposedTriggered = true;
	if(!isInit && bytesCount!=0)
	{
		free(bytes);
	}
	isInit=false;

	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (requestId >> 8) & 0xFF;
  	idIntegerArray[0] = requestId & 0xFF;
	
	OneSheeld.sendPacket(INTERNET_ID,0,RESPONSE_DISPOSE,1,new FunctionArg(sizeof(int),idIntegerArray));
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
	callbacksRequested |= RESPONSE_INPUT_GET_HEADER_BIT;
	getHeaderCallBack = userFunction;
	OneSheeld.sendPacket(INTERNET_ID,0,RESPONSE_INPUT_GET_HEADER,1,new FunctionArg(strlen(headerName),(byte *)headerName));
}

/***************************Internet***************************/
/*************************************************************/
/************************************************************/
InternetShield::InternetShield() : ShieldParent(INTERNET_ID)
{
	for(int i=0;i<MAX_NO_OF_REQUESTS;i++){
		requestsArray[i]=NULL;
	}
}

bool InternetShield::performGet(HttpRequest & request)
{	
	if(request.callbacksRequested!=0)
	{
		int i;
		for (i = 0; i < MAX_NO_OF_REQUESTS; i++)
		{
			if(requestsArray[i]==NULL)break;
		}

		if(i>=MAX_NO_OF_REQUESTS)return false;
		else
		{
			requestsArray[i]=&request;
		}

	}
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (request.localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = request.localRequestId & 0xFF;
	
	OneSheeld.sendPacket(INTERNET_ID,0,INTERNET_GET,2,
						 new FunctionArg(sizeof(int),idIntegerArray),
						 new FunctionArg(1,&(request.callbacksRequested)));
	return true;
}

bool InternetShield::performPost(HttpRequest & request)
{	
	if(request.callbacksRequested!=0)
	{
		int i;
		for (i = 0; i < MAX_NO_OF_REQUESTS; i++)
		{
			if(requestsArray[i]==NULL)break;
		}

		if(i>=MAX_NO_OF_REQUESTS)return false;
		else
		{
			requestsArray[i]=&request;
		}

	}
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (request.localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = request.localRequestId & 0xFF;
	
	OneSheeld.sendPacket(INTERNET_ID,0,INTERNET_POST,2,
						 new FunctionArg(sizeof(int),idIntegerArray),
						 new FunctionArg(1,&(request.callbacksRequested)));
	return true;
}

bool InternetShield::performPut(HttpRequest & request)
{	
	if(request.callbacksRequested!=0)
	{
		int i;
		for (i = 0; i < MAX_NO_OF_REQUESTS; i++)
		{
			if(requestsArray[i]==NULL)break;
		}

		if(i>=MAX_NO_OF_REQUESTS)return false;
		else
		{
			requestsArray[i]=&request;
		}

	}
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (request.localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = request.localRequestId & 0xFF;
	
	OneSheeld.sendPacket(INTERNET_ID,0,INTERNET_PUT,2,
						 new FunctionArg(sizeof(int),idIntegerArray),
						 new FunctionArg(1,&(request.callbacksRequested)));
	return true;
}

bool InternetShield::performDelete(HttpRequest & request)
{	
	if(request.callbacksRequested!=0)
	{
		int i;
		for (i = 0; i < MAX_NO_OF_REQUESTS; i++)
		{
			if(requestsArray[i]==NULL)break;
		}

		if(i>=MAX_NO_OF_REQUESTS)return false;
		else
		{
			requestsArray[i]=&request;
		}

	}
	byte idIntegerArray[2] ;
  	idIntegerArray[1] = (request.localRequestId >> 8) & 0xFF;
  	idIntegerArray[0] = request.localRequestId & 0xFF;
	
	OneSheeld.sendPacket(INTERNET_ID,0,INTERNET_DELETE,2,
						 new FunctionArg(sizeof(int),idIntegerArray),
						 new FunctionArg(1,&(request.callbacksRequested)));
	return true;
}

void InternetShield::ignoreResponse(HttpRequest & request)
{
	request.ignoreResponse();
}

void InternetShield::cancelAllRequests(void)
{
	OneSheeld.sendPacket(INTERNET_ID,0,INTERNET_CANCEL_ALL_REQUESTS,0);
}

void InternetShield::setBasicAuthentication(char * userName,char * password)
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_ADD_HEADER,2,
		                 new FunctionArg(strlen(userName),(byte*)userName),
		                 new FunctionArg(strlen(password),(byte*)password));
}

void InternetShield::clearBasicAuthentication()
{
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_ADD_HEADER,0);
}

void InternetShield::setDefaultMaxResponseBytesCount(int data)
{
	byte IntegerArray[2] ;
  	IntegerArray[1] = (data >> 8) & 0xFF;
  	IntegerArray[0] = data & 0xFF;
	OneSheeld.sendPacket(INTERNET_ID,0,HTTP_ADD_HEADER,1,new FunctionArg(sizeof(int),IntegerArray));
}

void InternetShield::processData()
{
	byte functionId = OneSheeld.getFunctionId();

	if(functionId == HTTP_GET_SUCCESS   || functionId == HTTP_GET_FAILURE           ||
	   functionId == HTTP_GET_STARTED   || functionId == HTTP_GET_ON_PROGRESS       ||
	   functionId == HTTP_GET_ON_FINISH || functionId == RESPONSE_GET_NEXT_RESPONSE ||
	   functionId == RESPONSE_GET_ERROR || functionId == RESPONSE_INPUT_GET_HEADER)
	{

		int requestId  = OneSheeld.getArgumentData(0)[0]|((OneSheeld.getArgumentData(0)[1])<<8);
		unsigned long totalBytesCount  = 0;
		unsigned long progressDoneBytes  = 0;
		int statusCodeOrError = 0;

		if(functionId ==HTTP_GET_SUCCESS||functionId == HTTP_GET_FAILURE || functionId == RESPONSE_GET_ERROR )
			statusCodeOrError = OneSheeld.getArgumentData(1)[0]|((OneSheeld.getArgumentData(1)[1])<<8);
		
		else if(functionId == HTTP_GET_ON_PROGRESS)
		{	
			progressDoneBytes  =(unsigned long)OneSheeld.getArgumentData(1)[0]
						 		|(((unsigned long)OneSheeld.getArgumentData(1)[1])<<8)
						 		|(((unsigned long)OneSheeld.getArgumentData(1)[2])<<16)
						 		|(((unsigned long)OneSheeld.getArgumentData(1)[3])<<24); 
		}


		if(functionId == HTTP_GET_SUCCESS||functionId == HTTP_GET_FAILURE||functionId == HTTP_GET_ON_PROGRESS)
		{	
			 totalBytesCount  =(unsigned long)OneSheeld.getArgumentData(2)[0]
						 		|(((unsigned long)OneSheeld.getArgumentData(2)[1])<<8)
						 		|(((unsigned long)OneSheeld.getArgumentData(2)[2])<<16)
						 		|(((unsigned long)OneSheeld.getArgumentData(2)[3])<<24); 
		}
		
		char * data =NULL;
		int dataLength=0;
		int i;
		for (i = 0; i < MAX_NO_OF_REQUESTS; i++)
		{  
			if(requestsArray[i]!=NULL&&requestsArray[i]->localRequestId==requestId)
			{
				if((((requestsArray[i]->callbacksRequested) & SUCCESS_CALLBACK_BIT) && functionId == HTTP_GET_SUCCESS)||
				   (((requestsArray[i]->callbacksRequested) & FAILURE_CALLBACK_BIT) && functionId == HTTP_GET_FAILURE)||
				   (((requestsArray[i]->response.callbacksRequested) & RESPONSE_GET_NEXT_RESPONSE_BIT) && functionId == RESPONSE_GET_NEXT_RESPONSE))
				{
					byte dataArgumentNumber; 

					if(functionId == RESPONSE_GET_NEXT_RESPONSE)
					{
						dataArgumentNumber = 1;
						if(requestsArray[i]->response.bytesCount!= 0 && requestsArray[i]->response.isInit)
						{
							free(requestsArray[i]->response.bytes);
						}
					}
					else dataArgumentNumber = 3;
					
					if(functionId == RESPONSE_GET_NEXT_RESPONSE || totalBytesCount!=0)
					{
						dataLength = OneSheeld.getArgumentLength(dataArgumentNumber);
						data=(char*)malloc(sizeof(char)*(dataLength+1));
						for (int j=0; j<dataLength; j++)
						{
							data[j]=OneSheeld.getArgumentData(dataArgumentNumber)[j];
						}

						data[dataLength]='\0';
						requestsArray[i]->response.bytesCount=dataLength;
						requestsArray[i]->response.index=dataLength;
						requestsArray[i]->response.bytes=data;
					}

					if(functionId != RESPONSE_GET_NEXT_RESPONSE)
					{
						requestsArray[i]->response.isInit=true;
						requestsArray[i]->response.isDisposedTriggered=false;
						requestsArray[i]->response.statusCode=statusCodeOrError;
						requestsArray[i]->response.totalBytesCount=totalBytesCount;
					}
					if(((requestsArray[i]->callbacksRequested) & SUCCESS_CALLBACK_BIT) && functionId == HTTP_GET_SUCCESS) requestsArray[i]->successCallBack(requestsArray[i]->response);
					else if(((requestsArray[i]->callbacksRequested) & FAILURE_CALLBACK_BIT) && functionId == HTTP_GET_FAILURE) requestsArray[i]->failureCallBack(requestsArray[i]->response);
					else if((requestsArray[i]->response.callbacksRequested) & RESPONSE_GET_NEXT_RESPONSE_BIT) requestsArray[i]->response.getNextCallBack(requestsArray[i]->response);
				}
				else if(((requestsArray[i]->callbacksRequested) & START_CALLBACK_BIT) && functionId == HTTP_GET_STARTED)
				{
					requestsArray[i]->startCallBack();
				}
				else if(((requestsArray[i]->callbacksRequested) & FINISH_CALLBACK_BIT) && functionId == HTTP_GET_ON_FINISH)
				{
					requestsArray[i]->finishCallBack();
				}
				else if(((requestsArray[i]->callbacksRequested) & PROGRESS_CALLBACK_BIT) && functionId == HTTP_GET_ON_PROGRESS)
				{
					requestsArray[i]->progressCallback(progressDoneBytes,totalBytesCount);
				}
				else if((requestsArray[i]->response.callbacksRequested) & RESPONSE_GET_ERROR_BIT) 
				{
					requestsArray[i]->response.getErrorCallBack(statusCodeOrError);	
				}
				else if((requestsArray[i]->response.callbacksRequested) & RESPONSE_INPUT_GET_HEADER_BIT)
				{
					byte headerNameLength = OneSheeld.getArgumentLength(1);

					char  headerName [headerNameLength+1];
					for(int k = 0 ;k<headerNameLength ;k++)
					{
						headerName[k]=OneSheeld.getArgumentData(1)[k];
					}
					headerName[headerNameLength]='\0';


					byte headerValueLength = OneSheeld.getArgumentLength(2);

					char  headerValue [headerValueLength+1];
					for(int j = 0 ;j<headerValueLength ;j++)
					{
						headerValue[j]=OneSheeld.getArgumentData(2)[j];
					}
					headerValue[headerValueLength]='\0';

					requestsArray[i]->response.getHeaderCallBack(headerName,headerValue);
				}
				break;
			}
		}	

	}
	else if(functionId == INTERNET_GET_ERROR)
	{
		int errorNumber  = OneSheeld.getArgumentData(0)[0]|((OneSheeld.getArgumentData(0)[1])<<8);
		(*internetErrorCallBack)(errorNumber);
	}
}

void InternetShield::setOnError(void (*userFunction)(int errorNumber))
{
	isSetOnErrorCallBackAssigned = true;
	internetErrorCallBack = userFunction;
}

InternetShield Internet;