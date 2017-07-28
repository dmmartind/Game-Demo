//*********** (C) Copyright 2009 David Martin All rights reserved. **********
//
// Purpose: Mutex Class Header 
//
//****************************************************************************************

#include <windows.h>


// ----------------------------------------------------------------
//  Name:           
//	Class:			cMutexImpl
//  Description:    critical section objects and its unlock/lock functions
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
class cMutexImpl
{
public:
	
	CRITICAL_SECTION obj;//critical section object 
	cMutexImpl();//constructor
	~cMutexImpl();//deconstructor
	void lock();//lock the section
	void unlock();//release the section
	
};

// ----------------------------------------------------------------
//  Name:           
//	Class:			cMutex
//  Description:    interface class to the critical section class
//  Arguments:      None
//  Return Value:   None.
// ----------------------------------------------------------------
class cMutex
{
public:
	cMutex();//constructor
	~cMutex();//deconstructor
	void lock();//lock section
	void unlock();//release section
	static void incrementRC(long *value);//increment protected var
	static long decrementRC(long *value);//decrement protected var
	static long test_and_set(long *value, long newValue=1);//set new value to protect var

private:
	cMutexImpl *m_this;//critical section object
	
};






