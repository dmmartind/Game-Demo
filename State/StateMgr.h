//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: State Manager Class Header 
//
//****************************************************************************************

#include <list>


namespace Viper2D
{

// ----------------------------------------------------------------
//	enum:			cState
//	Class:			
//  Description:    list of possible states
//  Arguments:      None.
//  Return Value:   eStateManager
// ----------------------------------------------------------------	
	enum cState//state mode
	{
		GAME_PRELOAD,//preload mode
		GAME_INIT,//initialize mode
		GAME_MISSION,//mission playing mode
		GAME_MENU,//menu mode
		GAME_SHUTDOWN//shutdown mode
	};

// ----------------------------------------------------------------
//  Name:           
//	Class:			eStateManager
//  Description:    State Manager Class
//  Arguments:      None.
//  Return Value:   None
// ----------------------------------------------------------------	
class eStateManager//state manager
{

	public:
		eStateManager();//constructor
		~eStateManager();//deconstructor

		cState getState();//get state object
		void setState(cState input);//set state
		void popState();//pop the state out of the list

	private:
		std::list<cState> state_list;//list vector


};






};



