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
  void setPort(int = 1883);
  void setClientID(const char *);
  void setClientID(String);
  void setLastWillAndTestament(const char *,const char *,byte =0,byte =0);
  void setLastWillAndTestament(String,String,byte =0,byte =0);
  void setCleanSession(bool=true);
  void setKeepAlive(unsigned int = 30);
  void setCredentials(const char *,const char * );
  void setCredentials(String,String);
  void setAutoReconnect(bool =true);
  void connect();
  void connect(const char *,int=1883);
  void connect(const char *, const char *, const char *,int=1883);
  void connect(String,int=1883);
  void connect(String,String,String,int=1883);
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
  void setOnConnectionStatusChange(void (userFunction)(byte));
  void setOnNewMessage(void (userFunction)(char * ,char * ,bool));
  void setOnNewMessageAsString(void (userFunction)(String,String,bool));
  void setOnError(void (userFunction)(byte));
  void resetConnectionParametersToDefault();
private:
  bool isBrokerConnected;
  bool isConnStatCallbackAssigned;
  bool isMessageCallbackAssigned;
  bool isMessageStrCallbackAssigned;
  bool isErrorCallbackAssigned;
  void processData();
  void (*connectionStatusCallback)(byte);
  void (*newMessageCallback)(char * ,char *,bool );
  void (*newMessageCallbackAsString)(String,String,bool);
  void (*errorCallback)(byte);
};

extern IOTShield IOT;
#endif