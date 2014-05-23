#ifndef PushButtonShield_h
#define PushButtonShield_h

#define PUSHBUTTON_VALUE 0x01


class PushButtonShield
{
public:
	PushButtonShield();
	bool isPressed();
	void setOnButtonStatusChange(void (*userFunction)(bool ));
public:
	void processData();
	byte value;
	bool isCallBackAssigned;
	void (*changeCallBack)(bool);
	friend class OneSheeldClass;
	
};

extern PushButtonShield PushButton;
#endif