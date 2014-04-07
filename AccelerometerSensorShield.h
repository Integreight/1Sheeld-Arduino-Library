#ifndef AccelerometerSensorShield_h
#define AccelerometerSensorShield_h

#define ACCELEROMETER_VALUE 0x01



class AccelerometerSensorShield
{
public:
	AccelerometerSensorShield();
	float getX();
	float getY();
	float getZ();
private:
	void processData();
	float valueX,valueY,valueZ;
	union float_test
	{
		byte data[4];
		float num;

	} getfloat;

friend class OneSheeldClass;
	
};

extern AccelerometerSensorShield AccelerometerSensor;
#endif