#pragma once

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <SDL_image.h>

//singelton class
class Graphics
{
public:

	//keep track of the width and height of the windowscreen
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

private:
	static Graphics* sInstance;
	//this will be set to true if everything created went fine
	static bool sInitialized;

	SDL_Window* mWindow;
	SDL_Surface* mBackBuffer;
	SDL_Renderer* mRenderer;

public:
	static Graphics* Instance();
	static void Release();
	static bool Initialized();

	//function for uploading a texture
	SDL_Texture* LoadTexture(std::string filePath);
	//function that clears taken space by the renderer on the heap memory
	void ClearBackBuffer();
	//function that renders a texture to our window
	void DrawTexture(SDL_Texture* tex, SDL_Rect* clip = nullptr, SDL_Rect* rend = nullptr);

	//refresh our backbuffer once we are ready to draw to the window/screen
	void Render();

private:
	Graphics();
	//used for clearing the heap memoryspace and quiting SDL & IMG
	~Graphics();

	bool Init();
};

