//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Input Class Header 
//
//****************************************************************************************
#define DIRECTINPUT_VERSION 0x0800//set direct input version
#include <dinput.h>




namespace Viper2D
{
	

// Enumerated list of of device types
enum InputDevices {
  NONE = 0,//no input
  KEYBOARD = 1,//keyboard input
  MOUSE = 2,//mouse input
  JOYSTICK = 3//joystick input
};


///////////////////////////////////////////////////////////////////////
// Class definitions
///////////////////////////////////////////////////////////////////////
class cInput;//forward declaration
class cInputDevice;//forward declaration

class cInput//cinput object to handle direct input  
{
  protected:
      HWND           m_hWnd;//window handle
      IDirectInput8 *m_pDI;//direct input 8 object

  public:
    cInput();//constructor
    ~cInput();//destructor

    IDirectInput8 *GetDirectInputCOM();//direct input COM object
    HWND           GethWnd();//get window handle
    
    bool Init(HWND hWnd, HINSTANCE hInst);//initialization of the directx 
    bool Shutdown();//shutdown object
	template<class T> void ReleaseCOM(T& x);//release direct objects
};

class cInputDevice//direct input device class
{
  public:
    cInput               *m_Input;//input object

    short                 m_Type;//type integer
    IDirectInputDevice8  *m_pDIDevice;//direct input device object

    bool                  m_Windowed;//var to hold whether or not 

    char                  m_State[256];//controller state
    DIMOUSESTATE         *m_MouseState;//mouse filter
    DIJOYSTATE           *m_JoystickState;//joystick filter

    bool                  m_Locks[256];//controller array

    long                  m_XPos, m_YPos, m_ZPos;//cordinate var
      
    static BOOL FAR PASCAL EnumJoysticks(LPCDIDEVICEINSTANCE pdInst, LPVOID pvRef);
	//enumerate through controllers attached
  public:
    cInputDevice();//constructor
    ~cInputDevice();//deconstructor

    IDirectInputDevice8 *DeviceCOM();//device COM object

    // Generic functions - all devices
    bool Create(cInput *Input, short Type, bool Windowed = TRUE);//create new object
    bool Free();//free objects

    bool Clear();//free objects
    bool Read();//read controller
    bool Acquire(BOOL Active = TRUE);//aquire device

    bool GetLock(char Num);//get the lock state of a button or key
   	bool SetLock(char Num, bool State = TRUE);//set the lock of a button or key

    long GetXPos();//get x position
	bool SetXPos(long XPos);//set x position
    long GetYPos();//get y position
	bool SetYPos(long YPos);//set y position
    long GetXDelta();//get change in x
    long GetYDelta();//get change in y

    // Keyboard specific functions
    bool  GetKeyState(char Num);//get key state(pressed/unpressed)
    bool  SetKeyState(char Num, BOOL State);//set key state(pressed/unpressed)
    bool  GetPureKeyState(char Num);//get the state without checking the locks
    short GetKeypress(long TimeOut = 0);//check key presses for an amount
    long  GetNumKeyPresses();//get number of key presses with locks
    long  GetNumPureKeyPresses();//get number of key presse without locks

    // Mouse/Joystick specific functions
    bool  GetButtonState(char Num);//get buttin state
    bool  SetButtonState(char Num, BOOL State);//set button state
    BYTE  GetPureButtonState(char Num);//get pure buttin state
    long  GetNumButtonPresses();//get number if button states with locks from controller
    long  GetNumPureButtonPresses();//get number if button states without locks from controller
	template<class T> void ReleaseCOM(T& x);//release objects
	char _GetKeyState(int key);//getunfiltered key state 
	long GetZPos();//get z position
	long GetZDelta();//get change in Z
};
};


