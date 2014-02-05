#include "OneSheeld.h"
#include "MusicPlayerShield.h"


MusicPlayerShieldClass::MusicPlayerShieldClass()
{}

void MusicPlayerShieldClass::stop()
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,STOP,0);
}

void MusicPlayerShieldClass::play()
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,PLAY,0);
}
void MusicPlayerShieldClass::pause()
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,PAUSE,0);
}
void MusicPlayerShieldClass::previous()
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,PREVIOUS,0);
}
void MusicPlayerShieldClass::next()
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,NEXT,0);
}
void MusicPlayerShieldClass::seekForward(byte x)
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,SEEK_FORWARD,1,new FunctionArg(1,&x));
}
void MusicPlayerShieldClass::seekBackward(byte x)
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,SEEK_BACKWARD,1,new FunctionArg(1,&x));
}

MusicPlayerShieldClass MusicPlayer;