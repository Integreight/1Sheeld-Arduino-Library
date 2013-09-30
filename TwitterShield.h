/*
  TwitterShield.h - TwitterShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#ifndef TwitterShield_h
#define TwitterShield_h

// library defintions
#define TWITTER_ID 0x30  // twitter shield id 
#define SEND_TWEET 0x01  // sendTweet function command
#define SEND_DIRECT_MESSAGE 0x02  // send direct message function command

class TwitterShieldClass 
{
public:
TwitterShieldClass();
void updateStatus(char* data);
void sendDirectMessage(char* username,char* message);
private:



};
// instantiate object for users
extern TwitterShieldClass Twitter;
#endif