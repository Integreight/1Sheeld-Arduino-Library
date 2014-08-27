/*

  Project:       1Sheeld Library 
  File:          OneSheeld.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef OneSheeld_h
#define OneSheeld_h
#include "Stream.h"

#define ARDUINO_GALILEO (defined(ARDUINO_LINUX) && (PLATFORM_ID==0x06 || PLATFORM_ID==0x03))
typedef unsigned char byte;

//Inlcuding Shields Headers
#include "TwitterShield.h"
#include "FacebookShield.h"
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
#include "KeyboardShield.h"
#include "TTSShield.h"
#include "VoiceRecognitionShield.h"
#include "DataLoggerShield.h"
#include "TerminalShield.h"
#include "InternetShield.h"
#include "PatternShield.h"
#include "GraphShield.h"

//Shields ID's
#define SLIDER_ID 		 	 0x01
#define LED_ID 		 	 	 0x02
#define PUSH_BUTTON_ID 	 	 0x03
#define TOGGLE_BUTTON_ID 	 0x04
#define FLASH_ID			 0x05
#define NOTIFICATION_ID 	 0x06
#define SEV_SEG_ID 			 0x07
#define BUZZER_ID 		 	 0x08
#define KEYPAD_SHIELD_ID	 0x09
#define MAGNETOMETER_ID  	 0x0A
#define ACCELEROMETER_ID 	 0x0B
#define GAMEPAD_ID 			 0x0C
#define SMS_ID 				 0x0D
#define GYROSCOPE_ID		 0x0E
#define ORIENTATION_ID		 0x0F
#define LIGHT_ID 			 0x10
#define PRESSURE_ID			 0x11
#define TEMPERATURE_ID		 0x12
#define PROXIMITY_ID	 	 0x13
#define GRAVITY_ID 			 0x14
#define CAMERA_ID 		 	 0x15
#define LCD_ID 		   	 	 0x17
#define MIC_ID 				 0x18
#define FACEBOOK_ID     	 0x19
#define TWITTER_ID      	 0x1A
#define FOURSQUARE_ID 	 	 0x1B
#define GPS_ID 				 0x1C
#define MUSIC_PLAYER_ID  	 0x1D
#define EMAIL_ID 		  	 0x1E
#define SKYPE_ID 			 0x1F
#define PHONE_ID 			 0x20
#define CLOCK_ID		 	 0x21
#define KEYBOARD_ID			 0x22
#define TTS_ID				 0x23
#define VOICE_RECOGNITION_ID 0x24
#define DATA_LOGGER_ID	  	 0x25
#define TERMINAL_ID			 0x26
#define INTERNET_ID			 0x27
#define PATTERN_ID			 0x28
#define GRAPH_ID			 0x29
#define ONE_SECOND 1000

//Start and End of packet sent
#define START_OF_FRAME  0xFF
#define END_OF_FRAME 	0x00
//Library Version
#define LIBRARY_VERSION 2
//Time between sending Frames
#define TIME_GAP		200UL

//#define DEBUG


//Class for Datalength and Data
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

union FloatUnion{
	    float number;
	    byte floatBytes[sizeof(float)];
	  };

class OneSheeldClass
{


public:
    
	OneSheeldClass(Stream &s);
	//Getters 
	byte getShieldId();
	byte getInstanceId();
	byte getFunctionId();
	byte getArgumentNo();
	byte getArgumentLength(byte );
	byte * getArgumentData(byte );
	byte *convertFloat(float );
	//Processing Incomming Frames
	void processInput();		
	//Library Starter
	void begin();
	//Frame Sender
	void sendPacket(byte shieldID, byte instanceID,byte functionCommand, byte argNo, ...);
	#if !ARDUINO_GALILEO
	//PulseWidthModulation Getter 
	unsigned char analogRead(int );
	#endif
	Stream & OneSheeldSerial;
private:
	//Reserve Variables
	FloatUnion convertFloatUnion;
	bool isArgumentsNumberMalloced;
	bool isArgumentLengthMalloced;
	byte numberOfDataMalloced;
	byte shield;
	byte instance;
	byte functions;
	byte counter;
	byte argumentcounter;
	byte datalengthcounter;
	byte argumentnumber;
	byte **arguments;	
	byte *argumentL;            
	bool framestart;
	byte endFrame;
	unsigned long lastTimeFrameSent;
	bool isFirstFrame;
	//Send Incomming Data to shields
	void sendToShields();
	void begin(long baudRate);
	void freeMemoryAllocated();
};
//Extern Object
extern OneSheeldClass OneSheeld;
#endif