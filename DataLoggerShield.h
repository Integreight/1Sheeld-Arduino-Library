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

//Ouput Function ID's
#define LOGGER_START_LOG 	   0x01
#define LOGGER_STOP_LOG	   	   0x02
#define LOGGER_ADD_FLOAT	   0x03
#define LOGGER_ADD_STRING	   0x04
#define LOGGER_LOG_DATA	   	   0x05
#define LOGGER_SELECT_SHIELD   0xFE
#define LOGGER_UNSELECT_SHIELD   0xFD

//Input Function ID
#define LOGGER_CHECK_SELECTED	0xFF


class DataLoggerShield
{
public:
	//Starters
	void start();
	void start(const char *);
	void start(String );
	//Stopper
	void stop();
	//Process 
	void add(const char * , float);
	void add(String , float);
	void add(const char * ,const char*);
	void add(String , String);
	//Save data
	void log();
	//Selection
	void select();
	void unselect();
	//Set on when selected
	void setOnSelected(void(*)(void));
private:
	void processData();
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;


};

//Extern Object
extern DataLoggerShield Logger;
#endif
