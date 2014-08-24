#include "OneSheeld.h"
#include "GraphShield.h"



//Log Data
void GraphShield::add(const char * key,float value)
{
	OneSheeld.sendPacket(GRAPH_ID,0,GRAPH_ADD_FLOAT,2,new FunctionArg(strlen(key),(byte *)key),new FunctionArg(sizeof(float),(byte*)OneSheeld.convertFloat(value)));
}

void GraphShield::plot()
{
	OneSheeld.sendPacket(GRAPH_ID,0,PLOT,0);
}

//Reset 
void GraphShield::reset()
{
	OneSheeld.sendPacket(GRAPH_ID,0,RESET,0);
}
GraphShield Graph;