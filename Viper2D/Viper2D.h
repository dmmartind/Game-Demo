//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Main Engine Class Header
//
//****************************************************************************************


#ifndef VIPER2D_H_//define one time and let everyone share, so VS doesn't give annoying errors
#define VIPER2D_H_//define one time and let everyone share, so VS doesn't give annoying errors


#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#include <dxerr9.h>
#include <ctime>
#include <sstream>

#include <windowsx.h>



#include "..\Global\Timer.h"
#include "..\Input\Input.h"
#include "..\Entity\Entity.h"
#include <list>
#include "..\Thread\Mutex.h"
#include "..\Thread\Thread.h"



//version 
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define REVISION 0


//external variables and functions
extern bool gameover;//external flag for checking to see if the game is quiting
extern int game_preload();//external function for loading attributes for the window creation
extern int game_init(HWND);//external splash screen or pre-game loading
extern void game_update();//external function for updating the game
extern void game_end();//external function for closing 
extern void game_render3d();//external function for screen update in 3D space 
extern void game_render2d();//external function for screen update in 2D space
extern void game_keyPress(int input);//external to handle a key press
extern void game_keyRelease(int input);//exteranl to handle a key release
extern void game_mouseButton(int input);//external to handle a mouse button press
extern void game_mouseButtonR(int input);//external to handle a mouse button release
extern void game_mouseMotion(int x,int y);//external function to handle mouse motion
extern void game_mouseMove(int x,int y);//external function to handle mouse move from old position
extern void game_mouseWheel(int wheel);//external function to handle mouse movement
extern void game_GamePadPress(int input);//external function to handle game pad button press
extern void game_POVPress(int input);//external function to handle POV button press on a game pad
extern void gamepadLeftThumbMove(long inputx,long inputy);//external function gamepad left thumb move
extern void gamepadRightThumbMove(long inputRX,long inputRY);//external function game right thum move
extern void game_entityUpdate(Viper2D::cBaseEntity* entity);//external function for updating entities
extern void game_entityRender(Viper2D::cBaseEntity* entity);//external function for updating 
extern void game_entityCollision(std::list<Viper2D::cBaseEntity*>::iterator test1,std::list<Viper2D::cBaseEntity*>::iterator test2);
//external function for handling collision
extern void collisionTest();//external function for testing whether two entities have collided.



 
namespace Viper2D 
{


	static void* __cdecl thread_function_bury_entities(void* data);//garbage detection

// ----------------------------------------------------------------
//  Name:           
//	Class:			Engine
//  Description:    main engine class
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
	class Engine {//main engine class
	private:
		int p_versionMajor, p_versionMinor, p_revision;//version var
		HWND p_windowHandle;//var to hold windows handle
		HINSTANCE p_windowInstance;
		LPDIRECT3D9 p_d3d;//directx 9 object
		LPDIRECT3DDEVICE9 p_device;//video card object
		LPDIRECT3DSURFACE9 p_backbuffer;//backbuffer object
		LPD3DXSPRITE p_sprite_handler;//sprite renderer
		std::string p_apptitle;//title of game or engine
		bool p_fullscreen;//flag for fullscreen
		int p_screenwidth;//var for screenwidth
		int p_screenheight;//var for scren height
		int p_colordepth;//color depth
		bool p_pauseMode;//flag for pause game
		D3DCOLOR p_ambientColor;//set the ambient color
		bool p_maximizeProcessor;//flag to maximized processor
		Timer p_coreTimer;//var for holding time
		Timer collTimer;//var for holding collision time
		long p_frameCount_core;//var for holding the frame count
		long p_frameRate_core;//var for holding the frame rate
		Timer p_realTimer;//var for holding the timer
		long p_frameCount_real;//var for holding the frame count
		long p_frameRate_real;//var for holding the frame rate
		cInput input;//direct input object
		cInputDevice keyboard;//keyboard object
		cInputDevice mouse;//mouse object
		void updateKeyboard();//gets an update from the keyboard
		void updateMouse();//gets an update from the mouse
		std::list<cBaseEntity*> object;//entity vector
		bool mouseContinuous;//flag for continuouse mouse input/one at a time
		bool keyContinuous;//flag for continuouse key input/one at a time
		bool gamepadContinuous;//flag for continuouse gamepad input/one at a time
		bool xboxContinuous;//flag for continuouse xbox controller input/one at a time
		bool oldmouse[4];//old mouse button positions
		char oldkeys[256];//old key position
		cMutex *mutex;//mutex object
		cThread *thread;//thread object
		

		

	public:
		Engine();//constructor
		virtual ~Engine();//class deconstructor
		void Free();
		int Init(int width, int height, int colordepth, bool fullscreen);//initializes the rendering pipeline of the engine
		void Close();//scripted engine shutdown
		void Update();//rendering update and frame rate control
		void message(std::string message, std::string title = "ADVANCED 2D");//prints message box to user
		void fatalerror(std::string message, std::string title = "FATAL ERROR");//prints error on messagebox and shutsdown engine
		void Shutdown();//shutdown engine
		void ClearScene(D3DCOLOR color);//clears the front and back buffers on the video card
		void SetDefaultMaterial();//sets diffused material on objects for light reflection
		void SetAmbient(D3DCOLOR colorvalue);//sets environment light
		void SetIdentity();
		int RenderStart();//start rendering pipeline
		int RenderStop();//stop rendering pipeline
		int Render2D_Start();
		int Render2D_Stop();
		int Release();//release all objects
		template<class T> void ReleaseCOM(T& x);

		//accessor/mutator functions expose the private variables
		bool isPaused();//return if game is in paused state
		void setPaused(bool value);//set the pause state
		LPDIRECT3DDEVICE9 getDevice();//get the directx 9 video card
		LPDIRECT3DSURFACE9 getBackBuffer();//get the back buffer
		LPD3DXSPRITE getSpriteHandler();//get renderer
		void setWindowHandle(HWND hwnd);//set the window handle
		HWND getWindowHandle();//get the window handle
		void setWindowInstance();//set the window handle
		HINSTANCE getWindowInstance();//get the window handle
		std::string getAppTitle();//get the title of the application
		void setAppTitle(std::string value);//set the game title
		int getVersionMajor();//get the version major
		int getVersionMinor();//get the version minor
		int getRevision();//get the revision
		std::string getVersionText();//get version text
		long getFrameRate_core();//get the core frame rate
		long getFrameRate_real();//get the real frame rate
		int getScreenWidth();//get the screen width
		void setScreenWidth(int value);//set the screen width
		int getScreenHeight();//get the screen height
		void setScreenHeight(int value);//set the screen height
		int getColorDepth();//get the color depth
		void setColorDepth(int value);//set the color depth
		bool getFullscreen();//get the fullscreen
		void setFullscreen(bool value);//set the full screen
		bool getMaximizeProcessor();//speed up processor
		void setMaximizeProcessor(bool value);//set the maximize processor
		
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void UpdateEntities();//update entities
 void Draw3DEntities();//draws 3D entities
 void Draw2DEntities();//draws 2D entities
 void BuryEntities();//internal garbage collection
  std::list<cBaseEntity*>::iterator findEntity(ObjectType objectType);//find an entity based on object type
  int getEntityCount(int input);//get entity count based on object type
 void addEntity(cBaseEntity *input);//add entity
 void deleteEntity(ObjectType input);//delete entity based on the object
 bool getMouseContinuous();//function to see if the mouse is under continuouse output
bool getKeyContinuous();//function to see if the key is under continuouse output
void setMouseContinuous(bool input);//set function to see if the mouse is under continuouse output
void setKeyContinuous(bool input);//set function to see if the key is under continuouse output
std::list<cBaseEntity*> getObject();//get entity object
void TestForCollisions();//test for collision
bool Engine::collision(std::list<cBaseEntity*>::iterator test1,std::list<cBaseEntity*>::iterator test2);
//collision with bounding box calculation
bool Engine::collisionD(std::list<cBaseEntity*>::iterator test1,std::list<cBaseEntity*>::iterator test2);
//collsion with circle calculation
cMutex *getMutex();//get mutex object

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		
	}; //class


}; //namespace

 
//define the global engine object (visible everywhere!)
extern Viper2D::Engine *g_engine;//ertern function pointer to the engine.


#endif

