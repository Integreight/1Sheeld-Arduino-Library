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
	OneSheeld.sendShieldFrame(GLCD_ID,0,GLCD_TYPE,1,new FunctionArg(1,&functionId));	
}

void GLCDShield::draw(ShapeClass &usersShape)
{
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
     
     for(int i = 0 ; i<MAX_NO_OF_SHAPE_USED ;i++)
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
