#ifndef ProximitySensorShield_h
#define ProximitySensorShield_h



class ProximitySensorShield
{
public:
	ProximitySensorShield();
	byte getValue();
	void setOnChange(void (*userFunction)(byte));
private:
	void processData();
	byte value;
	void (* changeCallBack)(byte);
	bool callBack;
	friend class OneSheeldClass;
};

extern ProximitySensorShield ProximitySensor;

#endif