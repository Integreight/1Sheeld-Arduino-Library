#ifndef KeypadShield_h
#define KeypadShield_h

// shield id
#define KEYPAD_SHIELD_ID     0x33
// function commands
#define INIT 0x06
#define GET_ROW 0x02
#define GET_COL 0x03
#define SET_ON_CHANGE 0x04
#define GET_NUM 0x05
#define DATA_IN 0x01
#define PACKET_SIZE 6

class KeypadShieldClass 
{
public:
KeypadShieldClass();
void init();
int getRow();
int getCol();
int getButton();
void onSerialEvent(char);



private:

int row;
int col;
int count;
char readPacket[PACKET_SIZE];
int frameStart;
void processData();
};
// instantiate object for users
extern KeypadShieldClass Keypad;

#endif