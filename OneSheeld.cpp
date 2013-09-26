/*
  OneSheeld.h - OneSheeld library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/


#include "OneSheeld.h"
#include "HardwareSerial.h"

// public functions
OneSheeldClass::OneSheeldClass() {}
void OneSheeldClass::begin(long baudRate)
{
  Serial.begin(baudRate);
}

void OneSheeldClass::write(char* data)
{
  write(GENERAL_DATA,NOT_FUNCTION,data);
}

// private functions 
// instantiate object for users
OneSheeldClass OneSheeld;