#ifndef PrintClass_h
#define PrintClass_h

#define WRITE_ID 0x01
#define PRINT_ID 0x02
#define DEC	  10

class PrintClass
{
public:
	PrintClass();
	//Write
	void write(byte ,char);
	//Printing functions
	void print(byte ,char);
	void print(byte , long,byte = DEC);
	void print(byte , unsigned long,byte =DEC);
	void print(byte , char *);
	void print(byte , double ,int = 3 );
	//Printing in new line 
	void println(byte ,char);
	void println(byte , long,byte = DEC);
	void println(byte , unsigned long,byte =DEC);
	void println(byte , char *);
	void println(byte , double , int = 3);
private:

};

#endif