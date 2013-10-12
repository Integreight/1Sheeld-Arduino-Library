#ifndef KeypadShield_h
#define KeypadShield_h


// function commands
#define INIT 0x06
#define GET_ROW 0x02
#define GET_COL 0x03
#define SET_ON_CHANGE 0x04
#define GET_NUM 0x05
#define DATA_IN 0x01


class KeypadShieldClass 
{
public:
KeypadShieldClass();
void init();
int getRow();
int getCol();
int getButton();
void setOnButtonChange(void (*userFunction)(int,int));
void processData(char *);

private:

int row;
int col;
void (*buttonChangeCallback)(int,int);
 
bool isCallbackAssigned;
};
// instantiate object for users
extern KeypadShieldClass Keypad;

#endif