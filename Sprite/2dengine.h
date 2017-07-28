//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: 2D Class Header 
//
//****************************************************************************************
#pragma once//one instance of this file


#include "../Viper2D/Viper2D.h"//viper class
#include "../Texture/Texture.h"//texture class
#include "../Vector/Vector.h"//vector class




namespace Viper2D//viper2d namspace
{


// ----------------------------------------------------------------
//	Enum			Collision
//  Description:    collision modes
//  Arguments:      NONE
//  Return Value:   NONE
// ----------------------------------------------------------------	
	enum Collision//collision mode structure
{
	COLLISION_NONE = 0,//collision doesn't effect
	COLLISION_RECT = 1,//bounding box collision detection
	COLLISION_DIST = 2//bounding circle collision detection
};

// ----------------------------------------------------------------
//	Class:			_2DEngine
//  Description:    Sprite Class
//  Arguments:      NONE
//  Return Value:   NONE
// ----------------------------------------------------------------	
	class _2DEngine:public cBaseEntity//sprite class with base inheritance with the entity class
{
public:
	_2DEngine();//constructor
	~_2DEngine();//deconstructor
	void Free();//function to free objects from the heap
	
	//methods
	void setSize(int width,int height);//set size of the 2d object 
	int getWidth();//get width of the 2d object
	int getHeight();//get height of the 2d object
	void setWidth(int width);//set the width of the 2d object
	void setHeight(int height);//set the height of the 2d object
	int checkState();//check the state of the object
	void setState(int value);//set the state of the object
	bool loadImage(char *filename, D3DCOLOR color = D3DCOLOR_XRGB(255,0,255));//load image
	void setImage(Texture *image);//set an image to an object
	void transform();//function to calculate the 2d transformation from world space to 2d space
	void draw();//draw 2d object based on attributes
	void move();//sets the new cordinates for object to move
	void animate();//aniamate object based on current sprite sheet frame
	void setMoveClock(int value);//set the timer for movement speed
	int getMoveClock();//get the current time set for movement speed
	void setColor(D3DCOLOR color);//set transparency color to cover outer edge of object
	void setScale(double value);//set scale of the 2d object
	double getScale();//get the scale of the 2d object
	void setRotation(double value);//set the rotation of a 2d object
	double getRotation();//get the current rotation of an 2d object
	void setFrameControl(int value);//set direction of the animation sequence
	int getFrameControl();//get the direction of the animation sequences
	void setTotalFrames(int value);//set the total number of frmaes in the sprite shee
	int getTotalFrames();//get the total amount of frames in the sprite sheet
	void setCurrentFrame(int value);//set the current frame
	void setCurrentFrameplus(int value);//move the current frame up a value
	int getCurrentFrame();//get the current frame
	void setFrameTimer(int value);//set the timer for the animation speed
	int getFrameTimer();//get the animation speed timer
	void setColumns(int value);//set the number of columns in the sprite sheet
	int getColumns();//get the number of colums on the sprite sheet
	void setDirection(int value);//set direction of the 2d object
	int getDirection();//get the direction of the 2d object
	D3DCOLOR getColor();//get the current transparency color
	int getMoveStart();//get the current starting cordinates
	void setMoveStart(int time);//set the starting current cordinates
	int getFrameStart();//get the frame start on the sprite sheet
	void setFrameStart(int value);//set the frame start on the sprite sheet
	enum Collision getCollision();//get the current collision mode
	void setCollision(Collision value);//set the current collision mode
	void Free_2DEngine_Vector();//free the vector
	_vector getPosition();//get position of the 2d object
	void setPosition(_vector position);//set the position with a vector as input
	void setPosition(double x, double y);//set the position with x,y cordinates
	double getx();//get the x cordinate
	double gety();//get the y cordinate
	void setx(double x);//set x cordinate
	void sety(double y);//set y cordinate
	_vector getVelocity();//get velocity of the 2d objects
	void setVelocity(_vector vel);//set the velocity with the vector as an input
	void setVelocity(double x, double y);//set the velocity wit the x,y cordinates
	float getAngle();//get the angle of the object
	void setAngle(float input);//set the angle of the object.
	


	//attributes
private:
	int width;//object width
	int height;//object height
	int state;//object state
	bool isLoaded;//check whethere a picture is loaded
	Texture *image;//image object
	int moveClock;//clock for movement speed
	D3DCOLOR color;//transparency color
	double scale_k;//object scale size
	double rotation;//object rotation
	int frameControl;//object animation
	int totalFrames;//total frame 
	int currentFrame;//current frame
	int frameTimer;//animation speed
	int columns;//sprite sheet columns 
	int direction;//object direction
	int framestart;//starting frame for sprite sheet
	int animstartx;//animation sequence cordinate x start
	int animstarty;//animation sequecne cordinate y start
	float moveAngle;//angle of movement
	int movestart;//time start for movement
	Collision collisionType;//collision mode
	_vector position;//position vector for input
	_vector velocity;//velocity vector for input
	
};


};

