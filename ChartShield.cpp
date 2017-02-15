/*

  Project:       1Sheeld Library 
  File:          ChartShield.cpp
                 
  Version:       1.12.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.12

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "ChartShield.h"



ChartShield::ChartShield() : ShieldParent(CHART_ID)
{
	for(int i=0;i<5;i++){
		namesArray[i]=NULL;
		floatArray[i]=0;
		chartIDArray[i]=0;
	}
	keysCounter= 0 ;
}

void ChartShield::add(const char * _key,float _value, byte _chartID)
{
	
	byte found = false;
	if(_chartID>=5)
	{
		_chartID=4;
	}
	
	for(int i=0 ;i<keysCounter;i++)
	{
		if(!strcmp(namesArray[i],_key) && chartIDArray[i]==_chartID)
		{
			floatArray[i]=_value;
			found=true;
		}
	}

	byte keyLength=strlen(_key);
	if(!keyLength||keysCounter >= 5) return;	

	if(!found)
	{
		
		key = (char*)malloc(sizeof(char)*(keyLength+1));
		for (int j=0; j<keyLength; j++)
		{
			key[j]=_key[j];
		}
		key[keyLength]='\0';
		namesArray[keysCounter]=key;
		floatArray[keysCounter]=_value;
		chartIDArray[keysCounter]=_chartID;
		keysCounter++;
	}
}

void ChartShield::plot()
{
	if(keysCounter>0)
	{
		FunctionArg **arguments =(FunctionArg**)malloc(sizeof(FunctionArg *)*(keysCounter*3));
		byte stepCounter =0;
	  	for(int i=0 ;i<keysCounter*3;i+=3)
	  	{
	  		byte floatBytes[4];
	  		OneSheeld.convertFloatToBytes(floatArray[stepCounter],floatBytes);
	  		arguments[i]=   new FunctionArg(strlen(namesArray[stepCounter]),(byte*)(namesArray[stepCounter]));
	  		arguments[i+1]= new FunctionArg(4,floatBytes,true);
	  		arguments[i+2]= new FunctionArg(1,&chartIDArray[stepCounter]);
	  		stepCounter++;
	  	}
		OneSheeld.sendShieldFrame(CHART_ID,0,CHART_PLOT,keysCounter*3,arguments);
	    
	    for(int i=0;i<keysCounter*3;i++)
	    {
	      delete arguments[i];
	    }
		free(arguments);
		for(int i=0 ;i<keysCounter;i++)
		{
			if(namesArray[i]!=0)
			{
				free(namesArray[i]);
				namesArray[i]=NULL;
				floatArray[i]=0;
				chartIDArray[i]=0;
			}
		}
		keysCounter=0;
	}
}

void ChartShield::saveCsv(const char * fileName,byte _chartID)
{
	if(_chartID <5)
	{
		OneSheeld.sendShieldFrame(CHART_ID,0,CHART_SAVE_CSV,2,new FunctionArg(strlen(fileName),(byte*)fileName),new FunctionArg(1,&_chartID));
	}
}

void ChartShield::saveScreenshot(byte _chartID)
{
	OneSheeld.sendShieldFrame(CHART_ID,0,CHART_SAVE_SCREENSHOT,1,new FunctionArg(1,&_chartID));
}

void ChartShield::clear(byte _chartID)
{
	if(_chartID <5)
	{
		OneSheeld.sendShieldFrame(CHART_ID,0,CHART_CLEAR,1,new FunctionArg(1,&_chartID));
	}
}

void ChartShield::autoScroll(byte state)
{
	OneSheeld.sendShieldFrame(CHART_ID,0,CHART_AUTO_SCROLL,1,new FunctionArg(1,&state));
}