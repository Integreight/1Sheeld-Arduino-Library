#ifndef SevenSegmentShield_h
#define SevenSegmentShield_h 
#define SET_VALUE 0x01 
#define SET_DOT	0x02

class SevenSegmentShieldClass
{

public:
	void setNumber(byte );
	void setValue(byte  );
	void setDot();


private:
	

};

extern SevenSegmentShieldClass SevenSegment;
#endif
