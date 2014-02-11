#ifndef GravitySensorShield_h
#define GravitySensorShield_h




class GravitySensorShield
{
public:
	GravitySensorShield();
	float getX_Axis();
	float getY_Axis();
	float getZ_Axis();
	void processData();
private:
	float valueX ,valueY,valueZ;
	int x,y;
	union float_test
	{
		byte data[4];
		float num;

	} getfloat;

	
};
extern GravitySensorShield Gravity;
#endif 