//========= Copyright © David Martin,All rights reserved. ============
// Purpose: Font Class Manager Header
//
//=============================================================================

#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include "../Viper2D/Viper2D.h"
#include "../Sprite/2dengine.h"
#include <memory.h>


namespace Viper2D
{

// ----------------------------------------------------------------
//  Name:			
//  Class:			cFontManager
//  Description:    Creates and maintains list of actively used fonts
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
	class cFontManager: public _2DEngine
{
public:
	cFontManager();//constructor
	~cFontManager();//deconstructor

	// clears the current font list, frees any resources
	

	void writeText(int x,int y,std::string text,int color);//write text
	bool loadFontData(char *filename);//load font data
	int getFontWidth();//get the width of the font
	int getFontHeight();//get the height of the font
	void setFontSize(int width,int height);//set the size
	void setFontWidth(int input);//set the width

private:
	int widths[256];//array to hold the width of each character
};
};

// singleton accessor
//extern CFontManager &FontManager();


#endif // FONTMANAGER_H
