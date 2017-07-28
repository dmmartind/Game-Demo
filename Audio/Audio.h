 //*********** (C) Copyright 2009 David Martin All rights reserved. **********
// Purpose: Audio Interface Header
//
//**********************************************vk)****************************************


#ifndef _AUDIO_H_//define one time and let everyone share, so VS doesn't give annoying errors
#define _AUDIO_H_//define one time and let everyone share, so VS doesn't give annoying errors

#include "Sound.h"//sound header file
#include <vector>//vector header file


// ----------------------------------------------------------------
//  Name:           Sample
//	Class:			Sample
//  Description:    class to tie the sound channel and data channel together
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class Sample
    {
    private:
        char *name;//reference name of the sound file
    
	public:
		SoundData    data;//Sound Data object
        SoundChannel channel;//Sound Channel object
		HANDLE p_Thread;//thread handle
		DWORD p_ThreadID;//thread id
        Sample(void);//constructor
        ~Sample(void);//deconstructor
        char* getName() { return name; }//return name of current reference
        void setName(char *value) { name = value; }//set the name of the current reference
		int index_count;//index count for the queue
		
    };

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ----------------------------------------------------------------
//  Name:           Audio
//	Class:			Audio
//  Description:    main interface to audio framework
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    class Audio
    {
    private:
        Sound system;//sound object
		typedef std::vector<Sample*> Samples_Vector;//main vector queue object
        typedef std::vector<Sample*>::iterator Iterator;//queue iterater
        Samples_Vector samples_vec;//instance of the queue object
		
    
    public:
        Audio();//constructor
        ~Audio();//deconstructor
        

        
        bool Init(HWND hwnd);//Audio interface initialization
        
		bool Load(char *filename, char *name);//load file with the name of the reference
					//WAV:fill the attributes of the RIFF header of the WAV file and set the reference to the wav file
					//to the data channel.
					//OGG: fill the attributes of the RIFF header of the OGG file and decode the OGG to WAV and copy 
					//the WAV to a buffer in its own class to hold until the channel buffer is created.

		bool SampleExists(char *name);//Does a particular reference exist
		
        Sample* Load(char *filename);//fill the attributes of the RIFF header of the WAV file and set the reference to the wav file
	//				to the data channel.
       
        bool Play(char *name, int vol=100, bool loop=false);//play a the file via reference
        void StopAll();//stop playing all sounds
        bool IsPlaying(char *name);//check to see if the reference is still playing
		Sample *FindSample(char* name);//check to see if reference is in the queue and return reference
		BOOL Stop(char *name);//stop playing sound via reference name
		void StopAllExcept(char *name);//stop all sound except for the refernce of the sound sent to the function
		void ChangeVolume(char *name, int level);//change the volume of the sound by the reference name
		void Pan(char *name, int level);//pan sound between -100 to 100 from left , center, right
		void Frequency(char *name, int level);//change the sample frequency that the playback will be sampled at
		void SetLoop(char *name);//change the looping state of the referenced sound
		void StopLoop(char *name);//change the looping state of the referenced sound
		void Pause(char *name);//pause the referenced sound
		
        
    };//end audio class



#endif
