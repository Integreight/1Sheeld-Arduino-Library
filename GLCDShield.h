/*

  Project:       1Sheeld Library 
  File:          GLCDShield.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef GLCDShield_h
#define GLCDShield_h

#define GLCD_TYPE			            0x00
#define GLCD_CLEAR			          0x00

#define GLCD_GET_DATA_FROM_SHAPE  0x01   

#define MAX_NO_OF_SHAPE_USED  32

#include "ShieldParent.h"
#include "ShapeClass.h"
#include "GLCDPoint.h"
#include "GLCDRectangle.h"
#include "GLCDLine.h"
#include "GLCDEllipse.h"
#include "GLCDTextBox.h"
#include "GLCDProgressBar.h"
#include "GLCDAnalogGauge.h"
#include "GLCDButton.h"
#include "GLCDRadioButton.h"  
#include "GLCDCheckBox.h"
#include "GLCDSlider.h"

class GLCDShield : public ShieldParent
{
public:
	GLCDShield();
	void clear();
  void draw(ShapeClass &);
private:
  ShapeClass * interactiveShapesArray[MAX_NO_OF_SHAPE_USED];
  bool addToShapesArray(ShapeClass &);
  void processData();
};
extern GLCDShield GLCD;
#endif