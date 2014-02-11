#ifndef MagnetometerSensorShield_h
#define MagnetometerSensorShield_h




class MagnetometerSensorShield
{
public:
	MagnetometerSensorShield();
	float getX_Axis();
	float getY_Axis();
	float getZ_Axis();
	void processData();
private:
	float valueX ,valueY,valueZ;
	union float_test
	{
		byte data[4];
		float num;

	} getfloat;

	
};
extern MagnetometerSensorShield Magnet;
#endif 