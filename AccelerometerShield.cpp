/*
  AccelerometerShield.h - AccelerometerShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#include "OneSheeld.h"
#include "AccelerometerShield.h"
#include "ReadPWMClass.h"

// public functions
AccelerometerShieldClass::AccelerometerShieldClass() {}
unsigned int AccelerometerShieldClass::readValue(int pin)
{
    return PWM.readValue(pin);
}
// instantiate object for users
AccelerometerShieldClass Accelerometer;