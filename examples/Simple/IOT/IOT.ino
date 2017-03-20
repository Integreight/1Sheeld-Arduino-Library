/*

IOT Shield Example

This example shows an application on 1Sheeld's iot shield.

By using this example, you can control the status of a LED by posting
on/off messages to a MQTT topic.
 
OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_IOT_SHIELD
#define INCLUDE_TERMINAL_SHIELD

/* Set your host name */
#define HOST_NAME "test.mosquitto.org"

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Set an LED on pin 13. */
int ledPin = 13;
/* Subscribe to topic 1Sheeld/MyArduino/led . */
const char * myTopic = "1Sheeld/MyArduino/led";

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Disconnect from broker. */
  IOT.disconnect();
  /* Reset all connection variables to default */
  IOT.resetConnectionParametersToDefaults();
  /* Connect to mosquitto's public broker. */
  IOT.connect(HOST_NAME);
  /* Subscribe to new messages. */
  IOT.setOnNewMessage(&newMessage);
  /* Subscribe to connnection status callback. */
  IOT.setOnConnectionStatusChange(&connectionStatus);
  /* Subscribe to error callback. */
  IOT.setOnError(&error);
  /* Some time for app to connect. */
  delay(3000);
  /* Subscribe to led topic. */
  IOT.subscribe(myTopic);
  /* LED pin mode output. */
  pinMode(ledPin,OUTPUT);
}

void loop()
{}

void newMessage(char * incomingTopic, char * payload, byte qos, bool retained)
{
  /* Check on incomingTopic. */
  if(!strcmp(myTopic,incomingTopic))
  {
    /* If payload states ON. */
    if(!strcmp("ON",payload))
    {
      /* Turn on the led. */
      digitalWrite(ledPin,HIGH);
    }
    /* If payload states OFF. */
    else if(!strcmp("OFF",payload))
    {
      /* Turn off the led. */
      digitalWrite(ledPin,LOW);
    }
  }
}

void connectionStatus(byte statusCode)
{
  /* Check connection code and display. */
  switch(statusCode)
  {
    case CONNECTION_SUCCESSFUL: Terminal.println("CONNECTION_SUCCESSFUL");break;
    case CONNECTION_FAILED: Terminal.println("CONNECTION_FAILED");break;
    case CONNECTION_LOST: Terminal.println("CONNECTION_LOST");break;
    case CONNECTION_LOST_RECONNECTING: Terminal.println("CONNECTION_LOST_RECONNECTING");break;
    case NOT_CONNECTED_YET:  Terminal.println("NOT_CONNECTED_YET");break;
    case MISSING_HOST: Terminal.println("MISSING_HOST");break;
  }
}

void error(byte errorCode)
{
  /* Check error code and display. */
  switch(errorCode)
  {
    case CONNECTION_REFUSED                    : Terminal.println("CONNECTION_REFUSED");break;
    case ILLEGAL_MESSAGE_RECEIVED              : Terminal.println("ILLEGAL_MESSAGE_RECEIVED");break;
    case DROPPING_OUT_GOING_MESSAGE            : Terminal.println("DROPPING_OUT_GOING_MESSAGE");break;
    case ENCODER_NOT_READY                     : Terminal.println("ENCODER_NOT_READY");break;
    case INVALID_CONNACK_RECEIVED              : Terminal.println("INVALID_CONNACK_RECEIVED");break;
    case NO_CONNACK_RECEIVED                   : Terminal.println("NO_CONNACK_RECEIVED");break;
    case CONNACK_UNACCEPTABLEP_ROTOCOLVERSION  : Terminal.println("CONNACK_UNACCEPTABLEP_ROTOCOLVERSION");break;
    case CONNACK_IDENTIFIER_REJECTED           : Terminal.println("CONNACK_IDENTIFIER_REJECTED");break;
    case CONNACK_SERVER_UNAVAILABLE            : Terminal.println("CONNACK_SERVER_UNAVAILABLE");break;
    case CONNACK_AUTHENTICATION_FAILED         : Terminal.println("CONNACK_AUTHENTICATION_FAILED");break;
    case CONNACK_NOT_AUTHORIZED                : Terminal.println("CONNACK_NOT_AUTHORIZED");break;
    case CONNACK_RESERVED                      : Terminal.println("CONNACK_RESERVED");break;
  }
}