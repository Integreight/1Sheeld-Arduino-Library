#ifndef OrientationSensorShield_h
#define OrientationSensorShield_h




class OrientationSensorShield
{
public:
	OrientationSensorShield();
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
extern OrientationSensorShield OrientationSensor;
#endif 