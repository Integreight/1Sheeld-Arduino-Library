#ifndef LightSensorShield_h
#define LightSensorShield_h



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