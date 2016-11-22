/*

  Project:       1Sheeld Library 
  File:          FaceDetectionShield.h
                 
  Version:       1.11.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.11

*/
#ifndef FaceDetectionShield_h
#define FaceDetectionShield_h

#include "ShieldParent.h"

//Output Function ID


//Input Function ID
#define FACE_GET            0x01
#define FACE_OUT_OF_BOUNDS  0x02

//Literals
#define MAX_FACES 20


struct Face{
  bool visible;
  byte leftEyeOpened;
  byte rightEyeOpened;
  byte smiling;
  int  xCoordinate;
  int  yCoordinate;
  unsigned int faceID;
  unsigned int faceWidth;
  unsigned int faceHeight;



  Face()
  {
    visible = false;
    leftEyeOpened = 0;
    rightEyeOpened = 0;
    smiling = 0;
    xCoordinate = 0;
    yCoordinate = 0;
    faceID = 0;
    faceWidth = 0;
    faceHeight = 0;    
  }

  bool isVisible()
  {
    return visible;
  }

  byte getSmileProbability() 
  {
      return smiling;
  }

  byte getIsLeftEyeOpenedProbability() 
  {
      return leftEyeOpened;
  }

  byte getIsRightEyeOpenedProbability() 
  {
      return rightEyeOpened;
  }

  int  getXCoordinate() 
  {
      return xCoordinate;
  }

  int  getYCoordinate() 
  {
      return yCoordinate;
  }

  unsigned int getFaceID()
  {
    return faceID;
  }

  unsigned int  getFaceWidth()
  {
    return faceWidth;
  }

  unsigned int getFaceHeight()
  {
    return faceHeight;
  }
};



class FaceDetectionShield : public ShieldParent
{
public:
	FaceDetectionShield();
  Face getFace(byte);
  void setOnNewFace(void (*)(Face));
  void setOnNotVisible(void (*)(int ));
	
private:
  bool isCallBackAssigned;
  bool isdeletedAssigned;
  void eraseFaceData(byte);
	void processData();
  Face facesArray[MAX_FACES];
  void (*onNewFaceCallback)(Face);
  void (*onDeletedFaceCallback)(int);
};

extern FaceDetectionShield FaceDetector;
#endif