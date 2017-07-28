//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Rectangle Class Header 
//
//****************************************************************************************

#include "../Vector/vector.h"

namespace Viper2D
{

// ----------------------------------------------------------------
//  Name:           
//	Class:			Rect
//  Description:    class for building a bounding box around a sprite and calculate the overlap
//  Arguments:      int left, int top, int right, int bottom
//  Return Value:   NONE
// ----------------------------------------------------------------	
class Rect//rectangle class for bounding box
{

private:
	double top;//top of bounding box
	double left;//left of bounding box
	double right;//right of bounding box
	double bottom;//bottom of bounding box


public:
	Rect(int left, int top, int right, int bottom);//constructor(integer input)
	Rect(double left, double top, double right, double bottom);//constructor(double input)

	double getTop();//get top of box
	double getLeft();//get left side of box
	double getRight();//get right side of box
	double getBottom();//get bottom side of box
	double getWidth();//get width of the box
	double getHeight();//get height of box 
	
	void setTop(double input);//set top side of box
	void setLeft(double input);//set left side of box
	void setRight(double input);//set right side of box
	void setBottom(double input);//set the bottom side of the box
	
	
	

	bool isInside(_vector point);//check to see if vector is inside of box
	bool isInside(int x, int y);//check to see if cordinates is inside of box(integer input)
	bool isInside(double x, double y);//check to see if cordinates is inside of box(double input)

};
};