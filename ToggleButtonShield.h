#ifndef ToggleButtonShield_h
#define ToggleButtonShield_h

#define TOGGLE_VALUE 0x01



class ToggleButtonShield
{
public:
	ToggleButtonShield();
	byte getValue();
	void setOnChange(void (*userFunction)());
private:
	void processData();
	byte value;
	bool isCallBackAssigned;
	void (*changeCallBack)();
	friend class OneSheeldClass;
};

extern ToggleButtonShield ToggleButton;
#endif