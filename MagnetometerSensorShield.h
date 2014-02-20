#ifndef MagnetometerSensorShield_h
#define MagnetometerSensorShield_h




class MagnetometerSensorShield
{
public:
	MagnetometerSensorShield();
	float getX();
	float getY();
	float getZ();
private:
	void processData();
	float valueX ,valueY,valueZ;
	union float_test
	{
		byte data[4];
		float num;

	} getfloat;
	friend class OneSheeldClass;

	
};
extern MagnetometerSensorShield Magnetometer;
#endif 