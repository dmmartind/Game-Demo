//*********** (C) Copyright 2009 David Martin All rights reserved. **********
// Purpose: Sound Class Header

//****************************************************************************************

#ifndef _SOUND_H_
#define _SOUND_H_

#include <windows.h>
#include <mmsystem.h>
#include <dsound.h>//directx sound library
#include <stdio.h>//standard I/O library
#include <io.h>//I/O library
#include <fcntl.h>//file control





// Macro to release a COM object
//#define ReleaseCOM(x) if(x) { x->Release(); x = NULL; }

// These are the fixed sizes for sound channel buffers
//const long g_SoundBufferSize  = 65536;//maximum size of music file
//const long g_SoundBufferChunk = g_SoundBufferSize / 4;//section the sound file will be divided up

// Forward class declarations
class Sound;//sound class
class SoundData;//sound data class
class SoundChannel;//sound channel

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ----------------------------------------------------------------
//  Class:			CWAVFile
//  Description:    class that holds the pcm data from the decoded ogg file and it's attributes
// ----------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class CWAVFile//wave file object class
{
public:
	CWAVFile();//constructor
	virtual ~CWAVFile();//deconstructor
	BYTE getData(long index);
	BYTE *getData();
	void setData(BYTE *input);
	long getIndex();
	void setIndex(long input);
	unsigned int getDataLen();
	void setDataLen(unsigned int input);
	int getAudioFormat();
	void setAudioFormat(int input);
	int getSampleRate();
	void setSampleRate(int input);
	int getNumberofChannels();
	void setNumberofChannels(int input);
	short getBitsPerSample();
	void setBitsPerSample(int input);
	int getByteRate();
	void setByteRate(int input);
	int getBlockAlign();
	void setBlockAlign(int input);
	
private:
		
		
	BYTE *m_Data;//buffer
	long index;//buffer index
	unsigned int m_DataLen;//size of buffer
	int m_AudioFormat;//audio format of the file or buffer being read
	int m_SampleRate;//sample rate
	int m_NumberofChannels;//mono or stereo
	short m_BitsPerSample;//bits per sample
	int m_ByteRate;//byte rate
	int m_BlockAlign;//size of each sample
	void Init();//initialize everything
	

};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ----------------------------------------------------------------
//  Class:			cData
//  Description:    data object for the play thread
// ----------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class cData
{
public:
	cData();//constructor
	~cData();//destructor
	SoundData* getSoundData();
	void setSoundData(SoundData* input);
	bool getLoop();
	void setLoop(bool input);
	SoundChannel* getSoundChannel();
	void setSoundChannel(SoundChannel* input);
	long getVolume();
	void setVolume(long input);

private:
	SoundData *Desc;//sound data object
	long VolumePercent;//volume var
	bool Loop;//loop var
	SoundChannel *sChannel;//sound channel object

};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ----------------------------------------------------------------
//  Class:			Sound
//  Description:    initializes directx primary sound buffer and initializes the notification events
// ----------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Sound
{
  private:
    // Sound system related
    HWND                      m_hWnd;//windows handle attribute

    long                      m_Volume;//volume attribute

    HANDLE                    m_Events[33];//events address array
    SoundChannel            *m_EventChannel[32];//events array that holds the channel of the spcific index 

    HANDLE                    m_hThread;//thread handle
    DWORD                     m_ThreadID;//id of the thread
    BOOL                      m_ThreadActive;//flag of activity thread
    static DWORD              HandleNotifications(LPVOID lpvoid);//event managing thread

    // Sound related
    IDirectSound8            *m_pDS;//directx sound object
    IDirectSoundBuffer       *m_pDSBPrimary;//directx buffer

    long                      m_CooperativeLevel;//priority of the hold of the buffer
    long                      m_Frequency;//frequency attribute
    short                     m_Channels;//channels attribute
    short                      m_BitsPerSample;//bits per sample
	
	
  public:
    Sound();//constructor
    ~Sound();//deconstructor

    // Assign and release events
    BOOL AssignEvent(SoundChannel *Channel, short *EventNum, HANDLE *EventHandle);
	//copies the event address from the event array to the event handle; sets the event array to it's counter
    BOOL ReleaseEvent(SoundChannel *Channel, short *EventNum);
	//release event from the array


    // Functions to retrieve COM interfaces
    IDirectSound8            *GetDirectSoundCOM();
    IDirectSoundBuffer       *GetPrimaryBufferCOM();
    

    // Init and shutdown functions
    BOOL Init(HWND hWnd, long Frequency = 22050, short Channels = 1, short BitsPerSample = 16, long CooperativeLevel = DSSCL_PRIORITY);
    //initializes the directx sound object and primary sound buffer
	BOOL Shutdown();
	//garbage collector for the class

    // Volume get/set
    long GetVolume();
	//return the volume level
    BOOL SetVolume(long Percent);
	//set the volume and return the bool value of success or fail

    // Restore system to known state
    BOOL Restore();
	template<class T>
	void ReleaseCOM(T& x);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// -----------------------------/-----------------------------------
//  Class:			SoundData
//  Description:    initializes directx primary sound buffer and initializes the notification events
// ----------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////
class SoundData
{
  friend class SoundChannel;//sound channel object

private:
	bool is_ogg;//flag whether or not the file is an off file
	FILE *m_fp;//file pointer
    BYTE *m_Ptr;//data pointer
    char *m_Buf;//data pointer
	CWAVFile *m_Pcm;//PCM data object
	long  m_Size;//size attribute
    long  m_Left;//position marker from the right to the left of the buffer
    long  m_StartPos;//start position after the RIFF header
    long  m_Pos;//position marker from the left to right of the buffer
	long  m_Frequency;//frequency attributes
    short m_Channels;//channels attributes
    short m_BitsPerSample;//bits per sample
	long g_SoundBufferSize; 
	long g_SoundBufferChunk;
	// = 65536;//maximum size of music file
//= g_SoundBufferSize / 4;//section the sound file will be divided up

  public:
    SoundData();//constructor
    ~SoundData();//deconstructor

	
    char *GetPtr();//return buffer
	CWAVFile *getPCMBUFFER();
    long GetSize();//return size of buffer

    //BOOL Create();//creates a new buffer with the size that is already set in the class
    //BOOL Create(long Size);//creates a new data buffer using the size set by the user
    BOOL Free();//frees all buffers and pointers

    BOOL SetFormat(long Frequency, short Channels, short BitsPerSample);
	//set new format for secondary sound buffer
    BOOL SetSource(FILE *fp, long Pos = -1, long Size = -1);
	//set the file pointer to the sound channel
    CWAVFile *SoundData::LoadOGG(char *Filename);
	//copies attributes of one class object to another
	
    FILE *LoadWAVHeader(char *Filename, FILE *fp = NULL);
	//set the attributes from the RIFF data of the wave file

    BOOL Copy(SoundData *Source);
	//copies attributes of one class object to another
	BOOL Load_OGG_Wav_Header(CWAVFile *data);
	//set the attributes from the RIFF data of the OGG file
	BOOL SetSource_WAV_OGG(CWAVFile *ptr);
	//sets the object pointer to the pcm data object
	bool SoundData::getIsOGG();
	CWAVFile *getPCM();
	long SoundData::getSize();
	template<class T>
	void ReleaseCOM(T& x);
	 

};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ----------------------------------------------------------------
//  Class:			SoundChannel
//  Description:    initializes a channel for music play, initializes secondary sound buffer, controls playback,
//					panning, volume control, looping control, frequency control, and notification management
// ----------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SoundChannel
{
  friend class Sound;//add sound class as a friend
	//friend class SoundData;
  protected:
    Sound              *m_Sound;//sound object
    IDirectSoundBuffer8 *m_pDSBuffer;//secondary directx sound buffer
    IDirectSoundNotify8 *m_pDSNotify;//directx sound notification
    short                m_Event;//event counter
	bool				isAlive;
    long                 m_Volume;//volume attribute
    signed long          m_Pan;//pan attribute
    bool                m_Playing;//playing flag
    bool                 m_Loop;//looping flag

    long                 m_Frequency;//frequency attribute
    short                m_BitsPerSample;//bits per sample attribute
    short                m_Channels;//channels attributes

    SoundData           m_Desc;//sound data object

    short                m_LoadSection;//holds the section number to load into the buffer
    short                m_StopSection;//holds end of the sound file section number
    short                m_NextNotify;//holds the next section to be added to the buffer
	int                       m_flag;//flag for the pause algorithm
	DWORD                dwCurrentPlayPos;//holds the current play position for pausing
	bool							m_Pause;//attribute that holds whether or not a sound file is paused
	bool is_ogg;		//attribute of whether a sound file is ogg file

    BOOL BufferData();//handles the copying from the sound file to the buffer for wav streaming
    BOOL Update();//sets the next section to be uploaded into the secondary buffer
	bool firstPlay;//flag to say whether or not a audio file has played one loop
	bool hasLooped;//flag to say whether or not an audio file is looping 
	bool startPlayLoop;//flag to say whethere an audio file is going to start to play as a looped audio file

  public:
    SoundChannel();//constructor
    ~SoundChannel();//deconstructor

    IDirectSoundBuffer8 *GetSoundBufferCOM();//sound buffer COM
    IDirectSoundNotify8 *GetNotifyCOM();//notification COM
	//create sound channel with sound file attributes
	BOOL Create(Sound *Sound, long Frequency, short Channels, short BitsPerSample, bool is_ogg, long Size,long wave_chunk=0, long wave_size=4);

	//create sound channel
	BOOL Create(Sound *Sound, SoundData *SoundDesc);
    //create sound channel with default arguments
	BOOL Free();//garbage collector
    
    static DWORD WINAPI Play(LPVOID lpvoid);//play function that's a thread
	BOOL Stop();//stop playback

    long GetVolume();//get the volume of the current playback
    BOOL SetVolume(long Percent);//set the volume of the current playback

    signed long GetPan();//get pan level from the playback
    BOOL SetPan(signed long Level);//set the pan level to the current playback

    long GetFrequency();//get frequency of the current playback
    BOOL SetFrequency(long Level);//set the frequency of the current playback
    
    bool IsPlaying();//flag that states whether the current song is playing or not

	bool IsPaused();//flag that states whether the current playback is paused or not

	
	void ChangePauseState();//change the current pause state of the current playback

	char* buffer_read(char *buffer, DWORD size,DWORD count,CWAVFile *stream);//proxy fread
	
	BOOL LoadSoundData(long LockPos, BYTE *fp, long Size);//copy pcm data into secondary buffer
	
	void setLoop(bool input);//set the loop value
	bool isLoop();//get audio loop flag value
	bool isOgg();//get flag value ogg file type
	void setOgg(bool input);//set ogg flag
	void playWav(SoundChannel* input);//play wav file based on the provided node reference
	
	int nonLoopPlay();//
	int LoopPlay();
	void setFirstPlay(bool input);
	bool getFirstPlay();
	void sethasLooped(bool input);
	bool gethasLooped();
	template<class T>
	void ReleaseCOM(T& x);
	int Read( BYTE* pBuffer,BYTE* input, DWORD dwSizeToRead, DWORD* pdwSizeRead );
	void setAlive(bool input);
	bool getAlive();
	void turnon(bool input);

	
	
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ----------------------------------------------------------------
//  Class:			sWaveHeader
//  Description:    structure to hold the attribute of any wave file
// ----------------------------------------------------------------
////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma pack(1) //multiple of 1 byte
typedef struct sWaveHeader
{
  char  RiffSig[4];//File Header Signature
  long  WaveformChunkSize;//buffer size
  char  WaveSig[4];//PCM signature
  char  FormatSig[4];//format signature
  long  FormatChunkSize;//not used
  short FormatTag;//not used
  short Channels;//number channels in the PCM
  long  SampleRate;//sample frequency
  long  BytesPerSec;//byte rate
  short BlockAlign;//number of bytes per sample rate
  short BitsPerSample;//number of bits per sample
  char  DataSig[4];//data signature
  long  DataSize;//size of buffer
} sWaveHeader;
#pragma pack() 

#endif
