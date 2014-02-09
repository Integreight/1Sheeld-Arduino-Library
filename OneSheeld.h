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
#include "GPSShield.h"
#include "SevSegShield.h"
#include "SkypeShield.h"
#include "MusicPlayerShield.h"
#include "EmailShield.h"
#include "FoursquareShield.h"
#include "CameraShield.h"
#include "BuzzerShield.h"
#include "LedShield.h"
#include "SliderShield.h"
#include "Pushbuttonshield.h"
#include "ToggleButtonShield.h"
#include "GamePadShield.h"

// shield ids
#define TWITTER_ID       0x1A 
#define FACEBOOK_ID      0x19 
#define LCD_SHIELD_ID    0x17
#define KEYPAD_SHIELD_ID 0x09
#define NOTIFICATION_ID  0x06
#define ACCELEROMETER_ID 0x0B
#define SMS_ID 0x0D
#define GAMEPAD_ID 0x0C
#define PHONE_ID 0x20
#define GPS_ID 0x1C
#define SEV_SEG_ID 0x07
#define SLIDER_ID 0x01
#define SKYPE_ID 0x1F
#define MUSIC_PLAYER_ID 0x1D
#define EMAIL_ID 0x1E
#define FOURSQUARE_ID 0x1B
#define CAMERA_ID 0x15
#define BUZZER_ID 0x08
#define LED_ID 0x02
#define SLIDER_ID 0x01
#define PUSH_BUTTON 0x03
#define TOGGLE_BUTTON 0x04


#define PACKET_SIZE 12

// start and end of the packet sent
#define STX 0x02
#define ETX 0x03
#define START_OF_FRAME 0xFF
// for general data sending
#define GENERAL_DATA 0x29
#define NOT_FUNCTION 0x00

//new function for the new packet frame 

class FunctionArg
{
private:
	byte length;
	byte * data;
public:
	FunctionArg(int l ,byte * d)
	{
		length=(l>0xff)?0xff:l;
		data=d;
	}
	byte getLength()
	{
		return length;
	}
	byte * getData()
	{
		return data;
	}

};


class OneSheeldClass
{
	private:
int count;
char readPacket[PACKET_SIZE];
int frameStart;
void sendToShields();
byte shield;
byte Start;
byte instance;
byte functions;
byte counter;
byte argumentcounter;
byte datalengthcounter;
byte argumentnumber;
byte **arguments;				 //pointer to an array of 2d
byte *argumentL;            
byte framestart;

public:
    
OneSheeldClass();
  

  //Functions of the reciever 
byte getShieldId();
byte getInstanceId();
byte getFunctionId();
byte getArgumentNo();
byte getArgumentLength(byte x);
byte * getArgumentData(byte x);
void processInput();					//new Reciever function 
void begin(long baudRate);
void onSerialEvent(char);
void sendPacket(byte shieldID, byte instanceID,byte functionCommand, byte argNo, ...);
    //void write(char shieldID, char functionCommand, char *data);
    //void write(char *data);
   // void write(char shieldID, char functionCommand, char *data, int length); 

};
// instantiate object for users
extern OneSheeldClass OneSheeld;
#endif