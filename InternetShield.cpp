/*

  Project:       1Sheeld Library 
  File:          InternetShield.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/
#include "OneSheeld.h"
#include "InternetShield.h"



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
	
	OneSheeld.sendPacket(INTERNET_ID,0,INTERNET_GET,2,
						 new FunctionArg(sizeof(int),request.localRequestId),
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
	
	OneSheeld.sendPacket(INTERNET_ID,0,INTERNET_POST,2,
						 new FunctionArg(sizeof(int),request.localRequestId),
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
	
	OneSheeld.sendPacket(INTERNET_ID,0,INTERNET_PUT,2,
						 new FunctionArg(sizeof(int),request.localRequestId),
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
	
	OneSheeld.sendPacket(INTERNET_ID,0,INTERNET_DELETE,2,
						 new FunctionArg(sizeof(int),request.localRequestId),
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