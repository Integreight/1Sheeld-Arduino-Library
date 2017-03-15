/*

  Project:       1Sheeld Library 
  File:          IOTShield.h
                 
  Version:       1.13.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.2

*/
#ifndef IOTShield_h
#define IOTShield_h

#include "ShieldParent.h"

//Output Function ID
#define IOT_RESET_TO_DEFAULT    0x00
#define IOT_SET_HOST          0x01
#define IOT_SET_PORT          0x02
#define IOT_SET_CLIENT_ID     0x03
#define IOT_LAST_WILL         0x04
#define IOT_CLEAN_SESSION     0x05
#define IOT_KEEP_ALIVE        0x06
#define IOT_CREDENTIALS       0x07
#define IOT_AUTO_RECON        0x08
#define IOT_CONNECT           0x09
#define IOT_DISCONNECT        0x0A
#define IOT_PUBLISH           0x0B
#define IOT_SUBSCRIBE         0x0C
#define IOT_UNSUBSCRIBE       0x0D
#define IOT_UNSUBSCRIBE_ALL   0x0E
#define IOT_SSL_CONNECTION    0x0F


// Exception until we support sending empty strings
#define IOT_PUBLISH_EMPTY     0xFE
 

//Input Function ID
#define IOT_GET_DATA        0x01
#define IOT_GET_CONNECTION  0x02
#define IOT_GET_ERROR       0x03
//Literals
#define QOS_0            0x00
#define QOS_1            0x01
#define QOS_2            0x02
#define NOT_RETAINED     0x00
#define RETAINED         0x01
//Connection codes literals
#define CONNECTION_SUCCESSFUL         0x01
#define CONNECTION_FAILED             0x02
#define CONNECTION_LOST               0x03
#define CONNECTION_LOST_RECONNECTING  0x04
#define NOT_CONNECTED_YET             0x05
#define MISSING_HOST                  0x06

// Callback assginments order in callbacksAssignments variable
#define CHAR_CHAR       0
#define CHAR_INT        1
#define CHAR_UNINT      2
#define CHAR_FLOAT      3
#define CHAR_RAW        4
#define STRING_STRING   5
#define STRING_INT      6
#define STRING_UNINT    7
#define STRING_FLOAT    8
#define STRING_RAW      9

// Error literals
#define CONNECTION_REFUSED                    0x00
#define ILLEGAL_MESSAGE_RECEIVED              0x01
#define DROPPING_OUT_GOING_MESSAGE            0x02
#define ENCODER_NOT_READY                     0x03
#define INVALID_CONNACK_RECEIVED              0x04
#define NO_CONNACK_RECEIVED                   0x05
#define CONNACK_UNACCEPTABLEP_ROTOCOLVERSION  0x06
#define CONNACK_IDENTIFIER_REJECTED           0x07
#define CONNACK_SERVER_UNAVAILABLE            0x08
#define CONNACK_AUTHENTICATION_FAILED         0x09
#define CONNACK_NOT_AUTHORIZED                0x0A
#define CONNACK_RESERVED                      0x0B

class IOTShield : public ShieldParent
{
public:
  IOTShield();
  bool isConnected();
  void setHost(const char *);
  void setHost(String);
  void setPort(unsigned int);
  void setClientID(const char *);
  void setClientID(String);
  void setLastWillAndTestament(const char *,const char *,byte=0,bool=false);
  void setLastWillAndTestament(String,String,byte=0,bool=false);
  void setCleanSession(bool);
  void setKeepAlive(unsigned int);
  void setCredentials(const char *,const char * );
  void setCredentials(String,String);
  void setAutoReconnect(bool);
  void setSecureConnection(bool);
  void connect();
  void connect(const char*);
  void connect(const char *,unsigned int);
  void connect(const char *,unsigned int,bool);
  void connect(const char *, const char *, const char *,unsigned int);
  void connect(String);
  void connect(String,unsigned int);
  void connect(String,unsigned int,bool);
  void connect(String,String,String,unsigned int);
  void disconnect();
  void publish(const char *,const char * ,byte=0,bool=false);
  void publish(const char*, byte *,byte ,byte=0,bool=false);
  void publish(const char *, int , byte=0,bool=false);
  void publish(const char *, unsigned int,byte=0,bool=false);
  void publish(const char *, float ,byte=0,bool=false);
  void publish(String, String,byte=0,bool=false);
  void publish(String, byte *,byte ,byte=0,bool=false);
  void publish(String, int , byte=0,bool=false);
  void publish(String, unsigned int,byte=0,bool=false);
  void publish(String, float ,byte=0,bool=false);
  void subscribe(const char *,byte=0);
  void subscribe(String,byte=0);
  void unsubscribe(const char *);
  void unsubscribe(String);
  void unsubscribe();
  void setOnConnectionStatusChange(void (userFunction)(byte));
  void setOnNewMessage(void (userFunction)(char * ,char * ,byte,bool));
  void setOnNewMessage(void (userFunction)(char * ,int ,byte,bool));
  void setOnNewMessage(void (userFunction)(char * ,unsigned int ,byte,bool));
  void setOnNewMessage(void (userFunction)(char * ,float ,byte,bool));
  void setOnNewMessage(void (userFunction)(char * ,byte*,byte,byte,bool));
  void setOnNewMessage(void (userFunction)(String,String,byte,bool));
  void setOnNewMessage(void (userFunction)(String,int,byte,bool));
  void setOnNewMessage(void (userFunction)(String,unsigned int,byte,bool));
  void setOnNewMessage(void (userFunction)(String,float,byte,bool));
  void setOnNewMessage(void (userFunction)(String,byte*,byte,byte,bool));
  void setOnError(void (userFunction)(byte));
  void resetConnectionParametersToDefaults();
private:
  int callbacksAssignments;
  bool isBrokerConnected;
  bool isConnStatCallbackAssigned;
  bool isErrorCallbackAssigned;
  void processData();
  void (*connectionStatusCallback)(byte);
  void (*newMessageCharCharCallback)(char * ,char *,byte,bool );
  void (*newMessageCharIntCallback)(char * ,int,byte,bool );
  void (*newMessageCharUnIntCallback)(char * ,unsigned int,byte,bool );
  void (*newMessageCharFloatCallback)(char * ,float,byte,bool );
  void (*newMessageCharRawCallback)(char * ,byte *,byte,byte,bool );
  void (*newMessageStrStrCallback)(String,String,byte,bool);
  void (*newMessageStrIntCallback)(String,int,byte,bool);
  void (*newMessageStrUnIntCallback)(String,unsigned int,byte,bool);
  void (*newMessageStrFloatCallback)(String,float,byte,bool);
  void (*newMessageStrRawCallback)(String,byte*,byte,byte,bool);
  void (*errorCallback)(byte);
};

extern IOTShield IOT;
#endif