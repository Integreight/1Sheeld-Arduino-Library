#ifndef PressureSensorShield_h
#define PressureSensorShield_h

#define PRESSURE_VALUE 0x01

class PressureSensorShield
{
public:
	PressureSensorShield();
	unsigned long getValue();
	void setOnValueChange(void (*)(unsigned  long));
private:
	void processData();
	void (*changeCallBack)(unsigned long);
	bool isCallBackAssigned;
	unsigned long value;
	unsigned long data[2];
	friend class OneSheeldClass;


};

extern PressureSensorShield PressureSensor;
#endif  