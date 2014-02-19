#ifndef GPSShield_h
#define GPSShield_h


class GPSShieldClass 
{
public:
	GPSShieldClass();
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