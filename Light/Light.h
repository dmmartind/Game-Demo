//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Light Class Header
//
//****************************************************************************************

#ifndef _LIGHT_H_//define one time and let everyone share, so VS doesn't give annoying errors
#define _LIGHT_H_//define one time and let everyone share, so VS doesn't give annoying errors

#include "..\Viper2D\Viper2D.h"

namespace Viper2D
{

// ----------------------------------------------------------------
//  Name:           Light
//	Class:			Light
//  Description:    class 
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
	
	class Light
	{

		private:
			D3DLIGHT9 p_light;//light structure
			D3DLIGHTTYPE p_type;//light type structure 
			int p_lightNum;//index

		public:
		//light constructor
		Light(int lightNum, D3DLIGHTTYPE type, D3DXVECTOR3 position, D3DXVECTOR3 direction, double range);
		~Light(void);//deconstructor
		void Light::Free();
		void Update();//update light settings
		void Show();//turn light on
		void Hide();//turn light off
		void setX(double value);//set the x value
		double getX();//get the x value
		void setY(double value);//set the y value
		double getY();//get the y value
		void setZ(double value);//set the z value
		double getZ();//get the z value
		D3DLIGHTTYPE getType();//get the light type value 
		void setColor(D3DCOLORVALUE color);//set the color value of light
		D3DCOLORVALUE getColor();//get the color value of the light
		void setDirection(D3DXVECTOR3 direction);//set the direction of the light using a direction vector
		void setDirection(double x,double y,double z);//set the direction of the light using the x,y,z cordinates
		void setPosition(D3DXVECTOR3 pos);//set the position of the light using a position vector
		void setPosition(double x,double y,double z);//set the position cordinates using x,y,z cordinates 
		D3DXVECTOR3 getPosition();//get the position vector
		D3DXVECTOR3 getDirection();//get the direction vector
		template<class T> void ReleaseCOM(T& x);//release objects
		
	};

};



#endif







