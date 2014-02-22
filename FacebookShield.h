/*
  FacebookShield.h - FacebookShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/
#ifndef FacebookShield_h
#define FacebookShield_h

// library defintions
#define UPDATE_STATUS 0x01  
#define SEND_DIRECT_MESSAGE 0x02

class FacebookShieldClass 
{
public:
void updateStatus(char* );
void sendDirectMessage(char *,char* );

private:



};
// instantiate object for users
extern FacebookShieldClass Facebook;
#endif