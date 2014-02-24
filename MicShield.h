#ifndef MicShield_h
#define MicShield_h

#define MIC_VALUE 0x01

class MicShield
{
public:
	MicShield();
	byte getValue();
	void setOnChange(void (*userFunction)(byte));
private:
	void processData();
	byte value;
	bool callBack;
	void (*changeCallBack)(byte);
	friend class OneSheeldClass;
};
extern MicShield Mic;
#endif