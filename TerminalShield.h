#ifndef TerminalShield_h
#define TerminalShield_h

//Output Function ID's
#define WRITE_TERMINAL 0x01			//conflicts with #define of LCD 
#define PRINT_TERMINAL 0x02
#define DEC   10
//Input Function ID
#define READ  0x01


class TerminalShield 
{
public:
	TerminalShield();
	void write(byte);
	//printing 
	void print(char);
	void print(int , byte = DEC);
	void print(unsigned int ,byte =DEC);
	void print(long,byte=DEC);
	void print(unsigned long,byte =DEC);
	void print(char *);
	void print(double);
	//print in new line
	void println(char);
	void println(int , byte = DEC);
	void println(unsigned int ,byte =DEC);
	void println(long,byte=DEC);
	void println(unsigned long,byte =DEC);
	void println(char *);
	void println(double);

	char getData();
	char * getString();
	
private:
	void printNumber(unsigned long ,byte);
	void printFloat(double,byte);
	char data;
	char * string;
	void processData();
	bool signFlag;
	bool newLineFlag;

	friend class OneSheeldClass;
};

extern TerminalShield Terminal;
#endif