#ifndef DataLogger_h
#define DataLogger_h


#define SET_FORMAT 	   0x01
#define START_LOG  	   0x02
#define STOP_LOG	   0x03
#define LOG_DATA	   0x04
#define PLOT_GRAPH	   0x05
#define CSV_FORMAT	   0x01
#define JSON_FORMAT    0x02


class DataLoggerShield
{
public:
	DataLoggerShield();
	void startLogging();
	void startLogging(char *);
	void stopLogging();
	void setFileFormat(byte);
	void add(int ,float,int);
	void add(byte,float,int);
	void add(char * ,float,int);
	//void log();
	//void graph(int ,int);
	//void graph(char,int);
	//void graph(char * ,int);
	//void plot();

private:


};

extern DataLoggerShield Logger;
#endif
