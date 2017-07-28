//*********** (C) Copyright 2009 David Martin All rights reserved. **********
// Purpose: Mesh Class Header 
//
//****************************************************************************************

#ifndef _MESH_H_//define one time and let everyone share, so VS doesn't give annoying errors
#define _MESH_H_//define one time and let everyone share, so VS doesn't give annoying errors





#include "..\Viper2D\Viper2D.h"

namespace Viper2D
{
	
	class Mesh: public cBaseEntity
	{
	private:
		LPD3DXMESH mesh;//manipulate mesh object

		D3DMATERIAL9* materials;//lighting structure
		LPD3DXMATERIAL d3dxMaterials;//Returns material information
		LPD3DXBUFFER matbuffer;//material buffer
		DWORD material_count;//material counter

		LPDIRECT3DTEXTURE9* textures;//pointer interface to manipulate a texture resource

		D3DXVECTOR3 position;//position vector
		D3DXVECTOR3 velocity;//velocity vector
		D3DXVECTOR3 rotation;//rotation vector
		D3DXVECTOR3 scale;//scale vector

		D3DXMATRIX matWorld;//world matrix
		D3DXMATRIX matTranslate;//translate matrix
		D3DXMATRIX matRotate;//rotation matrix
		D3DXMATRIX matScale;//scale matrix

		 

	public:
		Mesh(void);//mesh constructor
		~Mesh(void);//mesh desconstructor

		void animate() { }
		void draw();

		int GetFaceCount();//get the face count of the mesh
		int GetVertexCount();//he get the vertex count of the mesh

		bool Load(char *filename);//load mesh

		void CreateSphere(float radius=0.1f, int slices= 10, int stacks=10);//create sphere mesh
		void CreateCube(float width=1.0f, float height=1.0f, float depth=1.0f);//create cube mesh

		void Draw();//draw mesh, materials, and textures
		void Transform();//create the tran

	    void Rotate(D3DXVECTOR3 rot);//rotation mesh
		void Rotate(float x, float y, float z);//rotation mesh

		void move();//move mesh
		//basic collision detection
		void LimitBoundary(float left, float right, float top, float bottom, float back, float front);

		void SetPosition(D3DXVECTOR3 pos);//set position
		
		void SetPosition(float x, float y, float z);//set position
		
		D3DXVECTOR3 GetPosition();//get position
		
		void SetVelocity(D3DXVECTOR3 vel);//set velocity
		
		void SetVelocity(float x,float y, float z);//set velocity
		
		D3DXVECTOR3 GetVelocity();//get velocity
		
		void SetRotation(D3DXVECTOR3 rot);//set rotation
				
		void SetRotation(float x, float y, float z);//set rotation
		
		void SetRotationX(float x);//set the rotation x
		
		double GetRotationX();//get rotation x
		
		void SetRotationY(float y);//set the rotation y
		
		double GetRotationY();//get rotation y
		
		void SetRotationZ(float z);//set rotation z
				
		float GetRotationZ();//get rotation z
		
		void SetScale(D3DXVECTOR3 value);//set scale
				
		void SetScale(float x, float y, float z);//set scale
		
		D3DXVECTOR3 GetScale();//get scale
		
		void SetScaleX(float x);//set scale x
		
		float GetScaleX();//get scale x
		
		void SetScaleY(float y);//set scale y
		
		float GetScaleY();//get scale y
		
		void SetScaleZ(float z);//set scale z
		
		float GetScaleZ(float z);//get scale z
		
		template<class T> void ReleaseCOM(T& x);//release all COM objects
		void Free();//free everything else
		
	};

};


#endif




