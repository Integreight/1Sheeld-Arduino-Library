/*

IOT Shield Example

This example shows an application on 1Sheeld's IoT shield.

By using this example, you can securely connect to a MQTT broker with SSL connection,
publish analog sensor values, subscribe for another remote sensor values and log
them using the data logger shield.
 
OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_IOT_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_DATA_LOGGER_SHIELD

/* Set your host name. */
#define HOST_NAME "hostname"
/* Set keep alive interval. */
#define KEEP_ALIVE_INTERVAL   10
/* Set port. */
#define PORT  8883
/* Set last will topic. */
#define LAST_WILL_TOPIC "1Sheeld/MyArduino/Status"
/* Set last will payload. */
#define LAST_WILL_PAYLOAD "Disconnected"
/* Set username. */
#define USER_NAME "username"
/* Set password. */
#define PASSWORD  "password"

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Flag to check if already subscribed. */
bool subscribed = false;
/* Flag to check if logger not started. */
bool startedLogging = false;
/* Set sensor on pin A0. */
int sensorPin = A0;
/* Counter for incoming sensor values. */
int counter;
/* Subscribe to topic "1Sheeld/MyArduino/RemoteSensor" to get remote sensor values . */
const char * subscribeTopic = "1Sheeld/MyArduino/RemoteSensor";
/* Pulish sesnor values to topic "1Sheeld/MyArduino/AnalogSensor" . */
const char * publishTopic = "1Sheeld/MyArduino/AnalogSensor";

void setup() 
{
  /* Start communication. */
  OneSheeld.begin();
  /* Disconnect from broker. */
  IOT.disconnect();
  /* Reset all connection parameters to default */
  IOT.resetConnectionParametersToDefaults();
  /* Set host name. */
  IOT.setHost(HOST_NAME);
  /* Set port no .*/
  IOT.setPort(PORT);
  /* Set the connection as SSL/TLS. */
  IOT.setSecureConnection(true);
  /* Set keep alive interval. */
  IOT.setKeepAlive(KEEP_ALIVE_INTERVAL);
  /* Set persistent session. */
  IOT.setCleanSession(false);
  /* Set username & password. */
  IOT.setCredentials(USER_NAME,PASSWORD);
  /* Set last will with QOS_0 and as a retained message. */
  IOT.setLastWillAndTestament(LAST_WILL_TOPIC,LAST_WILL_PAYLOAD,QOS_0,true);
  /* Connect to broker. */
  IOT.connect();
  /* Subscribe to new messages. */
  IOT.setOnNewMessage(&newMessage);
  /* Subscribe to connnection status callback. */
  IOT.setOnConnectionStatusChange(&connectionStatus);
  /* Subscribe to error callback. */
  IOT.setOnError(&error);
  /* Sensor pin mode input. */
  pinMode(sensorPin,INPUT);
}

void loop()
{
  /* Check if connected to broker. */
  bool connectedToBroker = IOT.isConnected();
  if(connectedToBroker)
  {
    /* Check if already subscribed to topic
     * and don't subscribe again.
     */
    if(!subscribed)
    {
      /* Subscribe to led topic. */
      IOT.subscribe(subscribeTopic);
      subscribed = true;
    }
    int sensorValue = analogRead(sensorPin);
    /* Publish to mic topic. */
    IOT.publish(publishTopic,sensorValue,QOS_1,true);
  }
}

void newMessage(char * incomingTopic, float payload, byte qos, bool retained)
{
  /* Check if 1000 messages were logged stop logging
   * and reset startLogging and counter variables.
  */
  if(counter == 1000)
  {
    Logger.stop();
    startedLogging = false;
    counter=0;
  }
  /* Check if data logging not started, then start 
   * with a new file.
  */ 
  if(!startedLogging)
  {
    Logger.start("SensorValues");
    startedLogging = true;
  }
  /* Log data to file. */
  if(startedLogging)
  {
    Logger.add("Value",payload);
    Logger.log();
    counter++;  
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