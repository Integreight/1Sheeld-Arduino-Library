#ifndef SkypeShield_h
#define SkypeShield_h

#define CALL 		0x01
#define VIDEO_CALL  0x02
#define MESSAGE 	0x03
class SkypeShieldClass 
{
private:
	
public:
	void call(char *);
	void videoCall(char *);
};

extern SkypeShieldClass Skype;
#endif