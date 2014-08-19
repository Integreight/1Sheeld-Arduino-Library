/*

  Project:       1Sheeld Library 
  File:          DataLogger.cpp
                 
  Version:       1.0.1

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.7

*/
#include "OneSheeld.h"
#include "DataLoggerShield.h"


//Start Logging Data
void DataLoggerShield::startLogging()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,START_LOG,0);
}
//Start Logging Data giving name to file created 
void DataLoggerShield::startLogging(char * fileName)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,START_LOG_NAME,1,new FunctionArg(strlen(fileName),(byte *)fileName));
}

//Stop Logging Data
void DataLoggerShield::stopLogging()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,STOP_LOG,0);
}

//Set File Format whether JSON or CSV
void DataLoggerShield::setFileFormat(byte format)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,SET_FORMAT,1,new FunctionArg(1,&format));
}

//Log Data
void DataLoggerShield::add(char * key,float value)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,ADD_FLOAT,2,new FunctionArg(strlen(key),(byte *)key),new FunctionArg(sizeof(float),(byte*)OneSheeld.convertFloat(value)));
}

void DataLoggerShield::add(char * key, char * data)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,ADD_STRING,2,new FunctionArg(strlen(key),(byte *)key),new FunctionArg(strlen(data),(byte*)data));
}
//Save data 
void DataLoggerShield::log()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOG_DATA,0);
}
//Instantiating Object
DataLoggerShield Logger;