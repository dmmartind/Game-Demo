//*********** (C) Copyright 2009 David Martin All rights reserved. **********
// Purpose: An application framework class definitions 

//=============================================================================


#ifndef _WINMAIN_H_//define one time and let everyone share, so VS doesn't give annoying errors
#define _WINMAIN_H_//define one time and let everyone share, so VS doesn't give annoying errors

#define WIN32_LEAN_AND_MEAN//includes headers to speed up compile
#define WIN32_EXTRA_LEAN//includes headers to speed up compile


//#include <time.h>//time library
#include "..\Viper2D\Viper2D.h"//engine header
#include <time.h>//time library
bool gameover;//gameover function that I'm declaring here, but I'm using it yet.

class cApplication//application class
{
  private:
    HINSTANCE     m_hInst;//handle to the instance of the window
	HWND          m_hWnd;//window handle

  protected:
    char          m_Class[MAX_PATH];//class name for window
    char          m_Caption[MAX_PATH];//name to go on titlebar

    WNDCLASSEX    m_wcex;//window class to state the attributes of the window being created

    DWORD         dwStyle;//the style attrubute of the window
	DWORD		  dwExStyle;//the style extention of the window
    DWORD         m_XPos;//the X position of the window
    DWORD         m_YPos;//the Y posistion of the window
    DWORD         m_Width;//the width of the window
    DWORD         m_Height;//the height of the window 
	RECT		  windowRect;//rectangle structure representing the window frame
	char          title[255];//title and the class name of the window
	MSG           msg;//message structure
	


  public:
    cApplication();//constructor
	~cApplication();

    HWND      GethWnd();//get handle of the current window
    HINSTANCE GethInst();//get the instance of the window
	void SethWnd(HWND input);
	//void SethInst(HINSTANCE input);

    BOOL Run();//main loop of the game
    BOOL Error(BOOL Fatal, char *Text, ...);//Will there be any errors in this engine? NEVER!!!!! 

    BOOL Move(long XPos, long YPos);//repainting window in new loacation, if user desides tho play in windowed mode.
    BOOL Resize(long Width, long Height);//repainting new size of the window, if allowed

    BOOL ShowMouse(BOOL Show = TRUE);//maybe we don't want to show the mouse, properly during a movie sequence, but otherwise it's defaulted to true.

	
//function to handle all user input during the druation of the game
	virtual BOOL Init()       { return TRUE; }//directx 9c initialization
    virtual BOOL Shutdown()   { return TRUE; }//clean house and DESTROY EVERYTHING!!!!
    virtual BOOL Frame()      { return TRUE; }//render frame 1/60 frames per sec
};

//static cApplication *g_pApplication = NULL;//window object
static LRESULT WINAPI WinProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );//window procedure
























#endif




