#ifndef PatternShield_h
#define PatternShield_h

#define GET_PATTERN 0x01



class PatternShield
{
public:
	PatternShield();
	char* getPattern();
	char patternLength();

private:
	char *patternData;
	char Length;
	void processData();
	friend class OneSheeldClass;


};

extern PatternShield Pattern;
#endif