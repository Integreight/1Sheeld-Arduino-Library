#ifndef MicShield_h
#define MicShield_h

#define MIC_VALUE 0x01

class MicShield
{
public:
	MicShield();
	byte getValue();
	void setOnChange(void (*)(byte));
private:
	void processData();
	void (*changeCallBack)(byte);
	byte value;
	bool isCallBackAssigned;
	friend class OneSheeldClass;
};
extern MicShield Mic;
#endif