#ifndef OrientationSensorShield_h
#define OrientationSensorShield_h




class OrientationSensorShield
{
public:
	OrientationSensorShield();
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
extern OrientationSensorShield Orientation;
#endif 