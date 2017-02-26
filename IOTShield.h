/*

  Project:       1Sheeld Library 
  File:          IOTShield.h
                 
  Version:       1.13.0

  Compiler:      Arduino avr#define gcc 4.3.2

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
#define IOT_PUBLISH_STRING    0x0B
#define IOT_PUBLISH_INT       0x0C
#define IOT_PUBLISH_UINT      0x0D
#define IOT_PUBLISH_FLOAT     0x0E
#define IOT_PUBLISH_RAW       0x1F
#define IOT_SUBSCRIBE         0x10
#define IOT_UNSUBSCRIBE       0x11

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
#define BAD_CREDENTIALS               0x06
#define MISSING_CONNECTION_PARAMETERS 0x07



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
  void setLastWillAndTestament(const char *,const char *,byte,byte);
  void setLastWillAndTestament(String,String,byte,byte);
  void setCleanSession(bool);
  void setKeepAlive(unsigned int);
  void setCredentials(const char *,const char * );
  void setCredentials(String,String);
  void setAutoReconnect(bool);
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
  void publish(const char *,const char * ,byte,bool);
  void publish(const char*, byte *,byte ,byte,bool);
  void publish(const char *, int , byte,bool);
  void publish(const char *, unsigned int,byte,bool);
  void publish(const char *, float ,byte,bool);
  void publish(String, String,byte,bool);
  void publish(String, byte *,byte ,byte,bool);
  void publish(String, int , byte,bool);
  void publish(String, unsigned int,byte,bool);
  void publish(String, float ,byte,bool);
  void subscribe(const char *,byte);
  void subscribe(String,byte);
  void unsubscribe(const char *);
  void unsubscribe(String);
  void setOnConnectionStatusChange(void (userFunction)(byte));
  void setOnNewMessage(void (userFunction)(char * ,char * ,byte,bool));
  void setOnNewMessageAsString(void (userFunction)(String,String,byte,bool));
  void setOnError(void (userFunction)(byte));
  void resetConnectionParametersToDefaults();
private:
  bool isBrokerConnected;
  bool isConnStatCallbackAssigned;
  bool isMessageCallbackAssigned;
  bool isMessageStrCallbackAssigned;
  bool isErrorCallbackAssigned;
  void processData();
  void (*connectionStatusCallback)(byte);
  void (*newMessageCallback)(char * ,char *,byte,bool );
  void (*newMessageCallbackAsString)(String,String,byte,bool);
  void (*errorCallback)(byte);
};

extern IOTShield IOT;
#endif