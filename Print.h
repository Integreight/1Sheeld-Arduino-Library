#ifndef PrintClass_h
#define PrintClass_h

#define WRITE 0x01
#define PRINT 0x02
#define DEC	  10

class PrintClass
{
public:
	Print();
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

extern PrintClass Print;
#endif