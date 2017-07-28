//*********** (C) Copyright 2009 David Martin All rights reserved. **********
// Purpose: Vector Class Header

//****************************************************************************************
#pragma once


#include <math.h>

namespace Viper2D
{

// ----------------------------------------------------------------
//  Name:           
//	Class:			_vector
//  Description:    
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
class _vector//vector class
{
public:
	_vector();//constructor
	_vector(float input1, float input2, float input3);//constructor initializing with cordinate input
	~_vector();//destructor
	float getx();//get cordinate x
	float gety();//get cordinate y
	float getz();//get cordinate z
	void setx(float value);//set cordinate x
	void sety(float value);//set cordinate x
	void setz(float value);//set cordinate x
	float distance(_vector second);//distance between two vectors
	float length();//length of a vector
	void move(float input1,float input2, float input3);//move current vector to new cordinates
	void operator=(_vector input);//copy constructor
	float dot_product(_vector input);////to find whether the angle between two vectors is <,>, or = to 90(cordinate input)
									//also used to find the exact angle
	_vector cross_product(_vector input);//used to find the resulting vector after a collision
	_vector normal();//scale the vector magnatute down to 1
	void set(float input1, float input2, float input3);//set the vector to new vector
	_vector operator+(_vector input);//add two vector
	void operator+=(_vector input);//add the result to a vector
	_vector operator-(_vector input);//subtract two vectors
	void operator-=(_vector input);//subtract the result from the vector
	_vector operator*(_vector input);//multiply two vectors
	void operator*=(_vector input);//multiply the result to a vector
	_vector operator/(_vector input);//divide two vectors
	void operator/=(_vector input);//divide the vector by the result
	bool operator==(_vector input);//test if two vecters are equall
	void setRotation(float input);//set the rotation of a vector
	float getRotation();//get the rotation of a vectors

private:
	float x;//x cordinate
	float y;//y cordinate
	float z;//z cordinate
	float rotation;//rotation var

};

};

