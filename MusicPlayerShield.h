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
#define MUSIC_STOP 			0x01
#define MUSIC_PLAY 			0x02
#define MUSIC_PAUSE 			0x03
#define MUSIC_PREVIOUS 		0x04
#define MUSIC_NEXT 			0x05
#define MUSIC_SEEK_FORWARD 	0x06
#define MUSIC_SEEK_BACKWARD 	0x07
#define MUSIC_VOLUME 		  	0x08
#define MUSIC_SELECT_SHEILD		0xFE
#define MUSIC_UNSELECT_SHIELD	0xFD

//Input Function ID
#define MUSIC_CHECK_SELECTED	0xFF

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
	//Selection
	void select();
	void unselect();
	//Set On Selected
	void setOnSelected(void (*)(void));
private:
	void processData();
	void (*selectedCallBack)(void);

	friend class OneSheeldClass;
};

//Extern Object
extern MusicPlayerShieldClass MusicPlayer;
#endif