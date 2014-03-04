#ifndef TemperatureSensorShield_h
#define TemperatureSensorShield_h

#define TEMPERATURE_VALUE 0x01

class TemperatureSensorShield
{
public:
	TemperatureSensorShield();
	char getValue();
	void setOnChange(void (*userFunction)(char));
private:
	void processData();
	char value;
	bool callBack;
	void(*changeOnCallBack)(char);
	friend class OneSheeldClass;
};
extern TemperatureSensorShield TemperatureSensor;
#endif