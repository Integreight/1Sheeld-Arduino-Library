#ifndef LightSensorShield_h
#define LightSensorShield_h

#define LIGHT_VALUE 0x01

class LightSensorShield
{
public:
	LightSensorShield();
	unsigned long getValue();
	void setOnChange(void (*)(unsigned long));
private:
	void processData();
	void (*changeCallBack)(unsigned long);
	bool isCallBackAssigned;
	union float_test
	{
		byte data[4];
		unsigned long num;

	} getfloat;
	unsigned long value;
	 friend class OneSheeldClass;

};

extern LightSensorShield LightSensor;
#endif  