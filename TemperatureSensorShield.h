#ifndef TemperatureSensorShield_h
#define TemperatureSensorShield_h

#define TEMPERATURE_VALUE 0x01

class TemperatureSensorShield
{
public:
	TemperatureSensorShield();
	char getValue();
	void setOnChange(void (*)());
private:
	void processData();
	char value;
	bool isCallBackAssigned;
	void(*changeOnCallBack)();
	friend class OneSheeldClass;
};
extern TemperatureSensorShield TemperatureSensor;
#endif