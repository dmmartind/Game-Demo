//*********** (C) Copyright 2009 David Martin All rights reserved. **********
// Purpose: Camera Class Header

//****************************************************************************************

#ifndef _CAMERA_H_//define one time and let everyone share, so VS doesn't give annoying errors
#define _CAMERA_H_//define one time and let everyone share, so VS doesn't give annoying errors

#include "..\Viper2D\Viper2D.h"

namespace Viper2D
{
	class Camera
	{
	private:
		D3DXMATRIX p_matrixProj;//projection matrix
		D3DXMATRIX p_matrixView;//view matrix
		D3DXVECTOR3 p_updir;//up/down vector

		D3DXVECTOR3 p_position;//vector for the position of the camera
		D3DXVECTOR3 p_target;//vector for the position of the target of the camera

		float p_nearRange;//how near to the camera does the image clip
		float p_farRange;//how far from the camera does the image clip
		float p_aspectRatio;//aspect ratio of the camera
		float p_fov;//field of view for the camera

	public:
		Camera(void);//constructor
		~Camera(void);//destructor
		void setPerspective(float fov, float apsectRatio, float nearRange, float farRange);//set the
		//clipping region
		float getNearRange();//get the near clipping range
		float setNearRange(float value);//set the near clipping range
		float getFarRange();//get the far clipping range
		float setFarRange(float value);//set the far clipping range
		float getAspectRatio();//get the aspect ratio
		float setAspectRatio(float value);//set the aspect ratio
		float getFOV();//get the field of view
		void setFOV(float value);//set the field of view
		void Update(); //TBA

		D3DXVECTOR3 getPosition();//get the position of the camera
		void setPosition(float x, float y, float z);//set the position of the camera
		void setPosition(D3DXVECTOR3 position);//set the position of the camera
		float getX();//get the position x cordinate
		float setX(float value);//set the position x cordinate
		float getY();//get the position y cordinate
		float setY(float value);//set the position y cordinate
		float getZ();//get the position z cordinate
		float setZ(float value);//set the z cordinate

		D3DVECTOR getTarget();//get the target of the camera
		void setTarget(D3DXVECTOR3 value);//set the target of the camera
		void setTarget(float x,float y,float z);//set the target of the camera

	};//end of class
};//end of namespace













#endif
