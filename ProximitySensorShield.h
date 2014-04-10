#ifndef ProximitySensorShield_h
#define ProximitySensorShield_h

#define PROXIMITY_VALUE 0x01

class ProximitySensorShield
{
public:
	ProximitySensorShield();
	byte getValue();
	void setOnChange(void (*userFunction)());
private:
	void processData();
	byte value;
	void (* changeCallBack)();
	bool isCallBackAssigned;
	friend class OneSheeldClass;
};

extern ProximitySensorShield ProximitySensor;

#endif