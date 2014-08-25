/*

  Project:       1Sheeld Library 
  File:          GraphShield.cpp
                 
  Version:       3.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.8

*/

#include "OneSheeld.h"
#include "GraphShield.h"



//Log Data
void GraphShield::add(const char * key,float value)
{
	OneSheeld.sendPacket(GRAPH_ID,0,GRAPH_ADD_FLOAT,2,new FunctionArg(strlen(key),(byte *)key),new FunctionArg(sizeof(float),(byte*)OneSheeld.convertFloat(value)));
}

void GraphShield::plot()
{
	OneSheeld.sendPacket(GRAPH_ID,0,GRAPH_PLOT,0);
}

//Reset 
void GraphShield::reset()
{
	OneSheeld.sendPacket(GRAPH_ID,0,GRAPH_RESET,0);
}
GraphShield Graph;