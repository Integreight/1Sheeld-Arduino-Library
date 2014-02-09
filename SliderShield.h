#ifndef SliderShield_h
#define SliderShield_h


class SliderShield
{
public:
	SliderShield();
	byte getValue();
	void processData();
private:
byte value;



};

extern SliderShield Slider;
#endif
