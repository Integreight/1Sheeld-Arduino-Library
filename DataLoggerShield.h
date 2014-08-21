/*

  Project:       1Sheeld Library 
  File:          DataLogger.h
                 
  Version:       1.0.1

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.7

*/
#ifndef DataLogger_h
#define DataLogger_h

//Ouput Function ID's
#define START_LOG 	   0x01
#define STOP_LOG	   0x02
#define SET_FORMAT 	   0x03
#define ADD_FLOAT	   0x04
#define ADD_STRING	   0x05
#define LOG_DATA	   0x06


class DataLoggerShield
{
public:
	//Starters
	void start();
	void start(char *);
	//Stopper
	void stop();
	//Process 
	void add(char * , float);
	void add(char * , char*);
	//Save data
	void log();
private:


};

//Extern Object
extern DataLoggerShield Logger;
#endif
