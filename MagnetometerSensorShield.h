#ifndef MagnetometerSensorShield_h
#define MagnetometerSensorShield_h

#define MAGNETOMETER_VALUE 0x01




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