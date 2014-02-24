#ifndef LightSensorShield_h
#define LightSensorShield_h

#define LIGHT_VALUE 0x01

class LightSensorShield
{
public:
	LightSensorShield();
	unsigned long getValue();
private:
	void processData();
	unsigned long value;
	 long data[3];
	 friend class OneSheeldClass;

};

extern LightSensorShield LightSensor;
#endif  