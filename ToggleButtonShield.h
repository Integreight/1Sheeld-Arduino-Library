#ifndef ToggleButtonShield_h
#define ToggleButtonShield_h



class ToggleButtonShield
{
public:
	ToggleButtonShield();
	byte getValue();
	void processData();
private:
	byte value;
};

extern ToggleButtonShield ToggleButton;
#endif