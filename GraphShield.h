/*

  Project:       1Sheeld Library 
  File:          GraphShield.h
                 
  Version:       3.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.8

*/

#ifndef GraphShield_h
#define GraphShield_h

#define GRAPH_ADD_FLOAT	0x01
#define GRAPH_PLOT 		0x02
#define GRAPH_RESET 		0x03


class GraphShield
{
public:
	
	void add(const char * ,float);
	void reset();
	void plot();
private:

};

extern GraphShield Graph;
#endif