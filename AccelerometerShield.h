/*
  AccelerometerShield.h - AccelerometerShield library
  Copyright (C) 2013 Integreight Inc  All rights reserved.
*/

#ifndef AccelerometerShield_h
#define AccelerometerShield_h

// library defintions
#define ACCELEROMETER_ID 0x33  // twitter shield id 

class AccelerometerShieldClass
{
public:
    AccelerometerShieldClass();
    unsigned int readValue(int pin);
private:
};
// instantiate object for users
extern AccelerometerShieldClass Accelerometer;
#endif