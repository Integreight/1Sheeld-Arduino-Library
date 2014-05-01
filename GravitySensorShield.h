#ifndef GravitySensorShield_h
#define GravitySensorShield_h

#define GRAVITY_VALUE 0x01


class GravitySensorShield
{
public:
	GravitySensorShield();
	float getX();
	float getY();
	float getZ();
	void setOnChange(void (*)(float,float,float));
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
extern GravitySensorShield GravitySensor;
#endif 