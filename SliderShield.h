#ifndef SliderShield_h
#define SliderShield_h

#define SLIDER_VALUE 0x01

class SliderShield
{
public:
	SliderShield();
	byte getValue();
	void setOnValueChange(void (*userFunction)(byte));
private:
	void processData();
	byte value;	
	bool isCallBackAssigned;
	void(*changeCallBack)(byte);
	friend class OneSheeldClass;



};

extern SliderShield Slider;
#endif
