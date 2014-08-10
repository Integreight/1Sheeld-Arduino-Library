#include "OneSheeld.h"
#include "PatternShield.h"




PatternShield::PatternShield()
{
	Length=0;
}

char * PatternShield::getPattern()
{
	return patternData;
}

char PatternShield::patternLength()
{
	return Length;
}

void PatternShield::processData()
{
	byte functioId = OneSheeld.getFunctionId();
	if(functioId == GET_PATTERN)
	{
		if (patternData!=0)
		{
			free(patternData);
		}
		Length=OneSheeld.getArgumentLength(0);
		patternData = (char*)malloc(sizeof(char)*(Length+1));
		for (int j=0; j<Length; j++)
		{
			patternData[j]=OneSheeld.getArgumentData(0)[j];
		}
		patternData[Length]='\0';
	}
}


PatternShield Pattern;