#ifndef GPSShield_h
#define GPSShield_h


class GPSCoordinate {

public:

GPSCoordinate (char deg,char min ,char sec,char side);
char getDeg();
char getMin();
char getSec();
char getChar();


private:
	unsigned char degree;
	unsigned char minutes;
	unsigned char seconds;
	unsigned char type;

};

class GPSShieldClass 
{
public:
	GPSShieldClass();
	GPSCoordinate getLat();
	GPSCoordinate getLon();
	bool isLongitude();
	bool isLatitude();
	void Proc ();
	
private:
	char Long[4],Latt[4];
	

};

extern GPSShieldClass GPS;
#endif 