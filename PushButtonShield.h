#ifndef PushButtonShield_h
#define PushButtonShield_h

#define PUSHBUTTON_VALUE 0x01


class PushButtonShield
{
public:
	PushButtonShield();
	byte getValue();
	void setOnChange(void (*userFunction)());
public:
	void processData();
	byte value;
	bool isCallBackAssigned;
	void (*changeCallBack)();
	friend class OneSheeldClass;
	
};

extern PushButtonShield PushButton;
#endif