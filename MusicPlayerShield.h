#ifndef MusicPlayerShield_h
#define MusicPlayerShield_h

#define STOP 0x01
#define PLAY 0x02
#define PAUSE 0x03
#define PREVIOUS 0x04
#define NEXT 0x05
#define SEEK_FORWARD 0x06
#define SEEK_BACKWARD 0x07

class MusicPlayerShieldClass 
{
private:

public:
	MusicPlayerShieldClass();
	void stop();
	void play();
	void pause();
	void previous();
	void next();
	void seekForward(byte x);
	void seekBackward(byte x);
};

extern MusicPlayerShieldClass MusicPlayer;
#endif