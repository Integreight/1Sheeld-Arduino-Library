#ifndef KeypadShield_h
#define KeypadShield_h



#define DATA_IN 0x01


class KeypadShieldClass 
{
public:
KeypadShieldClass();
bool isRowPressed(byte x);
bool isColumnPressed(byte x);
void setOnButtonChange(void (*)(byte ,byte));
bool isAnyRowPressed();
bool isAnyColumnPressed();

private:
void processData();
byte  row;
byte col;
void (*buttonChangeCallback)(byte , byte);
 
bool isCallbackAssigned;
friend class OneSheeldClass;
};
// instantiate object for users
extern KeypadShieldClass Keypad;

#endif