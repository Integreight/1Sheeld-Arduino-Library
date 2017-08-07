## v1.14.0(018) (August 7, 2017)
 - Added new methods to append data to old logged files in data logger shield.
 - Added new attach methods to the email shield.
 - Added new methods to play tracks by name or index in the music player shield.

## v1.13.0(017) (March 20, 2017)
 - Supported the new IoT shield.
 - Fixed some bugs.

## v1.12.0(016) (January 29, 2017)
 - Supported the new chart shield.
 - Fixed some bugs.

## v1.11.0(015) (December 19, 2016)
 - Supported the new fingerprint scanner and face detector shields.
 - Fixed a bug in the frames timeout that marks a correct frame faulty.

## v1.10.0(014) (November 7, 2016)
 - Supported the new bar code scanner shield.
 - Supported Arduino Zero and Arduino 101.
 - Made the library handle half-sent frames correctly.

## v1.9.2(013) (May 17, 2016)
 - Used the correct delay method for 1Sheeld+ workaround.

## v1.9.1(012) (May 15, 2016)
 - Added a workaround for 1Sheeld+ slow sending to prevent overruns.

## v1.9.0(011) (April 4, 2016)
 - Prepared the library to work with SoftwareSerial and AltSoftSerial libraries. (BETA)
 - Made the library connection testable.
 - Added a verification byte to frames sent.

## v1.8.0(010) (January 26, 2016)
 - Added the vibration shield.

## v1.7.0(009) (November 23, 2015)
 - Fixed a bug with the new SDK functions.
 - Added methods for uploading images from internet shield.
 - Added methods for recording voice clips from mic shield.

## v1.6.1(008) (September 1, 2015)
 - Added 2 new methods for sending and receiving frames. (For the new Android SDK)
 - Fixed an error in Internet shield.
 - Fixed a bug in GLCD shield.
 - Removed unneeded files.

## v1.6.0(007) (August 16, 2015)
 - Supported the new GLCD shield.

## v1.5.0(006) (May 5, 2015)
 - Supported the new color detector and NFC shields.
 - Added a way to decrease the size occupied by the library by disabling some shields from compilation from the sketch.
 - Deprecated Clock.begin() function in the clock shield.
 - Changed keywords highlighting to support the new IDE (v1.6.3).
 - Fixed a bug in JSON handling in the Internet shield.
 - Removed RemoteOneSheeld functionality.
 - Enhanced app connectivity checking and added OneSheeld.setOnAppConnection() event.
 - Fixed a bug that hangs the user's sketch if he dealed with callbacks.
 - Added an example to show Twitter keyword tracking functionality.

## v1.4.0(005) (March 8, 2015)
 - Supported the new Internet and pattern shields.
 - Revamped the whole library and added a parent class for all shields.
 - Added a delay function to be used instead of the regular Arduino one.
 - Added functions to enable callbacks interrupts from the app.
 - Added a function to set the value of the slider shield from Arduino.
 - Notify Arduino once the sketch enters and exits callbacks.
 - Added a callback to be called once the shield is selected on the App.
 - Increased overall library stability and fixed other bugs.

## v1.3.0(004) (December 25, 2014)
 - Supported input strings parameters for each char array functions.
 - Added a method to attach pictures to email shield.
 - Added methods to check BT connectivity.
 - Added a feature to control 1Sheelds remotely through the internet.
 - Added methods to track keywords to Twitter shield.
 - Report the library version when queried.
 - Increased overall library stability and fixed other bugs.

## v1.2.0(003) (September 10, 2014)
 - Added four new shields with examples (Data logger, voice recognition, text to speech and terminal).
 - Added methods to post photos to Facebook and Twitter shields.
 - Added a method to send direct messages from Twitter shield.
 - Added a way to decrease the size occupied by the library by disabling some shields from compilation.
 - Added more printing functions to the LCD shield.
 - Fixed a major bug that made the sketches hang after a couple of minutes.
 - Decreased the forced delay between frames to 200ms instead of 300ms.
 - Fixed some typos.
 - Increased overall library stability.

## v1.1.0(002) (June 29, 2014)
 - Added support for Intel Galileo board.
 - Added a getAsFahrenheit() Helper Function.
 - Refactored the LCD shield example.

## v1.0.0(001) (May 29, 2014)
 - Initial Release.