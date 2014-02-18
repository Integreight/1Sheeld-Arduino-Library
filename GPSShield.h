#ifndef GPSShield_h
#define GPSShield_h


class GPSCoordinate {

public:

GPSCoordinate (char deg,char min ,char sec,char side);
char getDegree();
char getMinutes();
char getSeconds();
char getCharacter();


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
	float getLattitude();
	float getLongitude();
	bool isLongitude();
	bool isLatitude();
	void Proc ();
	
private:
	char Long[4],Latt[4];
	float LatValue,LonValue;
	union float_test
	{
		byte data[4];
		float num;

	} getfloat;

};

extern GPSShieldClass GPS;
#endif 