/*

  Project:       1Sheeld Library 
  File:          PatternShield.cpp
                 
  Version:       1.4

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.1

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "PatternShield.h"


//Constructor 
PatternShield::PatternShield() : ShieldParent(PATTERN_ID)
{
	isNewPattern =false;
	isCallBackAssigned = false;
	length=0;
	for(int i=0;i<MAX_PATTERN_SIZE;i++){
		nodes[i]=PatternNode();
	}
}

PatternNode * PatternShield::getLastPattern()
{
	isNewPattern = false;
	return nodes;
}

int PatternShield::getLastPatternLength()
{
	return length;
}

bool PatternShield::isNewPatternReceived()
{
	return isNewPattern;
}

void PatternShield::setOnNewPattern(void (* userFunction)(PatternNode patternNode[] ,int length))
{
	isCallBackAssigned = true;
	changeCallBack = userFunction;
}
//Process Input Data
void PatternShield::processData()
{
	byte functionID = getOneSheeldInstance().getFunctionId();

	if(functionID==PATTERN_VALUE)
	{
		isNewPattern=true;
		length = getOneSheeldInstance().getArgumentLength(0);
		if(length>MAX_PATTERN_SIZE)return;
		for (int i = 0; i < length; i++)
		{
			PatternNode node;
			node.setValue(getOneSheeldInstance().getArgumentData(0)[i]);
			nodes[i]=node;
		}

		if(isCallBackAssigned && !isInACallback())
		{
			enteringACallback();
			(*changeCallBack)(nodes,length);
			exitingACallback();
		}

	}

}

