
#ifndef KEYBOARD_H_
#define KEYBOARD_H_

#define GET_CHAR	0x01




class KeyboardShield
{
public:
	KeyboardShield();
	char getCharacter();
	void setOnButtonChange(void (*)());
private:
	void processData();
	void (*buttonChangeCallBack)();
	bool isCallBackAssigned;
	char character;

	friend class OneSheeldClass ;


};

extern KeyboardShield AsciiKeyboard;
#endif

