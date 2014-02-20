#ifndef GyroscopeSensorShield_h
#define GyroscopeSensorShield_h




class GyroscopeSensorShield
{
public:
	GyroscopeSensorShield();
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
extern GyroscopeSensorShield Gyroscope;
#endif 