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
	callbacksAssignments=0;
	isBrokerConnected = false;
    isConnStatCallbackAssigned = false;
  	isErrorCallbackAssigned = false;
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

void IOTShield::setPort(unsigned int portNumber)
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

void IOTShield::setLastWillAndTestament(const char * willTopic,const char * willMessage,byte willQos,bool willRetained)
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_LAST_WILL,4,new FunctionArg(strlen(willTopic),(byte*)willTopic)
												 ,new FunctionArg(strlen(willMessage),(byte*)willMessage)
												 ,new FunctionArg(sizeof(byte),&willQos)
												 ,new FunctionArg(sizeof(byte),(byte*)&willRetained));
}

void IOTShield::setLastWillAndTestament(String willTopic,String willMessage,byte willQos,bool willRetained)
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

void IOTShield::setSecureConnection(bool state)
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_SSL_CONNECTION,1,new FunctionArg(sizeof(bool),(byte*)&state));		
}

void IOTShield::connect()
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_CONNECT,0);				
}

void IOTShield::connect(const char * host)
{
	byte hostLength = strlen(host);	
	if(hostLength)
	{
		OneSheeld.sendShieldFrame(IOT_ID,0,IOT_CONNECT,1,new FunctionArg(hostLength,(byte*)host));	
	}
	
}

void IOTShield::connect(String host)
{
	connect(&host[0]);
}

void IOTShield::connect(const char * host,unsigned int portNumber)
{
	byte hostLength = strlen(host);	
	if(hostLength)
	{
		OneSheeld.sendShieldFrame(IOT_ID,0,IOT_CONNECT,2,new FunctionArg(hostLength,(byte*)host)
												,new FunctionArg(sizeof(int),(byte*)&portNumber));	
	}
	
}

void IOTShield::connect(String host,unsigned int portNumber)
{
	connect(&host[0],portNumber);
}

void IOTShield::connect(const char * host,unsigned int portNumber,bool connectSSL)
{
	byte hostLength = strlen(host);	
	if(hostLength)
	{
		OneSheeld.sendShieldFrame(IOT_ID,0,IOT_CONNECT,3,new FunctionArg(hostLength,(byte*)host)
												,new FunctionArg(sizeof(int),(byte*)&portNumber)
												,new FunctionArg(sizeof(bool),(byte*)&connectSSL));	
	}
	
}

void IOTShield::connect(String host,unsigned int portNumber,bool connectSSL)
{
	connect(&host[0],portNumber,connectSSL);
}

void IOTShield::connect(const char * host, const char * userName, const char *password,unsigned int portNumber)
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

void IOTShield::connect(String host,String userName,String password,unsigned int portNumber)
{
	connect(&host[0],&userName[0],&password[0],portNumber);
}

void IOTShield::disconnect()
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_DISCONNECT,0);
	isBrokerConnected=false;	
}

void IOTShield::publish(const char * topic,byte * payload,byte payloadLength,byte qos,bool retain)
{
	if(qos > 2)qos = 2;
	if(payloadLength==0)
	{
		OneSheeld.sendShieldFrame(IOT_ID,0,IOT_PUBLISH_EMPTY,3,new FunctionArg(strlen(topic),(byte*)topic)
															  ,new FunctionArg(sizeof(byte),&qos)
													 		  ,new FunctionArg(sizeof(byte),(byte*)&retain));
	}else
	{
		OneSheeld.sendShieldFrame(IOT_ID,0,IOT_PUBLISH,4,new FunctionArg(strlen(topic),(byte*)topic)
													 ,new FunctionArg(payloadLength,payload)
													 ,new FunctionArg(sizeof(byte),&qos)
													 ,new FunctionArg(sizeof(byte),(byte*)&retain));
	}
}

void IOTShield::publish(const char * topic,const char * payload,byte qos,bool retain)
{
	publish(topic,(byte*)payload,strlen(payload),qos,retain);
}

void IOTShield::publish(const char * topic, int payload, byte qos,bool retain)
{
	publish(topic,(byte*)&payload,2,qos,retain);
}

void IOTShield::publish(const char * topic, unsigned int payload,byte qos,bool retain)
{
	publish(topic,(byte*)&payload,2,qos,retain);
}

void IOTShield::publish(const char *topic, float payload ,byte qos,bool retain)
{
	byte floatBytes[4];
	OneSheeld.convertFloatToBytes(payload,floatBytes);
	publish(topic,(byte*)floatBytes,4,qos,retain);
}

void IOTShield::publish(String topic,byte * payload,byte payloadLength,byte qos,bool retain)
{
	publish(&topic[0],payload,payloadLength,qos,retain);
}

void IOTShield::publish(String topic, String payload,byte qos,bool retain)
{
	publish(&topic[0],(byte*)&payload[0],payload.length(),qos,retain);
}

void IOTShield::publish(String topic, int payload, byte qos,bool retain)
{
	publish(&topic[0],(byte*)&payload,2,qos,retain);
}

void IOTShield::publish(String topic, unsigned int payload,byte qos,bool retain)
{
	publish(&topic[0],(byte*)&payload,2,qos,retain);
}

void IOTShield::publish(String topic, float payload ,byte qos,bool retain)
{
	byte floatBytes[4];
	OneSheeld.convertFloatToBytes(payload,floatBytes);
	publish(&topic[0],(byte*)floatBytes,4,qos,retain);
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

void IOTShield::unsubscribe()
{
	OneSheeld.sendShieldFrame(IOT_ID,0,IOT_UNSUBSCRIBE,0);
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
	newMessageCharCharCallback = userFunction;
	callbacksAssignments= callbacksAssignments|(1<<CHAR_CHAR);
}

void IOTShield::setOnNewMessage(void (userFunction)(char * ,int,byte ,bool))
{
	newMessageCharIntCallback = userFunction;
	callbacksAssignments= callbacksAssignments|(1<<CHAR_INT);
}

void IOTShield::setOnNewMessage(void (userFunction)(char * ,unsigned int,byte ,bool))
{
	newMessageCharUnIntCallback = userFunction;
	callbacksAssignments= callbacksAssignments|(1<<CHAR_UNINT);
}

void IOTShield::setOnNewMessage(void (userFunction)(char * ,float,byte ,bool))
{
	newMessageCharFloatCallback = userFunction;
	callbacksAssignments= callbacksAssignments|(1<<CHAR_FLOAT);
}

void IOTShield::setOnNewMessage(void (userFunction)(char * ,byte *,byte,byte ,bool))
{
	newMessageCharRawCallback = userFunction;
	callbacksAssignments= callbacksAssignments|(1<<CHAR_RAW);
}

void IOTShield::setOnNewMessage(void (userFunction)(String ,String,byte,bool ))
{
	newMessageStrStrCallback= userFunction;
	callbacksAssignments= callbacksAssignments|(1<<STRING_STRING);
}

void IOTShield::setOnNewMessage(void (userFunction)(String ,int ,byte,bool ))
{
	newMessageStrIntCallback= userFunction;
	callbacksAssignments= callbacksAssignments|(1<<STRING_INT);
}

void IOTShield::setOnNewMessage(void (userFunction)(String ,unsigned int ,byte,bool ))
{
	newMessageStrUnIntCallback= userFunction;
	callbacksAssignments= callbacksAssignments|(1<<STRING_UNINT);
}

void IOTShield::setOnNewMessage(void (userFunction)(String ,float ,byte,bool ))
{
	newMessageStrFloatCallback= userFunction;
	callbacksAssignments= callbacksAssignments|(1<<STRING_FLOAT);
}

void IOTShield::setOnNewMessage(void (userFunction)(String ,byte *,byte ,byte,bool ))
{
	newMessageStrRawCallback= userFunction;
	callbacksAssignments= callbacksAssignments|(1<<STRING_RAW);
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
		byte topicLength = getOneSheeldInstance().getArgumentLength(0);
		char topic[topicLength+1];
		for(int i=0;i<topicLength;i++)
		{
			topic[i]=getOneSheeldInstance().getArgumentData(0)[i];
		}
		topic[topicLength]='\0';
		byte qos = getOneSheeldInstance().getArgumentData(2)[0];
		bool retain = (bool)getOneSheeldInstance().getArgumentData(3)[0];
		//Invoke User Function
		if(!isInACallback())
		{
			if((bool)callbacksAssignments)
			{
				enteringACallback();
			}

			if(callbacksAssignments&(1<<CHAR_CHAR))
			{
				byte payloadLength = getOneSheeldInstance().getArgumentLength(1);
				char payload[payloadLength+1];
				for(int i=0;i<payloadLength;i++)
				{
					payload[i]=getOneSheeldInstance().getArgumentData(1)[i];
				}
				payload[payloadLength]='\0';
				(*newMessageCharCharCallback)(topic,payload,qos,retain);
			}
			if(callbacksAssignments&(1<<CHAR_INT) && (getOneSheeldInstance().getArgumentLength(1) == 2))
			{
				int payload = getOneSheeldInstance().getArgumentData(1)[0]|((getOneSheeldInstance().getArgumentData(1)[1])<<8);
				(*newMessageCharIntCallback)(topic,payload,qos,retain);
			}
			if(callbacksAssignments&(1<<CHAR_UNINT) && (getOneSheeldInstance().getArgumentLength(1) == 2))
			{
				unsigned int payload = getOneSheeldInstance().getArgumentData(1)[0]|((getOneSheeldInstance().getArgumentData(1)[1])<<8);
				(*newMessageCharUnIntCallback)(topic,payload,qos,retain);
			}
			if(callbacksAssignments&(1<<CHAR_FLOAT) && (getOneSheeldInstance().getArgumentLength(1) == 4))
			{
				float payload = OneSheeld.convertBytesToFloat(getOneSheeldInstance().getArgumentData(1));
				(*newMessageCharFloatCallback)(topic,payload,qos,retain);
			}
			if(callbacksAssignments&(1<<CHAR_RAW))
			{
				byte * payload = getOneSheeldInstance().getArgumentData(1);
				byte payloadLength = getOneSheeldInstance().getArgumentLength(1);
				(*newMessageCharRawCallback)(topic,payload,payloadLength,qos,retain);
			}
			if(callbacksAssignments&(1<<STRING_STRING))
			{
				byte payloadLength = getOneSheeldInstance().getArgumentLength(1);
				char payload[payloadLength+1];
				for(int i=0;i<payloadLength;i++)
				{
					payload[i]=getOneSheeldInstance().getArgumentData(1)[i];
				}
				payload[payloadLength]='\0';
				(*newMessageStrStrCallback)(String(topic),String(payload),qos,retain);
			}
			if(callbacksAssignments&(1<<STRING_INT) && (getOneSheeldInstance().getArgumentLength(1) == 2))
			{
				int payload = getOneSheeldInstance().getArgumentData(1)[0]|((getOneSheeldInstance().getArgumentData(1)[1])<<8);
				(*newMessageStrIntCallback)(String(topic),payload,qos,retain);
			}
			if(callbacksAssignments&(1<<STRING_UNINT) && (getOneSheeldInstance().getArgumentLength(1) == 2))
			{
				unsigned int payload = getOneSheeldInstance().getArgumentData(1)[0]|((getOneSheeldInstance().getArgumentData(1)[1])<<8);
				(*newMessageStrUnIntCallback)(String(topic),payload,qos,retain);
			}
			if(callbacksAssignments&(1<<STRING_FLOAT) && (getOneSheeldInstance().getArgumentLength(1) == 4))
			{
				float payload = OneSheeld.convertBytesToFloat(getOneSheeldInstance().getArgumentData(1));
				(*newMessageStrFloatCallback)(String(topic),payload,qos,retain);
			}
			if(callbacksAssignments&(1<<STRING_RAW))
			{
				byte * payload = getOneSheeldInstance().getArgumentData(1);
				byte payloadLength = getOneSheeldInstance().getArgumentLength(1);
				(*newMessageStrRawCallback)(String(topic),payload,payloadLength,qos,retain);
			}

			if((bool)callbacksAssignments)
			{
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
