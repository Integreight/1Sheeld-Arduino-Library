#include "OneSheeld.h"
#include "InternetShield.h"




InternetShield::InternetShield()
{
	status=0;
	result=NULL;
}

void InternetShield::open(char * url)
{
	OneSheeld.sendPacket(INTERNET_ID,0,SEND_URL,1,new FunctionArg(strlen(url),(byte *)url));
}

void InternetShield::search(char * content)
{
	OneSheeld.sendPacket(INTERNET_ID,0,SEARCH,1,new FunctionArg(strlen(content),(byte *)content));
}

void InternetShield::connect()
{
	OneSheeld.sendPacket(INTERNET_ID,0,CONNECT,0);
}

void InternetShield::disconnect()
{
	OneSheeld.sendPacket(INTERNET_ID,0,DISCONNECT,0);
}

bool InternetShield::getStatus()
{
	return status;
}

char * InternetShield::getResult()
{
	return result;
}

void InternetShield::processData()
{
	byte functionId = OneSheeld.getFunctionId();

	if(functionId == STATUS)
	{
		status=OneSheeld.getArgumentData(0)[0];
	}
	else
	{
		if (result!=0)
		{
			free(result);
		}
		int resultLength=OneSheeld.getArgumentLength(0);
		result = (char*)malloc(sizeof(char)*(resultLength+1));
		for (int j=0; j<resultLength; j++)
		{
			result[j]=OneSheeld.getArgumentData(0)[j];
		}
		result[resultLength]='\0';
	}
}
InternetShield Internet;