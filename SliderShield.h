#ifndef SliderShield_h
#define SliderShield_h


class SliderShield
{
public:
	SliderShield();
	byte getValue();
	void processData();
	void setOnChange(void (*userFunction)(byte));
private:
byte value;
bool callBack;
void(*changeCallBack)(byte);



};

extern SliderShield Slider;
#endif
