#ifndef MicShield_h
#define MicShield_h



class MicShield
{
public:
	MicShield();
	byte getValue();
	void processData();
	void setOnChange(void (*userFunction)(byte));
private:
	byte value;
	bool callBack;
	void (*changeCallBack)(byte);
};
extern MicShield Mic;
#endif