#ifndef SliderShield_h
#define SliderShield_h


class SliderShield
{
public:
	SliderShield();
	byte getValue();
	void setOnChange(void (*userFunction)(byte));
private:
	void processData();
	byte value;	
	bool callBack;
	void(*changeCallBack)(byte);
	friend class OneSheeldClass;



};

extern SliderShield Slider;
#endif
