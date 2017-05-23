/*

  Project:       1Sheeld Library 
  File:          MusicPlayerShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "MusicPlayerShield.h"

//Stop Setter
void MusicPlayerShieldClass::stop()
{
	OneSheeld.sendShieldFrame(MUSIC_PLAYER_ID,0,MUSIC_STOP,0);
}
//Play Setter
void MusicPlayerShieldClass::play()
{
	OneSheeld.sendShieldFrame(MUSIC_PLAYER_ID,0,MUSIC_PLAY,0);
}
//Pause Setter
void MusicPlayerShieldClass::pause()
{
	OneSheeld.sendShieldFrame(MUSIC_PLAYER_ID,0,MUSIC_PAUSE,0);
}

void MusicPlayerShieldClass::play(const char * fileName)
{
	OneSheeld.sendShieldFrame(MUSIC_PLAYER_ID,0,MUSIC_PLAY_FILE_NAME,1,new FunctionArg(strlen(fileName),(byte*)fileName));
}

void MusicPlayerShieldClass::play(int fileIndex)
{
	OneSheeld.sendShieldFrame(MUSIC_PLAYER_ID,0,MUSIC_PLAYD_FILE_INDEX,1,new FunctionArg(2,(byte*)&fileIndex));
}

//Previous Setter
void MusicPlayerShieldClass::previous()
{
	OneSheeld.sendShieldFrame(MUSIC_PLAYER_ID,0,MUSIC_PREVIOUS,0);
}
//Next Setter
void MusicPlayerShieldClass::next()
{
	OneSheeld.sendShieldFrame(MUSIC_PLAYER_ID,0,MUSIC_NEXT,0);
}
//SeekForward Setter
void MusicPlayerShieldClass::seekForward(byte x)
{
	OneSheeld.sendShieldFrame(MUSIC_PLAYER_ID,0,MUSIC_SEEK_FORWARD,1,new FunctionArg(1,&x));
}
//SeekBackward Setter
void MusicPlayerShieldClass::seekBackward(byte x)
{
	OneSheeld.sendShieldFrame(MUSIC_PLAYER_ID,0,MUSIC_SEEK_BACKWARD,1,new FunctionArg(1,&x));
}
//Volume Setter
void MusicPlayerShieldClass::setVolume(byte x)
{
	if (x>10) x=10;
	OneSheeld.sendShieldFrame(MUSIC_PLAYER_ID,0,MUSIC_VOLUME,1,new FunctionArg(1,&x));
}

