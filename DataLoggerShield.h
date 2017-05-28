/*

  Project:       1Sheeld Library 
  File:          DataLogger.h
                 
  Version:       1.2

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.9

*/
#ifndef DataLogger_h
#define DataLogger_h

#include "ShieldParent.h"

//Ouput Function ID's
#define LOGGER_START_LOG 	   0x01
#define LOGGER_STOP_LOG	   	   0x02
#define LOGGER_ADD_FLOAT	   0x03
#define LOGGER_ADD_STRING	   0x04
#define LOGGER_LOG_DATA	   	   0x05


class DataLoggerShield : public ShieldParent
{
public:
	DataLoggerShield():ShieldParent(DATA_LOGGER_ID){};
	//Starters
	void start();
	void start(const char *,bool=0);
	void start(String ,bool=0);
	//Stopper
	void stop();
	//Process 
	void add(const char * , float);
	void add(String , float);
	void add(const char * ,const char*);
	void add(String , String);
	//Save data
	void log();
private:


};

//Extern Object
extern DataLoggerShield Logger;
#endif
