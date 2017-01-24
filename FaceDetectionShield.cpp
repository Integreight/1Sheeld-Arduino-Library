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


Face FaceDetectionShield::getFace(int _faceID)
{
	for(int i=0 ;i <counter ;i++)
	{
		if(facesArray[i].faceID == _faceID && _faceID!=-1)
		{
			return facesArray[i];
		}
	}

	Face nullFace;
	return nullFace;
}

Face FaceDetectionShield::getVisibleFace(byte number)
{
	if(number <MAX_FACES && facesArray[number].faceID >=0)
	{
		return facesArray[number];
	}else
	{
		Face nullFace;
		return nullFace;
	}		
}

bool FaceDetectionShield::isFaceVisible(int _faceID)
{
	for(int i=0 ;i <counter ;i++)
	{
		if(facesArray[i].faceID == _faceID && _faceID!=-1)
		{
			return true;
		}
	}
	return false;	
}

byte FaceDetectionShield::getVisibleFacesCount()
{

	return counter;
}

void FaceDetectionShield::processData()
{
	byte functionId = getOneSheeldInstance().getFunctionId();

	if(functionId == FACE_GET)
	{
		int currentFaceID = getOneSheeldInstance().getArgumentData(0)[0]|((getOneSheeldInstance().getArgumentData(0)[1])<<8);
		int currentX = getOneSheeldInstance().getArgumentData(1)[0]|((getOneSheeldInstance().getArgumentData(1)[1])<<8);
		int currentY = getOneSheeldInstance().getArgumentData(1)[2]|((getOneSheeldInstance().getArgumentData(1)[3])<<8);
		unsigned int currentHeight = getOneSheeldInstance().getArgumentData(2)[0]|((getOneSheeldInstance().getArgumentData(2)[1])<<8);
		unsigned int currentWidth = getOneSheeldInstance().getArgumentData(2)[2]|((getOneSheeldInstance().getArgumentData(2)[3])<<8);
		int i;
		byte currentRightEye = getOneSheeldInstance().getArgumentData(3)[0];
		byte currentLeftEye = getOneSheeldInstance().getArgumentData(3)[1];
		byte currentSmile = getOneSheeldInstance().getArgumentData(3)[2];

		for(i =0 ;i <MAX_FACES;i++)
		{
			if(facesArray[i].faceID==currentFaceID)
			{
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
			while(facesArray[i].faceID>= 0 && i<MAX_FACES)
			{
				i++;
			}
			facesArray[i].faceID = currentFaceID;
			facesArray[i].leftEyeOpened = currentLeftEye;
			facesArray[i].rightEyeOpened = currentRightEye;
			facesArray[i].smiling = currentSmile;
			facesArray[i].xCoordinate = currentX;
			facesArray[i].yCoordinate = currentY;
			facesArray[i].faceWidth = currentWidth;
			facesArray[i].faceHeight = currentHeight;
			counter++;
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
		int currentFaceID = getOneSheeldInstance().getArgumentData(0)[0]|((getOneSheeldInstance().getArgumentData(0)[1])<<8);
		for( int i =0 ;i <MAX_FACES;i++)
		{
			if(facesArray[i].faceID==currentFaceID)
			{
				eraseFaceData(i);
				if(counter!=0){counter--;}
				break;
			}
		}
		rearrangeFaces();
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
	facesArray[i].faceID = -1;
	facesArray[i].leftEyeOpened = -1;
	facesArray[i].rightEyeOpened = -1;
	facesArray[i].smiling = -1;
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

void FaceDetectionShield::rearrangeFaces()
{
	for(int i=0;i<MAX_FACES;i++)
	{
		if(facesArray[i].faceID<0)
		{
			int j = i+1;
			while(facesArray[j].faceID<0 && j<MAX_FACES){j++;}
			if(j==MAX_FACES)
			{
				break;
			}else
			{
				facesArray[i]=facesArray[j];
				eraseFaceData(j);
			}
		}
	}
}