/*

  Project:       1Sheeld Library 
  File:          IOTShield.cpp
                 
  Version:       1.13.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.2

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "IOTShield.h"



IOTShield::IOTShield() : ShieldParent(IOT_ID)
{
	isBrokerConnected = false;
    isConnStatCallbackAssigned = false;
  	isMessageCallbackAssigned = false;
  	isErrorCallbackAssigned = false;
  	isMessageStrCallbackAssigned = false;
}

bool IOTShield::isConnected()
{
	return isBrokerConnected;
}

void IOTShield::setHost(const char * server)
{
	byte serverNameLength = strlen(server);
	if(serverNameLength)
	{
		OneSheeld.sendShieldFrame(IOT_ID,0,IOT_SET_HOST,1,new FunctionArg(serverNameLength,(byte*)server));
	}
}

void IOTShield::setHost(String server)
{
	setHost(&server[0]);
}

void IOTShield::setPort(int portNumber)
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_SET_PORT,1,new FunctionArg(sizeof(int),(byte*)&portNumber));	
}

void IOTShield::setClientID(const char * clientID)
{
	byte clientIdLength = strlen(clientID);
	if(clientIdLength)
	{
		OneSheeld.sendShieldFrame(IOT_ID,0,IOT_SET_CLIENT_ID,1,new FunctionArg(clientIdLength,(byte*)clientID));
	}
}

void IOTShield::setClientID(String clientID)
{
	setClientID(&clientID[0]);
}

void IOTShield::setLastWillAndTestament(const char * willTopic,const char * willMessage,byte willQos,byte willRetained)
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_LAST_WILL,4,new FunctionArg(strlen(willTopic),(byte*)willTopic)
												 ,new FunctionArg(strlen(willMessage),(byte*)willMessage)
												 ,new FunctionArg(sizeof(byte),&willQos)
												 ,new FunctionArg(sizeof(byte),&willRetained));
}

void IOTShield::setLastWillAndTestament(String willTopic,String willMessage,byte willQos,byte willRetained)
{
	setLastWillAndTestament(&willTopic[0],&willMessage[0],willQos,willRetained);
}

void IOTShield::setCleanSession(bool cleanSession)
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_CLEAN_SESSION,1,new FunctionArg(sizeof(cleanSession),(byte*)&cleanSession));	
}

void IOTShield::setKeepAlive(unsigned int keepAlive)
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_KEEP_ALIVE,1,new FunctionArg(sizeof(unsigned int),(byte*)&keepAlive));		
}

void IOTShield::setCredentials(const char * userName,const char * password)
{
	byte userNameLength = strlen(userName);
	byte passwordLength = strlen(password);
	if(userNameLength && passwordLength)
	{
		OneSheeld.sendShieldFrame(IOT_ID,0,IOT_CREDENTIALS,2,new FunctionArg(userNameLength,(byte*)userName)
													 ,new FunctionArg(passwordLength,(byte*)password));
	}
}

void IOTShield::setCredentials(String userName,String password)
{
	setCredentials(&userName[0],&password[0]);
}

void IOTShield::setAutoReconnect(bool autoReconnect)
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_AUTO_RECON,1,new FunctionArg(sizeof(bool),(byte*)&autoReconnect));		
}

void IOTShield::connect()
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_CONNECT,0);				
}

void IOTShield::connect(const char * host,int portNumber)
{
	byte hostLength = strlen(host);	
	if(hostLength)
	{
		OneSheeld.sendShieldFrame(IOT_ID,0,IOT_CONNECT,2,new FunctionArg(hostLength,(byte*)host)
												,new FunctionArg(sizeof(int),(byte*)&portNumber));	
	}
	
}

void IOTShield::connect(String host,int portNumber)
{
	connect(&host[0],portNumber);
}

void IOTShield::connect(const char * host, const char * userName, const char *password,int portNumber)
{
	byte hostLength = strlen(host);	
	byte userNameLength = strlen(userName);
	byte passwordLength = strlen(password);
	if(hostLength && userNameLength && passwordLength)
	{
		OneSheeld.sendShieldFrame(IOT_ID,0,IOT_CONNECT,4,new FunctionArg(hostLength,(byte*)host)
													,new FunctionArg(userNameLength,(byte*)userName)
													,new FunctionArg(passwordLength,(byte*)password)
													,new FunctionArg(sizeof(int),(byte*)&portNumber));
	}			
}

void IOTShield::connect(String host,String userName,String password,int portNumber)
{
	connect(&host[0],&userName[0],&password[0],portNumber);
}

void IOTShield::disconnect()
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_DISCONNECT,0);
	isBrokerConnected=false;	
}

void IOTShield::publish(const char * topic,const char * payload,byte qos,bool retain)
{
	if(qos > 2)qos = 2;
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_PUBLISH_STRING,4,new FunctionArg(strlen(topic),(byte*)topic)
													 ,new FunctionArg(strlen(payload),(byte*)payload)
													 ,new FunctionArg(sizeof(byte),&qos)
													 ,new FunctionArg(sizeof(byte),(byte*)&retain));
}

void IOTShield::publish(String topic, String payload,byte qos,bool retain)
{
	publish(&topic[0],&payload[0],qos,retain);
}

void IOTShield::publish(const char * topic,byte * payload,byte payloadLength,byte qos,bool retain)
{
	if(qos > 2)qos = 2;
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_PUBLISH_RAW,4,new FunctionArg(strlen(topic),(byte*)topic)
													 ,new FunctionArg(payloadLength,payload)
													 ,new FunctionArg(sizeof(byte),&qos)
													 ,new FunctionArg(sizeof(byte),(byte*)&retain));
}

void IOTShield::publish(String topic,byte * payload,byte payloadLength,byte qos,bool retain)
{
	publish(&topic[0],payload,payloadLength,qos,retain);
}

void IOTShield::publish(const char * topic, int payload, byte qos,bool retain)
{
	if(qos > 2)qos = 2;
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_PUBLISH_INT,4,new FunctionArg(strlen(topic),(byte*)topic)
													 ,new FunctionArg(sizeof(int),(byte*)&payload)
													 ,new FunctionArg(sizeof(byte),&qos)
													 ,new FunctionArg(sizeof(byte),(byte*)&retain));
}

void IOTShield::publish(String topic, int payload, byte qos,bool retain)
{
	publish(&topic[0],payload,qos,retain);
}

void IOTShield::publish(const char * topic, unsigned int payload,byte qos,bool retain)
{
	if(qos > 2)qos = 2;
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_PUBLISH_UINT,4,new FunctionArg(strlen(topic),(byte*)topic)
													 ,new FunctionArg(sizeof(int),(byte*)&payload)
													 ,new FunctionArg(sizeof(byte),&qos)
													 ,new FunctionArg(sizeof(byte),(byte*)&retain));
}

void IOTShield::publish(String topic, unsigned int payload,byte qos,bool retain)
{
	publish(&topic[0],payload,qos,retain);
}

void IOTShield::publish(const char *topic, float payload ,byte qos,bool retain)
{
	if(qos > 2)qos = 2;
	byte floatBytes[4];
	OneSheeld.convertFloatToBytes(payload,floatBytes);
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_PUBLISH_FLOAT,4,new FunctionArg(strlen(topic),(byte*)topic)
													 ,new FunctionArg(sizeof(float),floatBytes)
													 ,new FunctionArg(sizeof(byte),&qos)
													 ,new FunctionArg(sizeof(byte),(byte*)&retain));
}

void IOTShield::publish(String topic, float payload ,byte qos,bool retain)
{
	publish(&topic[0],payload,qos,retain);
}

void IOTShield::subscribe(const char * topic,byte qos)
{
	if(qos > 2)qos = 2;
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_SUBSCRIBE,2,new FunctionArg(strlen(topic),(byte*)topic)
													 ,new FunctionArg(sizeof(byte),&qos));
}

void IOTShield::subscribe(String topic,byte qos)
{
	subscribe(&topic[0],qos);
}

void IOTShield::unsubscribe(const char *topic)
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_UNSUBSCRIBE,1,new FunctionArg(strlen(topic),(byte*)topic));
}

void IOTShield::unsubscribe(String topic)
{
	unsubscribe(&topic[0]);
}

void IOTShield::setOnConnectionStatusChange(void (userFunction)(byte))
{
	connectionStatusCallback = userFunction;
	isConnStatCallbackAssigned = true;
}
 
void IOTShield::setOnNewMessage(void (userFunction)(char * ,char *,byte ,bool))
{
	newMessageCallback = userFunction;
	isMessageCallbackAssigned= true;
}

void IOTShield::setOnNewMessageAsString(void (userFunction)(String ,String,byte,bool ))
{
	newMessageCallbackAsString = userFunction;
	isMessageStrCallbackAssigned= true;
}

void IOTShield::setOnError(void (userFunction)(byte))
{
	errorCallback = userFunction;
	isErrorCallbackAssigned = true;
}

void IOTShield::resetConnectionParametersToDefaults()
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_RESET_TO_DEFAULT,0);
}

//Process Input Data
void IOTShield::processData()
{
	byte functionID = getOneSheeldInstance().getFunctionId();

	if(functionID==IOT_GET_DATA)
	{
		char * topic = (char *)getOneSheeldInstance().getArgumentData(0);
		char * payload = (char *)getOneSheeldInstance().getArgumentData(1);
		byte qos = getOneSheeldInstance().getArgumentData(2)[0];
		bool retain = (bool)getOneSheeldInstance().getArgumentData(3)[0];
		//Invoke User Function
		if(!isInACallback())
		{
			if(isMessageCallbackAssigned)
			{
				enteringACallback();
				(*newMessageCallback)(topic,payload,qos,retain);
				exitingACallback();
			}else if (isMessageStrCallbackAssigned)
			{
				enteringACallback();
				(*newMessageCallbackAsString)(String(topic),String(payload),qos,retain);
				exitingACallback();
			}
		}
	}else if(functionID==IOT_GET_CONNECTION)
	{
		byte connectionStatus = getOneSheeldInstance().getArgumentData(0)[0];
		if(connectionStatus==CONNECTION_SUCCESSFUL)
		{
			isBrokerConnected = true;
		}else if (connectionStatus==CONNECTION_FAILED || connectionStatus==CONNECTION_LOST || connectionStatus==NOT_CONNECTED_YET)
		{
			isBrokerConnected = false;
		}
		//Invoke User Function
		if(!isInACallback())
		{
			if(isConnStatCallbackAssigned)
			{
				enteringACallback();
				(*connectionStatusCallback)(connectionStatus);
				exitingACallback();
			}
		}
	}
	else if(functionID==IOT_GET_ERROR && !isInACallback())
	{
		byte errorNumber=getOneSheeldInstance().getArgumentData(0)[0];
		//Invoke User Function
		if(isErrorCallbackAssigned)
		{
			enteringACallback();
			(*errorCallback)(errorNumber);
			exitingACallback();
		}
	}
}
