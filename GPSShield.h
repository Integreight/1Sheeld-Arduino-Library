#ifndef GPSShield_h
#define GPSShield_h
#define R 6371


class GPSShieldClass 
{
public:
	GPSShieldClass();
	float getLattitude();
	float getLongitude();
	bool isInRange(float , float , float );
	float getDistance(float  , float );
	void Proc ();
	
private:
	float LatValue,LonValue;
	union float_test
	{
		byte data[4];
		float num;

	} getfloat;

};

extern GPSShieldClass GPS;
#endif 