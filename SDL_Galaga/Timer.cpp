#include "Timer.h"

Timer* Timer::sInstance = nullptr;

Timer* Timer::Instance()
{
	//if a istance of Timer is already created then the function returns that instance..
	//..otherwise an instance of Timer is created and then returned
	if (!sInstance)
	{
		sInstance = new Timer();
	}
	return sInstance;
}

void Timer::Release()
{
	//clearing up the memory used by the instance of the timer before shuting down
	delete sInstance;
	sInstance = nullptr;
}



void Timer::Reset()
{
	//gets the number of milliseconds since the start of SDL initialization
	mStartTicks = SDL_GetTicks();
	mElapsedTicks = 0;
	mDeltaTime = 0.0f;
}


//returning our deltatime value
float Timer::DeltaTime()
{
	return mDeltaTime;
}


void Timer::TimeScale(float t)
{
	mTimeScale = t;
}


float Timer::TimeScale()
{
	return mTimeScale;
}


void Timer::Update()
{
	//ticks that happen inbetween the last reset and our time right now
	mElapsedTicks = SDL_GetTicks() - mStartTicks;
	//elapsed ticks are in "int" so for deltaTime to use it we convert it to a float value..
	//..by multiplying with a milliseconds
	mDeltaTime = mElapsedTicks * 0.001f;
}


Timer::Timer()
{
	//sett our timescale an reset all our values
	Reset();
	mTimeScale = 1.0f;

}


Timer::~Timer()
{


}
