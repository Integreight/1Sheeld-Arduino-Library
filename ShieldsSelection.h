/*

  Project:       1Sheeld Library 
  File:          ShieldsSelection.h
                 
  Version:       1.4

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.4

*/

#define ANY_SHIELD_DEFINED \
(defined(KEYPAD_SHIELD) || \
defined(GPS_SHIELD) || \
defined(SLIDER_SHIELD) || \
defined(PUSH_BUTTON_SHIELD) || \
defined(TOGGLE_BUTTON_SHIELD) || \
defined(GAMEPAD_SHIELD) || \
defined(PROXIMITY_SHIELD) || \
defined(MIC_SHIELD) || \
defined(TEMPERATURE_SHIELD) || \
defined(LIGHT_SHIELD) || \
defined(PRESSURE_SHIELD) || \
defined(GRAVITY_SHIELD) || \
defined(ACCELEROMETER_SHIELD) || \
defined(GYROSCOPE_SHIELD) || \
defined(ORIENTATION_SHIELD) || \
defined(MAGNETOMETER_SHIELD) || \
defined(PHONE_SHIELD) || \
defined(SMS_SHIELD) || \
defined(CLOCK_SHIELD) || \
defined(KEYBOARD_SHIELD) || \
defined(TWITTER_SHIELD) || \
defined(VOICE_RECOGNITION_SHIELD) || \
defined(TERMINAL_SHIELD) || \
defined(FACEBOOK_SHIELD) || \
defined(NOTIFICATION_SHIELD) || \
defined(SEVEN_SEGMENT_SHIELD) || \
defined(SKYPE_SHIELD) || \
defined(MUSIC_PLAYER_SHIELD) || \
defined(EMAIL_SHIELD) || \
defined(FOURSQUARE_SHIELD) || \
defined(CAMERA_SHIELD) || \
defined(BUZZER_SHIELD) || \
defined(LED_SHIELD) || \
defined(LCD_SHIELD) || \
defined(TEXTTOSPEECH_SHIELD) || \
defined(DATA_LOGGER_SHIELD) || \
defined(REMOTE_SHIELD) || \
defined(PATTERN_SHIELD) || \
defined(INTERNET_SHIELD))

#if !defined(FROM_ONESHEELD_LIBRARY) 
	#if (defined(ALL_SHIELDS) && defined(CUSTOM_OPTIONS)) || (!defined(CUSTOM_OPTIONS) && !ANY_SHIELD_DEFINED)
		#include "IncludedShieldsDefines.h"
		#define ALL_SHIELDS_INCLUDED
	#endif
#endif 

#if (ANY_SHIELD_DEFINED && defined(CUSTOM_OPTIONS)) || defined(ALL_SHIELDS_INCLUDED)
	#define EXTERN
#else
    #define EXTERN extern
#endif