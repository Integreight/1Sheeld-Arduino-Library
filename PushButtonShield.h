#ifndef PushButtonShield_h
#define PushButtonShield_h




class PushButtonShield
{
public:
	PushButtonShield();
	byte getValue();
	void processData();
public:
	byte value;

	
};

extern PushButtonShield PushButton;
#endif