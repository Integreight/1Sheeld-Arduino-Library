/*

  Project:       1Sheeld Library 
  File:          PatternShield.cpp
                 
  Version:       1.4

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/
#include "OneSheeld.h"
#include "PatternShield.h"


//Constructor 
PatternShield::PatternShield() : ShieldParent(PATTERN_ID)
{
	isCallBackAssigned = false;
	size=0;
	for(int i=0;i<MAX_PATTERN_SIZE;i++){
		nodes[i]=PatternNode(0);
	}
}

PatternNode * PatternShield::getLastPattern()
{
	isCallBackAssigned = false;
	return nodes;
}

int PatternShield::getLastPatternSize()
{
	return size;
}

bool PatternShield::isNewPatternReceived()
{
	return isNewPattern;
}

void PatternShield::setOnNewPattern(void (* userFunction)(PatternNode* patternNode ,int size))
{
	isCallBackAssigned = true;
	changeCallBack = userFunction;
}
//Process Input Data
void PatternShield::processData()
{
	byte functionID = OneSheeld.getFunctionId();

	if(functionID==PATTERN_VALUE)
	{
		isNewPattern=false;
		size = OneSheeld.getArgumentLength(0);
		if(size>MAX_PATTERN_SIZE)return;
		for (int i = 0; i < size; i++)
		{
			nodes[i]=PatternNode(OneSheeld.getArgumentData(0)[i]);
		}

		if(isCallBackAssigned)
		{
			(*changeCallBack)(nodes,size);
		}

	}

}

#ifdef PATTERN_SHIELD
//Instantiating object 
PatternShield Pattern;
#endif