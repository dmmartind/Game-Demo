//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Thread Class Header 
//
//****************************************************************************************

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <process.h>
#include <stdio.h>


// ----------------------------------------------------------------
//  Name:           
//	Struct:			_Thread_t
//  Description:    thread handle
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
typedef struct _Thread_t
{
}*Thread_t;//thread structure



// ----------------------------------------------------------------
//  Name:           
//	Class:			cThread
//  Description:    thread class
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
class cThread//thread class
{
public:

	cThread();//constructor
	~cThread();//destructor
	int Thread_Create(void* (*start)(void*), void* arg);//create thread
	int Thread_Detach();//close thread
	int Thread_Join();//wait for another thread
	int Thread_Sleep(int millis);//sleep thread
	static unsigned __stdcall threadProc(void *a);//thread processor function to call the function to be threaded

	Thread_t *handle;//thread handle
	bool running;//thread running flag

};