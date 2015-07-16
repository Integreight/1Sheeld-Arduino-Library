/*

  Project:       1Sheeld Library 
  File:          InteracticeShapeClass.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef InteracticeShapeClass_h
#define InteracticeShapeClass_h

#include "ShapeClass.h"

class InteractiveShapeClass : public ShapeClass
{
public:
	void setOnChange(void (*userFunction)(byte));
	friend class GLCDShield;
protected:	
	InteractiveShapeClass(byte ,int ,int);
	byte value;
	bool isCallBackAssigned;
private:
	void(*onChangeCallback)(byte);

};

#endif