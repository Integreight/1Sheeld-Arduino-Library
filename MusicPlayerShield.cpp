/*

  Project:       1Sheeld Library 
  File:          MusicPlayerShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "MusicPlayerShield.h"

//Stop Setter
void MusicPlayerShieldClass::stop()
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,STOP,0);
}
//Play Setter
void MusicPlayerShieldClass::play()
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,PLAY,0);
}
//Pause Setter
void MusicPlayerShieldClass::pause()
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,PAUSE,0);
}
//Previous Setter
void MusicPlayerShieldClass::previous()
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,PREVIOUS,0);
}
//Next Setter
void MusicPlayerShieldClass::next()
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,NEXT,0);
}
//SeekForward Setter
void MusicPlayerShieldClass::seekForward(byte x)
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,SEEK_FORWARD,1,new FunctionArg(1,&x));
}
//SeekBackward Setter
void MusicPlayerShieldClass::seekBackward(byte x)
{
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,SEEK_BACKWARD,1,new FunctionArg(1,&x));
}
//Volume Setter
void MusicPlayerShieldClass::setVolume(byte x)
{
	if (x>10) 
		{x=10;}
	else if (x<0) 
		{x=0;}
	OneSheeld.sendPacket(MUSIC_PLAYER_ID,0,VOLUME,1,new FunctionArg(1,&x));
}

//Instantiating Object
MusicPlayerShieldClass MusicPlayer;