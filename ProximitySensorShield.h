#ifndef ProximitySensorShield_h
#define ProximitySensorShield_h

#define PROXIMITY_VALUE 0x01

class ProximitySensorShield
{
public:
	ProximitySensorShield();
	byte getValue();
	void setOnValueChange(void (*userFunction)(byte));
private:
	void processData();
	byte value;
	void (* changeCallBack)(byte);
	bool isCallBackAssigned;
	friend class OneSheeldClass;
};

extern ProximitySensorShield ProximitySensor;

#endif