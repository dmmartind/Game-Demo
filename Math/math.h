//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Math Class Header 
//
//****************************************************************************************
#include "..\Vector\vector.h"

#pragma once

namespace Viper2D {

    const double PI = 3.1415926535;//PI constant
    const double PI_over_180 = PI / 180.0f;//calculation needed for degreee to radian conversion
    const double PI_under_180 = 180.0f / PI;//calculation needed for radian to degree conversion
    
    class cMath {//math class
    public:
        double toDegrees(double radian);//convert radians to degrees
        double toRadians(double degree);//convert degrees to radians
        double wrapAngleDegs(double degs);//make sure that the degrees stays above 0
        double wrapAngleRads(double rads);//make sure that the radians stats above 0
        double LinearVelocityX(double angle);//move the horizontal angle back the next quadrant over and covert to radians
        double LinearVelocityY(double angle);//move the vertical angle back the next quadrant over and covert to radians
        _vector LinearVelocity(double angle);//move the angle back the next quadrant over and covert to radians
        double AngleToTarget(double x1,double y1,double x2,double y2);//set the angle of an object to the direction of another(cordinates as input)
        double AngleToTarget(_vector& source,_vector& target);//set the angle of an object to the direction of another(vectors as input)
        double Distance( double x1,double y1,double x2,double y2 );//distance between two objects(cordinates input)
        double Distance( _vector& v, _vector& vec2  );//distance between two objects(vector input)
        double Length(_vector& vec);//vector length(vector input)
        double Length(double x,double y,double z);//vector length(cordinate input)
        double DotProduct(double x1,double y1,double z1,double x2,double y2,double z2);
		//to find whether the angle between two vectors is <,>, or = to 90(cordinate input)
		//also used to find the exact angle
		double DotProduct( _vector& vec1, _vector& vec2 );
		//to find whether the angle between two vectors is <,>, or = to 90(vector input)
		//also used to find the exact angle
        _vector CrossProduct( double x1,double y1,double z1,double x2,double y2,double z2);
		//used to find the resulting vector after a collision
        _vector CrossProduct( _vector& vec1, _vector& vec2 );
		//used to find the resulting vector after a collision
        _vector Normal(double x,double y,double z);//scale the vector magnatute down to 1(cordinate input)
        _vector Normal(_vector& vec);//scale the vector magnatute down to 1(vector input)
    };
    
};
