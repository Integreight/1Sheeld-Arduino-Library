#ifndef LightSensorShield_h
#define LightSensorShield_h



class LightSensorShield
{
public:
	LightSensorShield();
	unsigned long getValue();
	void processData();
private:
	unsigned long value;
	 long data[3];

};

extern LightSensorShield Light;
#endif  