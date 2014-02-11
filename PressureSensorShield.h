#ifndef PressureSensorShield_h
#define PressureSensorShield_h



class PressureSensorShield
{
public:
	PressureSensorShield();
	unsigned long getPressure();
	void processData();
private:
	unsigned long value;
	 long data[3];

};

extern PressureSensorShield Pressure;
#endif  