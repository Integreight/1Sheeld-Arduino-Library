/*

  Project:       1Sheeld Library 
  File:          DataLogger.cpp
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "DataLoggerShield.h"



//Start Logging Data
void DataLoggerShield::start()
{
	OneSheeld.sendShieldFrame(DATA_LOGGER_ID,0,LOGGER_START_LOG,0);
}
//Start Logging Data giving name to file created 
void DataLoggerShield::start(const char * fileName,bool saveOnOld)
{
	// Check string is not empty
	int  fileNameLength = strlen(fileName);
	if(!fileNameLength) return ; 
	OneSheeld.sendShieldFrame(DATA_LOGGER_ID,0,LOGGER_START_LOG,2,new FunctionArg(fileNameLength,(byte *)fileName),new FunctionArg(1,(byte*)&saveOnOld));
}
//Start Logging Data giving name to the file in strings
void DataLoggerShield::start(String fileName,bool saveOnOld)
{
	start(&fileName[0],saveOnOld);
}

//Stop Logging Data
void DataLoggerShield::stop()
{
	OneSheeld.sendShieldFrame(DATA_LOGGER_ID,0,LOGGER_STOP_LOG,0);
}

//Log Data
void DataLoggerShield::add(const char * key,float value)
{
	// Check string is not empty
	int  keyLength = strlen(key);
	if(!keyLength) return ; 
	byte floatBytes[4];
	OneSheeld.convertFloatToBytes(value,floatBytes);
	OneSheeld.sendShieldFrame(DATA_LOGGER_ID,0,LOGGER_ADD_FLOAT,2,new FunctionArg(keyLength,(byte *)key)
																 ,new FunctionArg(sizeof(float),floatBytes));
}

void DataLoggerShield::add(String key , float value)
{	
	add(&key[0],value);
}

void DataLoggerShield::add(const char * key,const char * data)
{
	// Check string is not empty
	int  keyLength = strlen(key);
	int  dataLength = strlen(data);
	if(!dataLength || !keyLength) return ;
	OneSheeld.sendShieldFrame(DATA_LOGGER_ID,0,LOGGER_ADD_STRING,2,new FunctionArg(keyLength,(byte *)key),new FunctionArg(dataLength,(byte*)data));
}

void DataLoggerShield::add(String key , String data)
{
	add(&key[0],&data[0]);
}

//Save data 
void DataLoggerShield::log()
{
	OneSheeld.sendShieldFrame(DATA_LOGGER_ID,0,LOGGER_LOG_DATA,0);
}

