#include "OneSheeld.h"
#include "GraphShield.h"



//Log Data
void GraphShield::add(char * key,float value,int decimalAfterPoint =0)
{
	char floattostring[10]={0};
	dtostrf(value,10,decimalAfterPoint,floattostring);

	OneSheeld.sendPacket(GRAPH_ID,0,GRAPH_ADD_FLOAT,2,new FunctionArg(strlen(key),(byte *)key),new FunctionArg(10,(byte*)floattostring));
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