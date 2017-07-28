//========= Copyright © 2009, David Martin, All rights reserved. ============
//
// Purpose: Console Manager Header
//
//=============================================================================

#ifndef GAMECONSOLE_H
#define GAMECONSOLE_H

#include "../Viper2D/Viper2D.h"
//#include "../Sprite/2dengine.h"
#include "../Font/Font.h"
#include <vector>



namespace Viper2D
{
// ----------------------------------------------------------------
//  Class:			CGameConsole
//  Description:    GUI implementation of the game/dev console
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
class CGameConsole
{
	public:
	
		CGameConsole();//constructor
		~CGameConsole();//destructor
		bool Initialize();//draws the panel and sets the font
		bool Activate();//shows the console na draws the text
		void Show();//show panel	
		void Hide();//hide panel
		void Clear();//clears the panel
		void Printf(std::string text, int line);//print the text
		void DPrintf(const char *format, ...);//debug text printer
		bool IsConsoleVisible();//check to see if the console visible
	private:
		bool isVisible;//visible tag
		int currentLine;//current line on the panel
		cFontManager *font;//font object
		_2DEngine *panel;//panel object
		std::vector<std::string> textlines;//vector holding text
		std::vector<std::string>::iterator iter;//vector iterator
    
};
};



#endif // GAMECONSOLE_H
