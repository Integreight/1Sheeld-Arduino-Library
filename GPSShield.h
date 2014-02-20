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
	float radian(float);
private:
	void processData ();
	float LatValue,LonValue;
	bool isInit;
	union float_test
	{
		byte data[4];
		float num;

	} getfloat;
	friend class OneSheeldClass;

};

extern GPSShieldClass GPS;
#endif 