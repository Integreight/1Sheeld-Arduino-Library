/*

  Project:       1Sheeld Library 
  File:          MusicPlayerShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef MusicPlayerShield_h
#define MusicPlayerShield_h

//Output Functions ID's
#define STOP 			0x01
#define PLAY 			0x02
#define PAUSE 			0x03
#define PREVIOUS 		0x04
#define NEXT 			0x05
#define SEEK_FORWARD 	0x06
#define SEEK_BACKWARD 	0x07
#define VOLUME 		  	0x08

class MusicPlayerShieldClass 
{

public:
	//Setters
	void stop();
	void play();
	void pause();
	void previous();
	void next();
	void seekForward(byte );
	void seekBackward(byte );
	void setVolume(byte );

private:

};

//Extern Object
extern MusicPlayerShieldClass MusicPlayer;
#endif