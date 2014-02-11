#ifndef TemperatureShield_h
#define TemperatureShield_h

typedef signed char signedvalue;

class TemperatureShield
{
public:
	TemperatureShield();
	signedvalue getDegree();
	void processData();
	void setOnChange(void (*userFunction)(signedvalue));
private:
	signedvalue value;
	bool callBack;
	void(*changeOnCallBack)(signedvalue);

};
extern TemperatureShield Temp;
#endif