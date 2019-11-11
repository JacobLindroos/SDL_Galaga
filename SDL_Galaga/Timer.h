#pragma once

#include <SDL.h>

//Game timer to limit our framerate for our game to 60 or 120 FPS e.g.
//singleton class
class Timer
{
public:

private:

	static Timer* sInstance;

	unsigned int mStartTicks;
	unsigned int mElapsedTicks;
	float mDeltaTime;
	float mTimeScale;

public:
	static Timer* Instance();
	static void Release();

	void Reset();
	//returning our deltatime variable
	float DeltaTime();
	//setting our timeScale variable
	void TimeScale(float t);
	//returning our timescale variable
	float TimeScale();
	//to update our timer
	void Update();

private:

	Timer();
	~Timer();
	

};

