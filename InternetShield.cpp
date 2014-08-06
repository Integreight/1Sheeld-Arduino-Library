#include "OneSheeld.h"
#include "InternetShield.h"






void InternetShield::open(char * url)
{
	OneSheeld.sendPacket(INTERNET_ID,0,SEND_URL,1,new FunctionArg(strlen(url),(byte *)url));
}


InternetShield Internet;