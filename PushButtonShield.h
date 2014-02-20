#ifndef PushButtonShield_h
#define PushButtonShield_h




class PushButtonShield
{
public:
	PushButtonShield();
	byte getValue();
	void setOnChange(void (*userFunction)(byte));
public:
	void processData();
	byte value;
	bool callBack;
	void (*changeCallBack)(byte);
	friend class OneSheeldClass;
	
};

extern PushButtonShield PushButton;
#endif