/*

  Project:       1Sheeld Library 
  File:          ShieldsInstantiation.h
                 
  Version:       1.4

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.4

*/

#ifdef BUZZER_SHIELD
EXTERN BuzzerShieldClass Buzzer;
#endif

#ifdef ACCELEROMETER_SHIELD
EXTERN AccelerometerSensorShield AccelerometerSensor;	
#endif

#ifdef CAMERA_SHIELD
EXTERN CameraShieldClass Camera;
#endif

#ifdef CLOCK_SHIELD
EXTERN ClockShield Clock;
#endif

#ifdef DATA_LOGGER_SHIELD
EXTERN DataLoggerShield Logger;
#endif

#ifdef EMAIL_SHIELD
EXTERN EmailShieldClass Email;
#endif

#ifdef FACEBOOK_SHIELD
EXTERN FacebookShieldClass Facebook;
#endif

#ifdef FOURSQUARE_SHIELD
EXTERN FoursquareShieldClass Foursquare;
#endif

#ifdef GAMEPAD_SHIELD
EXTERN GamePadShield GamePad;
#endif

#ifdef GPS_SHIELD
EXTERN GPSShieldClass  GPS;
#endif

#ifdef GRAVITY_SHIELD
EXTERN GravitySensorShield GravitySensor;
#endif

#ifdef GYROSCOPE_SHIELD
EXTERN GyroscopeSensorShield GyroscopeSensor;
#endif

#ifdef INTERNET_SHIELD
EXTERN InternetShield Internet;
#endif

#ifdef KEYBOARD_SHIELD
EXTERN KeyboardShield AsciiKeyboard;
#endif

#ifdef KEYPAD_SHIELD
EXTERN KeypadShieldClass Keypad;
#endif

#ifdef LCD_SHIELD
EXTERN LCDShield LCD;
#endif

#ifdef LED_SHIELD
EXTERN LedShield LED;
#endif

#ifdef LIGHT_SHIELD
EXTERN LightSensorShield LightSensor;
#endif

#ifdef MAGNETOMETER_SHIELD
EXTERN MagnetometerSensorShield MagnetometerSensor;
#endif

#ifdef MIC_SHIELD
EXTERN MicShield Mic;
#endif

#ifdef MUSIC_PLAYER_SHIELD
EXTERN MusicPlayerShieldClass MusicPlayer;
#endif

#ifdef NOTIFICATION_SHIELD
EXTERN NotificationShieldClass Notification;
#endif

#ifdef ORIENTATION_SHIELD
EXTERN OrientationSensorShield OrientationSensor;
#endif

#ifdef PATTERN_SHIELD
EXTERN PatternShield Pattern;
#endif

#ifdef PHONE_SHIELD
EXTERN PhoneShieldClass Phone;
#endif

#ifdef PRESSURE_SHIELD
EXTERN PressureSensorShield PressureSensor;
#endif

#ifdef PROXIMITY_SHIELD
EXTERN ProximitySensorShield ProximitySensor;
#endif

#ifdef PUSH_BUTTON_SHIELD
EXTERN PushButtonShield PushButton;
#endif

#ifdef SEVEN_SEGMENT_SHIELD
EXTERN SevenSegmentShieldClass SevenSegment;
#endif

#ifdef SKYPE_SHIELD
EXTERN SkypeShieldClass Skype;
#endif

#ifdef SLIDER_SHIELD
EXTERN SliderShield Slider;
#endif

#ifdef SMS_SHIELD
EXTERN SMSShieldClass SMS;
#endif

#ifdef TEMPERATURE_SHIELD
EXTERN TemperatureSensorShield TemperatureSensor;
#endif

#ifdef TERMINAL_SHIELD
EXTERN TerminalShield Terminal;
#endif

#ifdef TOGGLE_BUTTON_SHIELD
EXTERN ToggleButtonShield ToggleButton;
#endif

#ifdef TEXTTOSPEECH_SHIELD
EXTERN TTSShield TextToSpeech;
#endif

#ifdef TWITTER_SHIELD
EXTERN TwitterShieldClass Twitter;
#endif

#ifdef VOICE_RECOGNITION_SHIELD
EXTERN VoiceRecognitionShield VoiceRecognition;
#endif