#include "GameManager.h"
#include <iostream>

GameManager* GameManager::sInstance = nullptr;

GameManager* GameManager::Instance()
{
	//if a istance of gameManager is already created then the function returns that instance..
	//..otherwise an instance of gameManager is created and then returned
	if (!sInstance)
	{
		sInstance = new GameManager();
	}
	return sInstance;
}

void GameManager::Release()
{
	//clearing up the memory before shuting down
	delete sInstance;
	sInstance = nullptr;
}

void GameManager::Run()
{
	//as long as mQuit is false the game loop will continue..
	//..mQuit can only be true if the user click´s the "X" in the window
	while (!mQuit)
	{
		//updates the timer of each iteration of the loop
		mTimer->Update();

		//as long as the event type returns 1 the loop will contiune..
		//whitin this loop all the drawing and update will happen
		while (SDL_PollEvent(&mEvents) != 0)
		{
			//if the user clicks the "X" in the window mQuit is set to be true..
			//..which quits the application
			if (mEvents.type == SDL_QUIT)
			{
				mQuit = true;
			}
		}

		if (mTimer->DeltaTime() >= (1.0f / FRAME_RATE))
		{
			//std::cout << "DeltaTime: " << mTimer->DeltaTime() << std::endl;
			//printf("DeltaTime: %F\n", mTimer->DeltaTime());

			mGraphics->ClearBackBuffer();
			mTexture->Render();

			mGraphics->Render();
			mTimer->Reset();
		}
	}
}


GameManager::GameManager()
{
	mQuit = false;
	//initialize the graphics
	mGraphics = Graphics::Instance();
	//if graphics wasn´t initialized correclty we throw an error and quit the game loop and the app
	if (!Graphics::Initialized())
	{
		std::cout << "Graphics error, not created." << std::endl;
		mQuit = true;
	}

	mAssetManager = AssetManager::Instance();

	mTimer = Timer::Instance();

	mTexture = new Texture("Galaga_SpriteSheet.png", 181, 52, 21, 21);
	mTexture->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f));
}

GameManager::~GameManager()
{
	Graphics::Release();
	mGraphics = nullptr;

	AssetManager::Release();
	mAssetManager = nullptr;

	Timer::Release();
	mTimer = nullptr;

	delete mTexture;
	mTexture = nullptr;
}
