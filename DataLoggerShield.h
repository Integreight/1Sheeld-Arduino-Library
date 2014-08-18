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
#define SET_FORMAT 	   0x01
#define START_LOG  	   0x02
#define STOP_LOG	   0x03
#define ADD_NUM		   0x04
#define ADD_STRING	   0x05
#define LOG_DATA	   0x06
#define CSV_FORMAT	   0x01
#define JSON_FORMAT    0x02


class DataLoggerShield
{
public:
	//Starters
	void startLogging();
	void startLogging(char *);
	//Stopper
	void stopLogging();
	//Setter
	void setFileFormat(byte);
	//Process 
	void add(int ,float,int);
	void add(char * ,float,int);
	//Save data
	void log();
private:


};

//Extern Object
extern DataLoggerShield Logger;
#endif
