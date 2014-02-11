#ifndef ProximityShield_h
#define ProximityShield_h



class ProximityShield
{
public:
	ProximityShield();
	byte getProx();
	void processData();
	void setOnChange(void (*userFunction)(byte));
private:
	byte value;
	void (* changeCallBack)(byte);
	bool callBack;
};

extern ProximityShield Prox;

#endif