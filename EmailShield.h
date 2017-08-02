/*

  Project:       1Sheeld Library 
  File:          EmailShield.h
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#ifndef EmailShield_h
#define EmailShield_h

#include "ShieldParent.h"

//Output Function ID
#define EMAIL_SEND              0x01
#define EMAIL_ATTACH_FILE	      0x02
#define EMAIL_ATTACH_FILE_PATH  0x03

/* LITERALS */
#define LAST_CAMERA_PIC_ONESHEELD_FOLDER    0x00
#define LAST_CAMERA_PIC_CAMERA_FOLDER       0x01
#define LAST_CAMERA_VIDEO                   0x02
#define LAST_CHART_CSV                      0x04
#define LAST_DATA_LOGGER_CSV                0x05
#define LAST_MIC_RECORD                     0x06
#define LAST_MUSIC_TRACK                    0x07

class EmailShieldClass : public ShieldParent
{
public:
  //Constructor
  EmailShieldClass() : ShieldParent(EMAIL_ID){};
	//Sender 
	void send(const char* ,const char*,const char* );
	void send(String , String ,String );
	void attachLastPicture(const char* ,const char*,const char*,byte =0);
  void attachLastPicture(String , String , String , byte =0);
  void attachFile(int);
  void attachFile(const char *);
  void attachFile(String);
private:
  
};

//Extern Object
extern EmailShieldClass Email;
#endif