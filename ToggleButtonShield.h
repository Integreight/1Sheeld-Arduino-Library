#ifndef ToggleButtonShield_h
#define ToggleButtonShield_h



class ToggleButtonShield
{
public:
	ToggleButtonShield();
	byte getValue();
	void setOnChange(void (*userFunction)(byte));
private:
	void processData();
	byte value;
	bool callBack;
	void (*changeCallBack)(byte);
	friend class OneSheeldClass;
};

extern ToggleButtonShield ToggleButton;
#endif