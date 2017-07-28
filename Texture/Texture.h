//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Texture Class Header
//
//****************************************************************************************

#ifndef _TEXTURE_H//header
#define _TEXTURE_H//header


#include "..\Viper2d\Viper2d.h"//main engine include

namespace Viper2D//engine namespace
{

	// ----------------------------------------------------------------
//  Name:           Texture
//	Class:			Texture
//  Description:    texture operations
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
	
	
	class Texture
	{
		public:
			Texture();//constructor
			~Texture();//destructor
			void Free();//free everything
			int getWidth();//get the width of the picture
			int getHeight();//get the height of the picture
			bool Load(char* filename, D3DCOLOR color=D3DCOLOR_XRGB(0,0,0));//load picture as texture
			LPDIRECT3DTEXTURE9 GetTexture();//get texture object
			int counter;//counter
			template<class T> void ReleaseCOM(T& x);//release objects
			void Release();

		private:
			LPDIRECT3DTEXTURE9 texture;//texture pointer
			D3DXIMAGE_INFO info;//image structure
	};

};

#endif


	









