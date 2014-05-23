#ifndef OrientationSensorShield_h
#define OrientationSensorShield_h


#define ORIENTATION_VALUE 0x01

class OrientationSensorShield
{
public:
	OrientationSensorShield();
	float getX();
	float getY();
	float getZ();
	void setOnValueChange(void (*)(float,float,float));
private:
	void processData();
	void (*changeCallBack)(float,float,float);
	bool isCallBackAssigned;
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