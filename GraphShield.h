#ifndef GraphShield_h
#define GraphShield_h

#define GRAPH_ADD_FLOAT	0x01
#define PLOT 		0x02
#define RESET 		0x03


class GraphShield
{
public:
	
	void add(char * ,float);
	void reset();
	void plot();
private:

};

extern GraphShield Graph;
#endif