/*

  Project:       1Sheeld Library 
  File:          ShieldsSelection.h
                 
  Version:       1.4

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.4

*/

#define ANY_SHIELD_DEFINED \
(defined(INCLUDE_KEYPAD_SHIELD) || \
defined(INCLUDE_GPS_SHIELD) || \
defined(INCLUDE_SLIDER_SHIELD) || \
defined(INCLUDE_PUSH_BUTTON_SHIELD) || \
defined(INCLUDE_TOGGLE_BUTTON_SHIELD) || \
defined(INCLUDE_GAMEPAD_SHIELD) || \
defined(INCLUDE_PROXIMITY_SENSOR_SHIELD) || \
defined(INCLUDE_MIC_SHIELD) || \
defined(INCLUDE_TEMPERATURE_SENSOR_SHIELD) || \
defined(INCLUDE_LIGHT_SENSOR_SHIELD) || \
defined(INCLUDE_PRESSURE_SENSOR_SHIELD) || \
defined(INCLUDE_GRAVITY_SENSOR_SHIELD) || \
defined(INCLUDE_ACCELEROMETER_SENSOR_SHIELD) || \
defined(INCLUDE_GYROSCOPE_SENSOR_SHIELD) || \
defined(INCLUDE_ORIENTATION_SENSOR_SHIELD) || \
defined(INCLUDE_MAGNETOMETER_SENSOR_SHIELD) || \
defined(INCLUDE_PHONE_SHIELD) || \
defined(INCLUDE_SMS_SHIELD) || \
defined(INCLUDE_CLOCK_SHIELD) || \
defined(INCLUDE_KEYBOARD_SHIELD) || \
defined(INCLUDE_TWITTER_SHIELD) || \
defined(INCLUDE_VOICE_RECOGNIZER_SHIELD) || \
defined(INCLUDE_TERMINAL_SHIELD) || \
defined(INCLUDE_FACEBOOK_SHIELD) || \
defined(INCLUDE_NOTIFICATION_SHIELD) || \
defined(INCLUDE_SEVEN_SEGMENT_SHIELD) || \
defined(INCLUDE_SKYPE_SHIELD) || \
defined(INCLUDE_MUSIC_PLAYER_SHIELD) || \
defined(INCLUDE_EMAIL_SHIELD) || \
defined(INCLUDE_FOURSQUARE_SHIELD) || \
defined(INCLUDE_CAMERA_SHIELD) || \
defined(INCLUDE_BUZZER_SHIELD) || \
defined(INCLUDE_LED_SHIELD) || \
defined(INCLUDE_LCD_SHIELD) || \
defined(INCLUDE_TEXT_TO_SPEECH_SHIELD) || \
defined(INCLUDE_DATA_LOGGER_SHIELD) || \
defined(INCLUDE_PATTERN_SHIELD) || \
defined(INCLUDE_INTERNET_SHIELD) || \
defined(INCLUDE_COLOR_DETECTOR_SHIELD) || \
defined(INCLUDE_NFC_SHIELD) || \
defined(INCLUDE_GLCD_SHIELD) || \
defined(INCLUDE_VIBRATION_SHIELD) || \
defined(INCLUDE_BARCODE_SCANNER_SHIELD)|| \
defined(INCLUDE_FINGERPRINT_SCANNER_SHIELD) ||\
defined(INCLUDE_FACE_DETECTOR_SHIELD) ||\
defined(INCLUDE_CHART_SHIELD) ||\
defined(INCLUDE_IOT_SHIELD))

#if !defined(FROM_ONESHEELD_LIBRARY) 
	#if (defined(INCLUDE_ALL_SHIELDS) && defined(CUSTOM_SETTINGS)) || (!defined(CUSTOM_SETTINGS) && !ANY_SHIELD_DEFINED)
		#include "IncludedShieldsDefines.h"
		#define ALL_SHIELDS_INCLUDED
	#endif
#endif 

#if (ANY_SHIELD_DEFINED && defined(CUSTOM_SETTINGS)) || defined(ALL_SHIELDS_INCLUDED)
	#define EXTERN
#else
    #define EXTERN extern
#endif