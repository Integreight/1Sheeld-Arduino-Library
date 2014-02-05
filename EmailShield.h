#ifndef EmailShield_h
#define EmailShield_h


#define SEND 0x01



class EmailShieldClass 
{
private:

public:
	EmailShieldClass();
	void send(char *username,char* message);
};

extern EmailShieldClass Email;
#endif