# 1Sheeld Library for Arduino [![Build Status](https://travis-ci.org/Integreight/1Sheeld-Arduino-Library.svg?branch=master)](https://travis-ci.org/Integreight/1Sheeld-Arduino-Library)#

## Overview ##

This library is crucial when working with 1Sheeld board, as it is the interface to your smartphone's accessories, sensors and virtual [Arduino shields](http://1sheeld.com). It allows you to communicate and interact with our mobile app using our own custom protocol.

## Installation ##

Make sure you have the latest version of Arduino IDE.

**Automatic Method (Recommended)**

Open the Arduino IDE, go to Sketch > Include Library > Manage Libraries.

![Go to Sketch > Include Library > Manage Libraries](http://i.imgur.com/jxlq6tS.png)

And then, search for our library in the list, pick the latest version and click install.

![Search for our library in the list](http://i.imgur.com/JBTYGmt.png)

**Manual Method**

Download the latest version of the library either from [our website](http://1sheeld.com/downloads) or the [releases page](https://github.com/Integreight/1Sheeld-Arduino-Library/releases). Unzip it in a new directory named *OneSheeld* inside your Arduino's libraries directory.

## Usage And Examples ##

- Add ``` #include <OneSheeld.h> ``` statement at the top of your sketch.
- Call ``` OneSheeld.begin(); ``` in your setup().
- You are now ready to call any of our [shields methods](http://1sheeld.com/docs/).

Note: To reduce the library compiled size and limit its memory usage, you can specify which shields you want to include in your sketch by defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. Review any of our examples to see that in action.

We have more than 60+ examples that covers shields usage. They are categorized into two categories according  to their complexity.

After library installation you can fire up any of our examples by going to File > Examples > OneSheeld > Advanced / Simple then pick your example.

![Go to File > Examples > OneSheeld > Advanced / Simple then pick your example](http://i.imgur.com/P8MYTSZ.png)

Here is a an example that capture a photo using your smartphone's camera and post it to Twitter when a hardware button is pressed.

``` cpp
/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* A name for the button on pin 12. */
int buttonPin = 12;
/* A name for the LED on pin 13. */
int ledPin = 13;

void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the button pin as input. */
  pinMode(buttonPin,INPUT);
  /* Set the LED pin as output. */
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  /* Always check the button state. */
  if(digitalRead(buttonPin) == HIGH)
  {
    /* Turn on the LED. */
    digitalWrite(ledPin,HIGH);
    /* Turn on the camera flash. */
    Camera.setFlash(ON);
    /* Take the picture. */
    Camera.rearCapture();
    /* Wait for 10 seconds. */
    OneSheeld.delay(10000);
    /* Post the picture on Twitter. */
    Twitter.tweetLastPicture("Posted by @1Sheeld");
  }
  else
  {
    /* Turn off the LED. */
    digitalWrite(ledPin,LOW);
  }
    
}
```

## Contribution ##

Contributions are welcomed, please follow this pattern:
- Fork the repo.
- Open an issue with your proposed feature or bug fix.
- Commit and push code to a new branch in your forked repo.
- Submit a pull request to our *development* branch.

Don't forget to drop us an email, post on our forum, or mention us on Twitter or Facebook about what you have built using 1Sheeld, we would love to hear about it.

## Learn More ##

 - [Getting started tutorial](http://www.1sheeld.com/tutorials/getting-started)
 - [Library documentation](http://1sheeld.com/docs/).
 - Download [1Sheeld App](https://play.google.com/store/apps/details?id=com.integreight.onesheeld) from Play Store.
 - Check our [1Sheeld Forums](http://www.1sheeld.com/forum) where you can post your questions and get answers.
 - Explore what people have built at our [Hackster.io page](https://www.hackster.io/1sheeld/projects)

## Changelog ##

To see what has changed in recent versions of 1Sheeld Arduino Library, see the [Change Log](CHANGELOG.md).

## Other Implementations ##

Our awesome community has ported the library to other platforms, check them out:
 - [pcDuino](https://github.com/arduinocodedog/1Sheeld-for-pcDuino)
 - [Netduino](https://github.com/arduinocodedog/1Sheeld-for-Netduino)
 - [PIC32](https://github.com/tom21091/OneSheeldPIC32)

## License and Copyright ##

```
This code is free software; you can redistribute it and/or modify it
under the terms of the GNU Lesser General Public License version 3 only, as
published by the Free Software Foundation.

This code is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
version 3 for more details (a copy is included in the LICENSE file that
accompanied this code).

Please contact Integreight, Inc. at info@integreight.com or post on our
support forums www.1sheeld.com/forum if you need additional information
or have any questions.
```
