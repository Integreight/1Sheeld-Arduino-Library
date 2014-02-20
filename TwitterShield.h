/*
  TwitterShield.h - TwitterShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#ifndef TwitterShield_h
#define TwitterShield_h

// library defintions
#define SEND_TWEET 0x01  // sendTweet function command
#define SEND_DIRECT_MESSAGE 0x02  // send direct message function command

class TwitterShieldClass 
{
public:
void updateStatus(char* );
void sendDirectMessage(char* ,char* );
private:



};
// instantiate object for users
extern TwitterShieldClass Twitter;
#endif