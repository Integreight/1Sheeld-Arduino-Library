/*
  OneSheeld.h - OneSheeld library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#ifndef OneSheeld_h
#define OneSheeld_h
#include "Stream.h"

typedef unsigned char byte;

#include "TwitterShield.h"
#include "FacebookShield.h"
#include "ReadPWMClass.h"
#include "KeypadShield.h"
#include "NotificationShield.h"
#include "SMSShield.h"
#include "PhoneShield.h"
#include "GPSShield.h"
#include "SevenSegmentShield.h"
#include "SkypeShield.h"
#include "MusicPlayerShield.h"
#include "EmailShield.h"
#include "FoursquareShield.h"
#include "CameraShield.h"
#include "BuzzerShield.h"
#include "LedShield.h"
#include "SliderShield.h"
#include "PushButtonShield.h"
#include "ToggleButtonShield.h"
#include "GamePadShield.h"
#include "FlashLightShield.h"
#include "ProximitySensorShield.h"
#include "MicShield.h"
#include "TemperatureSensorShield.h"
#include "LightSensorShield.h"
#include "PressureSensorShield.h"
#include "GravitySensorShield.h"
#include "AccelerometerSensorShield.h"
#include "GyroscopeSensorShield.h"
#include "OrientationSensorShield.h"
#include "MagnetometerSensorShield.h"
#include "LCDShield.h"
#include "ClockShield.h"

// shield ids
#define TWITTER_ID      	 0x1A 
#define FACEBOOK_ID     	 0x19 
#define LCD_ID 		   	 	 0x17
#define KEYPAD_SHIELD_ID	 0x09
#define NOTIFICATION_ID 	 0x06
#define ACCELEROMETER_ID 	 0x0B
#define SMS_ID 				 0x0D
#define GAMEPAD_ID 			 0x0C
#define PHONE_ID 			 0x20
#define GPS_ID 				 0x1C
#define SEV_SEG_ID 			 0x07
#define SKYPE_ID 			 0x1F
#define MUSIC_PLAYER_ID  	 0x1D
#define EMAIL_ID 		  	 0x1E
#define FOURSQUARE_ID 	 	 0x1B
#define CAMERA_ID 		 	 0x15
#define BUZZER_ID 		 	 0x08
#define LED_ID 		 	 	 0x02
#define SLIDER_ID 		 	 0x01
#define PUSH_BUTTON_ID 	 	 0x03
#define TOGGLE_BUTTON_ID 	 0x04
#define FLASH_ID			 0x05
#define PROXIMITY_ID	 	 0x13
#define MIC_ID 				 0x18
#define TEMPERATURE_ID		 0x12
#define LIGHT_ID 			 0x10
#define PRESSURE_ID			 0x11
#define GRAVITY_ID 			 0x14
#define GYROSCOPE_ID		 0x0E
#define ORIENTATION_ID		 0x0F
#define MAGNETOMETER_ID  	 0x0A
#define CLOCK_ID		 	 0x21
// start and end of the packet sent
#define START_OF_FRAME  0xFF
#define END_OF_FRAME 	0x00
#define LIBRARY_VERSION 0x01

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
void sendToShields();
int frameStart;
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
byte endFrame;
void begin(long baudRate);
public:
    
OneSheeldClass(Stream &s);
//Functions of the reciever 
byte getShieldId();
byte getInstanceId();
byte getFunctionId();
byte getArgumentNo();
byte getArgumentLength(byte x);
byte * getArgumentData(byte x);
void processInput();					//new Reciever function 
void begin();
void sendPacket(byte shieldID, byte instanceID,byte functionCommand, byte argNo, ...);
Stream & OneSheeldSerial;
};
// instantiate object for users
extern OneSheeldClass OneSheeld;
#endif