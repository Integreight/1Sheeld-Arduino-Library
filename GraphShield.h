#ifndef GraphShield_h
#define GraphShield_h

#define ADD_FLOAT	0x01
#define ADD_NUM		0x02
#define PLOT 		0x03
#define RESET 		0x04


class GraphShield
{
public:
	
	void add(char * ,float,int);
	void reset();
	void plot();
private:

};

extern GraphShield Graph;
#endif