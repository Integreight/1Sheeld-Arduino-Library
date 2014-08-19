#ifndef PrintClass_h
#define PrintClass_h

#define WRITE_ID 0x01
#define PRINT_ID 0x02
#define DEC	  10

class PrintClass
{
public:
	PrintClass(byte, byte);
	//Write
	void write(char);
	//Printing functions
	void print(char);
	void print(long,byte = DEC);
	void print(unsigned long,byte =DEC);
	void print(char *);
	void print(double ,int = 3 );
	//Printing in new line 
	void println(char);
	void println(long,byte = DEC);
	void println(unsigned long,byte =DEC);
	void println(char *);
	void println(double , int = 3);
private:
	byte shieldId;
	byte functionsIdOffset;
};

#endif