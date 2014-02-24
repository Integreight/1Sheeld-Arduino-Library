#ifndef KeypadShield_h
#define KeypadShield_h



#define DATA_IN 0x01


class KeypadShieldClass 
{
public:
KeypadShieldClass();
bool isRowPressed(byte x);
bool isColumnPressed(byte x);
void setOnButtonChange(void (*userFunction)(int,int));
void processData();

private:

byte row;
byte col;
void (*buttonChangeCallback)(int,int);
 
bool isCallbackAssigned;
};
// instantiate object for users
extern KeypadShieldClass Keypad;

#endif