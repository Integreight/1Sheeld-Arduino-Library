#ifndef PushButtonShield_h
#define PushButtonShield_h




class PushButtonShield
{
public:
	PushButtonShield();
	byte getValue();
	void processData();
	void setOnChange(void (*userFunction)(byte));
public:
	byte value;
	bool callBack;
	void (*changeCallBack)(byte);

	
};

extern PushButtonShield PushButton;
#endif