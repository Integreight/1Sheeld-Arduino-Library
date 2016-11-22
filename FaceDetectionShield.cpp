/*

  Project:       1Sheeld Library 
  File:          FaceDetectionShield.cpp
                 
  Version:       1.11.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2016.11

*/
#define FROM_ONESHEELD_LIBRARY
#include "OneSheeld.h"
#include "FaceDetectionShield.h"



FaceDetectionShield::FaceDetectionShield() : ShieldParent(FACE_DETECTOR_ID)
{}


Face FaceDetectionShield::getFace(byte numberOfFace)
{
	return facesArray[numberOfFace];
}

void FaceDetectionShield::processData()
{
	byte functionId = getOneSheeldInstance().getFunctionId();

	if(functionId == FACE_GET)
	{
		unsigned int currentFaceID = getOneSheeldInstance().getArgumentData(0)[0]|((getOneSheeldInstance().getArgumentData(0)[1])<<8);
		int currentX = getOneSheeldInstance().getArgumentData(1)[0]|((getOneSheeldInstance().getArgumentData(1)[1])<<8);
		int currentY = getOneSheeldInstance().getArgumentData(1)[2]|((getOneSheeldInstance().getArgumentData(1)[3])<<8);
		unsigned int currentHeight = getOneSheeldInstance().getArgumentData(2)[0]|((getOneSheeldInstance().getArgumentData(2)[1])<<8);
		unsigned int currentWidth = getOneSheeldInstance().getArgumentData(2)[2]|((getOneSheeldInstance().getArgumentData(2)[3])<<8);
		int i;
		byte currentLeftEye = getOneSheeldInstance().getArgumentData(3)[0];
		byte currentRightEye = getOneSheeldInstance().getArgumentData(3)[1];
		byte currentSmile = getOneSheeldInstance().getArgumentData(3)[2];

		for(i =0 ;i <MAX_FACES;i++)
		{
			if(facesArray[i].faceID==currentFaceID)
			{
				facesArray[i].visible = true;
				facesArray[i].leftEyeOpened = currentLeftEye;
				facesArray[i].rightEyeOpened = currentRightEye;
				facesArray[i].smiling = currentSmile;
				facesArray[i].xCoordinate = currentX;
				facesArray[i].yCoordinate = currentY;
				facesArray[i].faceWidth = currentWidth;
				facesArray[i].faceHeight = currentHeight;
				break;
			}
		}

		if(i == MAX_FACES)
		{
			i=0;
			while(facesArray[i].faceID!=0)
			{
				i++;
			}
			facesArray[i].visible= true;
			facesArray[i].faceID = currentFaceID;
			facesArray[i].leftEyeOpened = currentLeftEye;
			facesArray[i].rightEyeOpened = currentRightEye;
			facesArray[i].smiling = currentSmile;
			facesArray[i].xCoordinate = currentX;
			facesArray[i].yCoordinate = currentY;
			facesArray[i].faceWidth = currentWidth;
			facesArray[i].faceHeight = currentHeight;
		}
		
		if(!isInACallback())
		{
			if(onNewFaceCallback)
			{
				enteringACallback();
				(*onNewFaceCallback)(facesArray[i]);
				exitingACallback();
			}
		}
	}else if(functionId == FACE_OUT_OF_BOUNDS)
	{
		int i;
		unsigned int currentFaceID = getOneSheeldInstance().getArgumentData(0)[0]|((getOneSheeldInstance().getArgumentData(0)[1])<<8);
		for( i =0 ;i <MAX_FACES;i++)
		{
			if(facesArray[i].faceID==currentFaceID)
			{
				eraseFaceData(i);
				break;
			}
		}

		if(!isInACallback())
		{
			if(isdeletedAssigned)
			{
				enteringACallback();
				(*onDeletedFaceCallback)(currentFaceID);
				exitingACallback();
			}
		}
	}
}

void FaceDetectionShield::eraseFaceData(byte i)
{
	facesArray[i].visible = false;
	facesArray[i].faceID = 0;
	facesArray[i].leftEyeOpened = 0;
	facesArray[i].rightEyeOpened = 0;
	facesArray[i].smiling = 0;
	facesArray[i].xCoordinate = 0;
	facesArray[i].yCoordinate = 0;
	facesArray[i].faceWidth = 0;
	facesArray[i].faceHeight = 0;
}


//Users Function Setter return String data 
void FaceDetectionShield::setOnNewFace(void (*userFunction)(Face myFace))
{
	onNewFaceCallback=userFunction;
	isCallBackAssigned=true;
}

void FaceDetectionShield::setOnNotVisible(void (*userFunction)(int id))
{
	onDeletedFaceCallback=userFunction;
	isdeletedAssigned=true;
}