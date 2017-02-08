/*

  Project:       1Sheeld Library 
  File:          ShieldsInstantiation.h
                 
  Version:       1.4

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.4

*/

#ifdef INCLUDE_BUZZER_SHIELD
EXTERN BuzzerShieldClass Buzzer;
#endif

#ifdef INCLUDE_ACCELEROMETER_SENSOR_SHIELD
EXTERN AccelerometerSensorShield AccelerometerSensor;	
#endif

#ifdef INCLUDE_CAMERA_SHIELD
EXTERN CameraShieldClass Camera;
#endif

#ifdef INCLUDE_CLOCK_SHIELD
EXTERN ClockShield Clock;
#endif

#ifdef INCLUDE_DATA_LOGGER_SHIELD
EXTERN DataLoggerShield Logger;
#endif

#ifdef INCLUDE_EMAIL_SHIELD
EXTERN EmailShieldClass Email;
#endif

#ifdef INCLUDE_FACEBOOK_SHIELD
EXTERN FacebookShieldClass Facebook;
#endif

#ifdef INCLUDE_FOURSQUARE_SHIELD
EXTERN FoursquareShieldClass Foursquare;
#endif

#ifdef INCLUDE_GAMEPAD_SHIELD
EXTERN GamePadShield GamePad;
#endif

#ifdef INCLUDE_GPS_SHIELD
EXTERN GPSShieldClass  GPS;
#endif

#ifdef INCLUDE_GRAVITY_SENSOR_SHIELD
EXTERN GravitySensorShield GravitySensor;
#endif

#ifdef INCLUDE_GYROSCOPE_SENSOR_SHIELD
EXTERN GyroscopeSensorShield GyroscopeSensor;
#endif

#ifdef INCLUDE_INTERNET_SHIELD
EXTERN InternetShield Internet;
#endif

#ifdef INCLUDE_KEYBOARD_SHIELD
EXTERN KeyboardShield AsciiKeyboard;
#endif

#ifdef INCLUDE_KEYPAD_SHIELD
EXTERN KeypadShieldClass Keypad;
#endif

#ifdef INCLUDE_LCD_SHIELD
EXTERN LCDShield LCD;
#endif

#ifdef INCLUDE_LED_SHIELD
EXTERN LedShield LED;
#endif

#ifdef INCLUDE_LIGHT_SENSOR_SHIELD
EXTERN LightSensorShield LightSensor;
#endif

#ifdef INCLUDE_MAGNETOMETER_SENSOR_SHIELD
EXTERN MagnetometerSensorShield MagnetometerSensor;
#endif

#ifdef INCLUDE_MIC_SHIELD
EXTERN MicShield Mic;
#endif

#ifdef INCLUDE_MUSIC_PLAYER_SHIELD
EXTERN MusicPlayerShieldClass MusicPlayer;
#endif

#ifdef INCLUDE_NOTIFICATION_SHIELD
EXTERN NotificationShieldClass Notification;
#endif

#ifdef INCLUDE_ORIENTATION_SENSOR_SHIELD
EXTERN OrientationSensorShield OrientationSensor;
#endif

#ifdef INCLUDE_PATTERN_SHIELD
EXTERN PatternShield Pattern;
#endif

#ifdef INCLUDE_PHONE_SHIELD
EXTERN PhoneShieldClass Phone;
#endif

#ifdef INCLUDE_PRESSURE_SENSOR_SHIELD
EXTERN PressureSensorShield PressureSensor;
#endif

#ifdef INCLUDE_PROXIMITY_SENSOR_SHIELD
EXTERN ProximitySensorShield ProximitySensor;
#endif

#ifdef INCLUDE_PUSH_BUTTON_SHIELD
EXTERN PushButtonShield PushButton;
#endif

#ifdef INCLUDE_SEVEN_SEGMENT_SHIELD
EXTERN SevenSegmentShieldClass SevenSegment;
#endif

#ifdef INCLUDE_SKYPE_SHIELD
EXTERN SkypeShieldClass Skype;
#endif

#ifdef INCLUDE_SLIDER_SHIELD
EXTERN SliderShield Slider;
#endif

#ifdef INCLUDE_SMS_SHIELD
EXTERN SMSShieldClass SMS;
#endif

#ifdef INCLUDE_TEMPERATURE_SENSOR_SHIELD
EXTERN TemperatureSensorShield TemperatureSensor;
#endif

#ifdef INCLUDE_TERMINAL_SHIELD
EXTERN TerminalShield Terminal;
#endif

#ifdef INCLUDE_TOGGLE_BUTTON_SHIELD
EXTERN ToggleButtonShield ToggleButton;
#endif

#ifdef INCLUDE_TEXT_TO_SPEECH_SHIELD
EXTERN TTSShield TextToSpeech;
#endif

#ifdef INCLUDE_TWITTER_SHIELD
EXTERN TwitterShieldClass Twitter;
#endif

#ifdef INCLUDE_VOICE_RECOGNIZER_SHIELD
EXTERN VoiceRecognitionShield VoiceRecognition;
#endif

#ifdef INCLUDE_COLOR_DETECTOR_SHIELD
EXTERN ColorShield ColorDetector;
#endif

#ifdef INCLUDE_NFC_SHIELD
EXTERN NFCShield NFC;
#endif

#ifdef INCLUDE_GLCD_SHIELD
EXTERN GLCDShield GLCD;
#endif

#ifdef INCLUDE_VIBRATION_SHIELD
EXTERN VibrationShield Vibration;
#endif

#ifdef INCLUDE_BARCODE_SCANNER_SHIELD
EXTERN BarcodeScannerShield BarcodeScanner;
#endif

#ifdef INCLUDE_FINGERPRINT_SCANNER_SHIELD
EXTERN FingerprintScannerShield FingerprintScanner;
#endif

#ifdef INCLUDE_FACE_DETECTOR_SHIELD
EXTERN FaceDetectionShield FaceDetector;
#endif

#ifdef INCLUDE_CHART_SHIELD
EXTERN ChartShield Chart;
#endif

#ifdef INCLUDE_IOT_SHIELD
EXTERN IOTShield IOT;
#endif