//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Timer Class Header
//
//****************************************************************************************


#ifndef _TIMER_H//define one time and let everyone share, so VS doesn't give annoying errors
#define _TIMER_H//define one time and let everyone share, so VS doesn't give annoying errors

#include <windows.h>



// ----------------------------------------------------------------
//  Name:           Timer
//  Description:    game timing chain
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
class Timer
{
private:
	DWORD timer_start;//starting time var
	DWORD stopwatch_start;//starting stopwatch var

public:
	Timer(void);//timer constructor
	~Timer(void);//timer deconstructor
	DWORD getTimer();//return the timer
	DWORD getStartTimeMillis();//start time in milliseconds
	
	void sleep(int ms);//sleep function
	void reset();//reset timer
	bool stopwatch(int ms);//stopwatch check
};

#endif