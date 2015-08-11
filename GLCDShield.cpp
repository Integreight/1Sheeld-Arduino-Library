/*

  Project:       1Sheeld Library 
  File:          GLCDShield.cpp
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "GLCDShield.h"

GLCDShield::GLCDShield() : ShieldParent(GLCD_ID)
{
  for(int i=0;i<MAX_NO_OF_SHAPE_USED;i++){
    interactiveShapesArray[i]=NULL;
  }
}


void GLCDShield::clear()
{
	byte functionId = GLCD_CLEAR;
	OneSheeld.sendPacket(GLCD_ID,0,GLCD_TYPE,1,new FunctionArg(1,&functionId));	
}

void GLCDShield::clear(int xPosition, int yPosition, int width, int height)
{
	byte xPositionArray[2] ;
  	xPositionArray[1] = (xPosition >> 8) & 0xFF;
  	xPositionArray[0] = xPosition & 0xFF;

  	byte yPositionArray[2] ;
  	yPositionArray[1] = (yPosition >> 8) & 0xFF;
  	yPositionArray[0] = yPosition & 0xFF;

  	byte widthArray[2] ;
  	widthArray[1] = (width >> 8) & 0xFF;
  	widthArray[0] = width & 0xFF;

  	byte heightArray[2] ;
  	heightArray[1] = (height >> 8) & 0xFF;
  	heightArray[0] = height & 0xFF;

  	byte functionId = GLCD_CUSTOM_CLEAR;
  	OneSheeld.sendPacket(GLCD_ID,0,GLCD_TYPE,5,new FunctionArg(1,&functionId),new FunctionArg(2,xPositionArray)
  																				   ,new FunctionArg(2,yPositionArray)
  																				   ,new FunctionArg(2,widthArray)
  																				   ,new FunctionArg(2,heightArray));
}


void GLCDShield::draw(ShapeClass &usersShape)
{
  byte currentShapeType = usersShape.shapeType;

  if(usersShape.isInteractiveShape)
  {
    bool shapeIsAdded = addToShapesArray(usersShape);
    if(shapeIsAdded)  usersShape.draw();
  }
  else
  {
    usersShape.draw(); 
  }
  
}

bool GLCDShield::addToShapesArray(ShapeClass & shape)
{
  int i;
    for (i = 0; i < MAX_NO_OF_SHAPE_USED; i++)
    {
      if(interactiveShapesArray[i]==NULL)break;
    }

    if(i>=MAX_NO_OF_SHAPE_USED)return false;
    else
    {
      interactiveShapesArray[i]= &shape;
      return true;
    }
}

void GLCDShield::processData()
{
   byte functionId = getOneSheeldInstance().getArgumentData(0)[0];

   if(functionId == GLCD_GET_DATA_FROM_SHAPE)
   {
     int shapeId =(getOneSheeldInstance().getArgumentData(1)[0] | ((getOneSheeldInstance().getArgumentData(1)[1])<<8));

     byte incomingShapeType = getOneSheeldInstance().getFunctionId();
     
     for(int i ; i<MAX_NO_OF_SHAPE_USED ;i++)
     {
       if(interactiveShapesArray[i] != NULL && interactiveShapesArray[i]->shapeID == shapeId  && interactiveShapesArray[i]->shapeType == incomingShapeType)
       {
         switch(incomingShapeType)
         {
           case GLCD_BUTTON_TYPE :  {

                                          bool incomingButtonValue =  getOneSheeldInstance().getArgumentData(2)[0];
                                          GLCDButton * buttonPointer = ((GLCDButton*)(interactiveShapesArray[i]));
                                          buttonPointer->value = incomingButtonValue;
                                          if(buttonPointer->isCallBackAssigned && !isInACallback())
                                          {
                                              enteringACallback();
                                              buttonPointer->onChangeCallback(incomingButtonValue);
                                              exitingACallback();
                                          }
                                       break;
                                    }

          case GLCD_RADIO_BUTTON_TYPE : {
                                          bool incomingRadioButtonValue =  getOneSheeldInstance().getArgumentData(2)[0];
                                          GLCDRadioButton * radioButtonPointer = ((GLCDRadioButton *)(interactiveShapesArray[i])); 
                                          radioButtonPointer->value = incomingRadioButtonValue;
                                          if(radioButtonPointer->isCallbackAssigned && !isInACallback())
                                          {
                                              enteringACallback();
                                              radioButtonPointer->onChangeCallback(incomingRadioButtonValue);
                                              exitingACallback();
                                          }
                                          break;
                                        }

          case GLCD_CHECK_BOX_TYPE : { 
                                        bool incomingCheckBoxValue =  getOneSheeldInstance().getArgumentData(2)[0];
                                        GLCDCheckBox * checkBoxPointer = ((GLCDCheckBox *)(interactiveShapesArray[i]));
                                        checkBoxPointer->value = incomingCheckBoxValue;
                                        if(checkBoxPointer->isCallbackAssigned && !isInACallback())
                                        {
                                            enteringACallback();
                                            checkBoxPointer->onChangeCallback(incomingCheckBoxValue);
                                            exitingACallback();
                                        }
                                        break;
                                      }

          case GLCD_SLIDER_TYPE : { 
                                    int incomingSliderValue =(getOneSheeldInstance().getArgumentData(2)[0] | ((getOneSheeldInstance().getArgumentData(2)[1])<<8));
                                    GLCDSlider * sliderPointer = ((GLCDSlider *)(interactiveShapesArray[i]));
                                    sliderPointer->value = incomingSliderValue;
                                    if(sliderPointer->isCallbackAssigned && !isInACallback())
                                    {
                                        enteringACallback();
                                        sliderPointer->onChangeCallback(incomingSliderValue);
                                        exitingACallback();
                                    }
                                    break;
                                  }
        }
        break;
      }
    }
  }
}
