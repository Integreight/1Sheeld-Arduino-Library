#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "OneSheeld.h"
#include "DataLoggerShield.h"
#include "HardwareSerial.h"


DataLoggerShield::DataLoggerShield()
{

}

void DataLoggerShield::startLogging()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,START_LOG,0);
}

void DataLoggerShield::startLogging(char * fileName)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,START_LOG,1,new FunctionArg(strlen(fileName),(byte *)fileName));
}

void DataLoggerShield::stopLogging()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,STOP_LOG,0);
}


void DataLoggerShield::setFileFormat(byte format)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,SET_FORMAT,1,new FunctionArg(1,&format));
}


void DataLoggerShield::add(int key,float value,int decimalAfterPoint)
{
	char floattostring[10]={0};
	char inttostring [5]={0};
	dtostrf(value,10,decimalAfterPoint,floattostring);
	itoa(key,inttostring,10);

	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOG_DATA,2,new FunctionArg(5,(byte *)inttostring),new FunctionArg(10,(byte*)floattostring));
}

void DataLoggerShield::add(char * key,float value,int decimalAfterPoint)
{
	char floattostring[10]={0};
	dtostrf(value,10,decimalAfterPoint,floattostring);

	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOG_DATA,2,new FunctionArg(strlen(key),(byte *)key),new FunctionArg(10,(byte*)floattostring));
}

DataLoggerShield Logger;