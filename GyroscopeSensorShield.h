#ifndef GyroscopeSensorShield_h
#define GyroscopeSensorShield_h




class GyroscopeSensorShield
{
public:
	GyroscopeSensorShield();
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
extern GyroscopeSensorShield Gyroscope;
#endif 