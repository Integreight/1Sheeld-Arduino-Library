/*

  Project:       1Sheeld Library 
  File:          JsonKey.cpp
                 
  Version:       1.4

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/
#include "JsonKey.h"




JsonKey::JsonKey(int key)
  {
    number=key;
    isText=false;
  }
/* Copy Constructor */
JsonKey::JsonKey(const JsonKey & old)
{
	isText=old.isText;
	if(isText)
	{
		int textSize=strlen(old.text);
		text=(char *)malloc(sizeof(char)*(textSize+1));
		for (int i = 0; i < textSize; i++)
		{
		  text[i]=old.text[i];
		}
		text[textSize]='\0';
	}
	else
	{
		number=old.number;
	}
}

JsonKey::JsonKey(const char * key)
{
	int textSize=strlen(key);
	text=(char *)malloc(sizeof(char)*(textSize+1));
	for (int i = 0; i < textSize; i++)
	{
	  text[i]=key[i];
	}
	text[textSize]='\0';
	isText=true;
}

bool JsonKey::isString()
{
    return isText;
}

bool JsonKey::isNumber()
{
    return !isText;
}

const char * JsonKey::getString()
{
    return text;
}

int JsonKey::getNumber()
{
    return number;
}


JsonKey::~JsonKey()
{
    if(isText)free(text);
}  