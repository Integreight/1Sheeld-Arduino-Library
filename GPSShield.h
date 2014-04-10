#ifndef GPSShield_h
#define GPSShield_h
#include <math.h>


#define RADUIS_OF_EARTH 6371
#define PI 3.1415926535897932384626433832795
#define GPS_VALUE 0x01




class GPSShieldClass 
{
public:
	GPSShieldClass();
	float getLattitude();
	float getLongitude();
	bool isInRange(float , float , float );
	float getDistance(float  , float );
	float radian(float);
	void setOnChange(void (*)());
private:
	void processData ();
	void (*changeCallBack)();
	float LatValue,LonValue;
	bool isInit;
	bool isCallBackAssigned;
	union float_test
	{
		byte data[4];
		float num;

	} getfloat;
	friend class OneSheeldClass;

};

extern GPSShieldClass GPS;
#endif 