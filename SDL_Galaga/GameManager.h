#pragma once

#include "Texture.h"
#include "Timer.h"

class GameManager
{
public:

private:

	static GameManager* sInstance;

	const int FRAME_RATE = 120;

	bool mQuit;
	Graphics* mGraphics;
	AssetManager* mAssetManager;

	Timer* mTimer;
	//handling events the user will give as input
	SDL_Event mEvents;

	Texture* mTexture;


public:

	static GameManager* Instance();
	static void Release();

	void Run();

private:

	GameManager();
	~GameManager();
};

