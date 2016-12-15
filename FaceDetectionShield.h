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
  int leftEyeOpened;
  int rightEyeOpened;
  int smiling;
  int  xCoordinate;
  int  yCoordinate;
  int faceID;
  unsigned int faceWidth;
  unsigned int faceHeight;

  Face()
  {
    faceID = -1;
    leftEyeOpened = -1;
    rightEyeOpened = -1;
    smiling = -1;
    xCoordinate = 0;
    yCoordinate = 0;
    faceWidth = 0;
    faceHeight = 0;    
  }

  int getSmileProbability() 
  {
      return smiling;
  }

  int getLeftEyeOpenProbability() 
  {
      return leftEyeOpened;
  }

  int getRightEyeOpenProbability() 
  {
      return rightEyeOpened;
  }

  int  getXCoordinates() 
  {
      return xCoordinate;
  }

  int  getYCoordinates() 
  {
      return yCoordinate;
  }

  int getID()
  {
    return faceID;
  }

  unsigned int  getWidth()
  {
    return faceWidth;
  }

  unsigned int getHeight()
  {
    return faceHeight;
  }
};



class FaceDetectionShield : public ShieldParent
{
public:
	FaceDetectionShield();
  Face getVisibleFace(byte);
  Face getFace(int);
  byte getVisibleFacesCount();
  bool isFaceVisible(int);
  void setOnNewFace(void (*)(Face));
  void setOnNotVisible(void (*)(int ));
	
private:
  bool isCallBackAssigned;
  bool isdeletedAssigned;
  byte counter;
  void eraseFaceData(byte);
	void processData();
  Face facesArray[MAX_FACES];
  void (*onNewFaceCallback)(Face);
  void (*onDeletedFaceCallback)(int);
  void rearrangeFaces();
};

extern FaceDetectionShield FaceDetector;
#endif