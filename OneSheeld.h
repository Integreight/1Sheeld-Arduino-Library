/*
  OneSheeld.h - OneSheeld library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#ifndef OneSheeld_h
#define OneSheeld_h

#include "TwitterShield.h"
#include "FacebookShield.h"
#include "LiquidCrystalShield.h"
#include "AccelerometerShield.h"
#include "ReadPWMClass.h"
#include "KeypadShield.h"
#include "NotificationShield.h"
#include "SMSShield.h"
#include "PhoneShield.h"

// shield ids
#define TWITTER_ID       0x30 
#define FACEBOOK_ID      0x31 
#define LCD_SHIELD_ID    0x32
#define KEYPAD_SHIELD_ID 0x33
#define NOTIFICATION_ID  0x34 
#define ACCELEROMETER_ID 0x35
#define SMS_ID 0x36
#define GAMEPAD_ID 0x37
#define PHONE_ID 0x38

#define PACKET_SIZE 6

// start and end of the packet sent
#define STX 0x02
#define ETX 0x03
// for general data sending
#define GENERAL_DATA 0x29
#define NOT_FUNCTION 0x00

class OneSheeldClass
{
public:
    OneSheeldClass();
    void begin(long baudRate);
    void write(char shieldID, char functionCommand, char *data);
    void write(char *data);
    void write(char shieldID, char functionCommand, char *data, int length);
    void onSerialEvent(char);

private:
int count;
char readPacket[PACKET_SIZE];
int frameStart;
void sendToShields();

};
// instantiate object for users
extern OneSheeldClass OneSheeld;
#endif