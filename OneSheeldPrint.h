#ifndef PrintClass_h
#define PrintClass_h

#define DEC	  10

class PrintClass
{
public:
	PrintClass(byte, byte, byte);
	//Write
	void write(char);
	//Printing functions
	void print(char);
	void print(int,byte = DEC);
	void print(unsigned int,byte =DEC);
	void print(long,byte = DEC);
	void print(unsigned long,byte =DEC);
	void print(const char *);
	void print(double ,int = 3 );
	//Printing in new line 
	void println(char);
	void println(int,byte = DEC);
	void println(unsigned int,byte =DEC);
	void println(long,byte = DEC);
	void println(unsigned long,byte =DEC);
	void println(const char *);
	void println(double , int = 3);
private:
	byte print_fn_id;
	byte write_fn_id;
	byte shieldId;
};

#endif