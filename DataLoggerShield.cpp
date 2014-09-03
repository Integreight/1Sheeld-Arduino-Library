/*

  Project:       1Sheeld Library 
  File:          DataLogger.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/
#include "OneSheeld.h"
#include "DataLoggerShield.h"


//Start Logging Data
void DataLoggerShield::start()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_START_LOG,0);
}
//Start Logging Data giving name to file created 
void DataLoggerShield::start(char * fileName)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_START_LOG,1,new FunctionArg(strlen(fileName),(byte *)fileName));
}

//Stop Logging Data
void DataLoggerShield::stop()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_STOP_LOG,0);
}

//Log Data
void DataLoggerShield::add(const char * key,float value)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_ADD_FLOAT,2,new FunctionArg(strlen(key),(byte *)key),new FunctionArg(sizeof(float),(byte*)OneSheeld.convertFloat(value)));
}

void DataLoggerShield::add(const char * key,const char * data)
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_ADD_STRING,2,new FunctionArg(strlen(key),(byte *)key),new FunctionArg(strlen(data),(byte*)data));
}
//Save data 
void DataLoggerShield::log()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_LOG_DATA,0);
}
//Instantiating Object
DataLoggerShield Logger;