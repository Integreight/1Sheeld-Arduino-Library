#ifndef SkypeShield_h
#define SkypeShield_h

#define CALL 0x01
#define VIDEO_CALL 0x02

class SkypeShieldClass 
{
private:
	
public:
	SkypeShieldClass();
	void call(char *username);
	void videoCall(char *username);

};

extern SkypeShieldClass Skype;
#endif