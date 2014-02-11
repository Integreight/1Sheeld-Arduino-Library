#ifndef AccelerometerSensorShield_h
#define AccelerometerSensorShield_h




class AccelerometerSensorShield
{
public:
	AccelerometerSensorShield();
	float getX_Axis();
	float getY_Axis();
	float getZ_Axis();
	void processData();
private:
	float valueX,valueY,valueZ;
	union float_test
	{
		byte data[4];
		float num;

	} getfloat;


	
};

extern AccelerometerSensorShield Accelerometer;
#endif