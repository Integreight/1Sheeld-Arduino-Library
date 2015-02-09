#include "OneSheeld.h"
#include "InternetShield.h"
#include "JsonKeyChain.h"



JsonKeyChain::JsonKeyChain()
{
  counter=0;
  isDisposed=false;
}

JsonKeyChain::JsonKeyChain(const JsonKeyChain& old)
{
	counter=old.counter;
	isDisposed=old.isDisposed;
	if(counter>0){
		for(int i=0;i<counter;i++)
		{
			keysArray[i]=new JsonKey(*old.keysArray[i]);
		}
	}
}

JsonKeyChain & JsonKeyChain::operator[](int key)
{
    if(counter<MAX_JSON_KEY_DEPTH)keysArray[counter++]=new JsonKey(key);
    return *this;
}

JsonKeyChain & JsonKeyChain::operator[](const char *key)
{
    if(counter<MAX_JSON_KEY_DEPTH)keysArray[counter++]=new JsonKey(key);
    return *this;
}

bool JsonKeyChain::operator==(const JsonKeyChain& other) 
{
    if(counter!=other.counter)return false;
    for(int i=0;i<counter;i++)
    {
      if(keysArray[i]->isString()!=other.keysArray[i]->isString())
      {
        return false;
      }
      else if(keysArray[i]->isString() && strcmp(keysArray[i]->getString(),other.keysArray[i]->getString()))
      {
        return false;
      }
      else if(keysArray[i]->isNumber() && keysArray[i]->getNumber()!=other.keysArray[i]->getNumber())
      {
        return false;
      }
    }
    return true;
}

bool JsonKeyChain::operator!=(const JsonKeyChain& other)
{
  return !(*this == other);
}

void JsonKeyChain::query()
{
	if(counter>16)return;
	int types=0;
	FunctionArg **arguments =(FunctionArg**)malloc(sizeof(FunctionArg *)*(counter+1));

	for(int i=1;i<counter+1;i++)
    {
      if(keysArray[i-1]->isString())arguments[i]=new FunctionArg(strlen(keysArray[i-1]->getString()),(byte *)keysArray[i-1]->getString());
      else 
      {
      	byte integerArray[2] ;
	  	integerArray[1] = (keysArray[i-1]->getNumber() >> 8) & 0xFF;
	  	integerArray[0] = keysArray[i-1]->getNumber() & 0xFF;
      	arguments[i]=new FunctionArg(sizeof(int),integerArray);	
      }
      types|=((keysArray[i-1]->isString())<<(i-1));
    }
    byte integerArray[2] ;
  	integerArray[1] = (types >> 8) & 0xFF;
  	integerArray[0] = types & 0xFF;
  	arguments[0]=new FunctionArg(sizeof(int),integerArray);
  	
  	OneSheeld.sendPacket(INTERNET_ID,0,INTERNET_GET_JSON,counter+1,arguments);

  	for(int i=1;i<counter+1;i++)
    {
    	delete arguments[i];
    	delete keysArray[i-1];
    }
    delete arguments[0];
    free(arguments);
    counter=0;
    isDisposed=true;
}

JsonKeyChain::~JsonKeyChain()
{
    if(isDisposed)return;
    for(int i=0;i<counter;i++)
    {
      delete keysArray[i];
    }
}