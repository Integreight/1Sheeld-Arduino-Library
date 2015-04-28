How to install:

Clone the library into a new folder in the libraries folder of your Arduino installation.

(ex: C:\Program Files\Arduino\libraries\OneSheeld)
```
git clone https://github.com/Integreight/1Sheeld-Arduino-Library.git ./OneSheeld
```

Follow the [getting started tutorial](http://www.1sheeld.com/tutorials/getting-started) on our website to know how to operate 1Sheeld and run the library's examples.

If you need more help, don't hesitate posting a question on our [website's forum](http://www.1sheeld.com/forum).

If you want to contribute, please discuss you proposed feature on our forum first so that you can coordinate with the other developers working on the library.

Change Log:

--------- Version 1.5.0(006) -----------

- Supported the new color detector and NFC shields.
- Added a way to decrease the size occupied by the library by disabling some shields from compilation from the sketch.
- Deprecated Clock.begin() function in the clock shield.
- Changed keywords highlighting to support the new IDE (v1.6.3).
- Fixed a bug in JSON handling in the Internet shield.
- Removed RemoteOneSheeld functionality.
- Enhanced app connectivity checking and added OneSheeld.setOnAppConnection() event.
- Fixed a bug that hangs the user's sketch if he dealed with callbacks.
- Added an example to show Twitter keyword tracking functionality.

--------- Version 1.4.0(005) -----------

- Supported the new Internet and pattern shields.
- Revamped the whole library and added a parent class for all shields.
- Added a delay function to be used instead of the regular Arduino one.
- Added functions to enable callbacks interrupts from the app.
- Added a function to set the value of the slider shield from Arduino.
- Notifiy Arduino once the sketch enters and exits callbacks.
- Added a callback to be called once the shield is selected on the App.
- Increased overall library stability and fixed other bugs.

--------- Version 1.3.0(004) -----------

- Supported input strings parameters for each char array functions.
- Added a method to attach pictures to email shield.
- Added methods to check BT connectivity.
- Added a feature to control 1Sheelds remotely through the internet.
- Added methods to track keywords to Twitter shield.
- Report the library version when queried.
- Increased overall library stability and fixed other bugs.

--------- Version 1.2.0(003) -----------

- Added four new shields with examples (Data logger, voice recognition, text to speech and terminal).
- Added methods to post photos to Facebook and Twitter shields.
- Added a method to send direct messages from Twitter shield.
- Added a way to decrease the size occupied by the library by disabling some shields from compilation.
- Added more printing functions to the LCD shield.
- Fixed a major bug that made the sketches hang after a couple of minutes.
- Decreased the forced delay between frames to 200ms instead of 300ms.
- Fixed some typos.
- Increased overall library stability.

1Sheeld Arduino Library by Integreight, Inc. is licensed under GNU Lesser General Public License v3.0 (GNU LGPL v3.0).