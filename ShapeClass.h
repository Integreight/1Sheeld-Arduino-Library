/*

  Project:       1Sheeld Library 
  File:          Shape.h
                 
  Version:       7.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2015.7

*/

#ifndef ShapeClass_h
#define ShapeClass_h

#define SHAPE_DRAW 			0x00
#define SHAPE_POSITION		0x01
#define SHAPE_VISIBILITY	0x02

class ShapeClass
{
public:
	virtual void setVisibility(byte);
	virtual void setPosition(int ,int );
friend class GLCDShield;
protected:	
	ShapeClass(byte,int,int);
	int shapeID;
	byte shapeType;
	int xposition;
	int yposition;
	bool isInteractiveShape;
	virtual void draw()=0;

private:
	static int currentShapeId;


};

#endif