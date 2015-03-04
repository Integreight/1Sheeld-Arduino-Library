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
void DataLoggerShield::start(const char * fileName)
{
	// Check string is not empty
	int  fileNameLength = strlen(fileName);
	if(!fileNameLength) return ; 
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_START_LOG,1,new FunctionArg(fileNameLength,(byte *)fileName));
}
//Start Logging Data giving name to the file in strings
//Support strings for Arduino
#if !defined(ARDUINO_LINUX)
void DataLoggerShield::start(String fileName)
{
	const char * cTypeStringFileName = fileName.c_str();

	start(cTypeStringFileName);
}
#endif

//Supporting strings for galileo
#if defined(ARDUINO_LINUX) 
void DataLoggerShield::start(String fileName)
{
	int fileNameStringLength = fileName.length();
	char cTypeFileName [fileNameStringLength+1];

	for (int i=0 ;i<fileNameStringLength;i++)
	{
		cTypeFileName [i]= fileName[i];
	}

	cTypeFileName [fileNameStringLength]='\0';	
	start(cTypeFileName);
}
#endif
//Stop Logging Data
void DataLoggerShield::stop()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_STOP_LOG,0);
}

//Log Data
void DataLoggerShield::add(const char * key,float value)
{
	// Check string is not empty
	int  keyLength = strlen(key);
	if(!keyLength) return ; 
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_ADD_FLOAT,2,new FunctionArg(keyLength,(byte *)key),new FunctionArg(4,(byte*)OneSheeld.convertFloatToBytes(value)));
}

//Support strings for Arduino
#if !defined(ARDUINO_LINUX)
void DataLoggerShield::add(String key ,float value)
{
	const char * cTypeStringKey = key.c_str();

	add(cTypeStringKey,value);
}
#endif

//Supporting strings for galileo
#if defined(ARDUINO_LINUX) 
void DataLoggerShield::add(String key , float value)
{
	int keyStringLength = key.length();
	char cTypeKey [keyStringLength+1];

	for (int i=0 ;i<keyStringLength;i++)
	{
		cTypeKey [i]= key[i];
	}

	cTypeKey [keyStringLength]='\0';	
	add(cTypeKey,value);
}
#endif

void DataLoggerShield::add(const char * key,const char * data)
{
	// Check string is not empty
	int  keyLength = strlen(key);
	int  dataLength = strlen(data);
	if(!dataLength || !keyLength) return ;
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_ADD_STRING,2,new FunctionArg(keyLength,(byte *)key),new FunctionArg(dataLength,(byte*)data));
}

//Support strings for Arduino
#if !defined(ARDUINO_LINUX)
void DataLoggerShield::add(String key ,String data)
{
	const char * cTypeStringKey = key.c_str();
	const char * cTypesStringData = data.c_str();

	add(cTypeStringKey,cTypesStringData);
}
#endif

//Supporting strings for galileo 
#if defined(ARDUINO_LINUX)
void DataLoggerShield::add(String key , String data)
{
	int keyStringLength = key.length();
	int dataStringLength = data.length();

	char cTypeKey [keyStringLength+1];
	char cTypeData [dataStringLength+1];

	for (int i=0 ;i<keyStringLength;i++)
	{
		cTypeKey [i]= key[i];
	}
	cTypeKey [keyStringLength]='\0';

	for (int j=0 ;j<dataStringLength;j++)
	{
		cTypeData [j]= data[j];
	}
	cTypeData [dataStringLength]='\0';

	add(cTypeKey,cTypeData);
}
#endif
//Save data 
void DataLoggerShield::log()
{
	OneSheeld.sendPacket(DATA_LOGGER_ID,0,LOGGER_LOG_DATA,0);
}

#ifdef DATA_LOGGER_SHIELD
//Instantiating Object
DataLoggerShield Logger;
#endif