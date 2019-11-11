#include "Graphics.h"
#include <iostream>

Graphics* Graphics::sInstance = nullptr;
bool Graphics::sInitialized = false;


Graphics* Graphics::Instance()
{
	//if a istance of graphics is already created then the function returns that instance..
	//..otherwise an instance of graphics is created and then returned
	if (!sInstance)
	{
		sInstance = new Graphics();
	}
	return sInstance;
}


void Graphics::Release()
{	
	//clearing up the memory used by the instance of the graphics before shuting down
	delete sInstance;
	sInstance = nullptr;
	sInitialized = false;
}


bool Graphics::Initialized()
{
	return sInitialized;
}


//initzializing when app is starting up
Graphics::Graphics()
{
	mBackBuffer = nullptr;
	sInitialized = Init();
}

Graphics::~Graphics()
{
	//Upon shuting down the app we clear the renderer from the heap memory
	SDL_DestroyWindow(mWindow);
	mWindow = nullptr;
	
	//Upon shuting down the app we clear the renderer from the heap memory
	SDL_DestroyRenderer(mRenderer);
	mRenderer = nullptr;

	//Unloads libraries loaded with IMG_Init and SDL_Init, clearing the taken space on the heap memory
	IMG_Quit();
	SDL_Quit();
}

bool Graphics::Init()
{
	//initializing Init
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL_Init error: " << SDL_GetError() << std::endl;
		return false;
	}

	//creating the window if SDL_init didnt get a error
	mWindow = SDL_CreateWindow("SDL Galaga", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	//if we didn´t get a window we throw an error that it wasnt created
	if (!mWindow)
	{
		std::cout << "SDL_Window error: " << SDL_GetError() << std::endl;
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	if (!mRenderer)
	{
		std::cout << "SDL_Renderer error: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	int flags = IMG_INIT_PNG;
	if (!(IMG_Init(flags) & flags))
	{
		std::cout << "IMG_Initialization error: " << IMG_GetError() << std::endl;
		return false;
	}

	//rendering our surface to our window?
	mBackBuffer = SDL_GetWindowSurface(mWindow);

	return true;
}


SDL_Texture* Graphics::LoadTexture(std::string filePath)
{
	//texture to return
	SDL_Texture* tex = nullptr;
	//surface that takes loads up the image file
	SDL_Surface* surface = IMG_Load(filePath.c_str());
	if (!surface)
	{
		//if something went wrong loading the image file, an error is thrown..
		//..and the loops stops by returning false
		std::cout << "Image load error: " << filePath.c_str() << " - " << IMG_GetError() << std::endl;
		return false;
	}

	tex = SDL_CreateTextureFromSurface(mRenderer, surface);
	if (!tex)
	{
		//if something went wrong creating the texture from the surface, an error is thrown..
		//..and the loops stops by returning false
		std::cout << "Create texture error: " << SDL_GetError() << std::endl;
		return false;
	}

	//if everything went just fine we free the heap memoryspace and return the texture..
	//..if the heap memoryspace is not cleared it will take up memory and "leak" memory 
	SDL_FreeSurface(surface);
	return tex;
}


void Graphics::ClearBackBuffer()
{
	SDL_RenderClear(mRenderer);
}

void Graphics::DrawTexture(SDL_Texture* tex, SDL_Rect* clip, SDL_Rect* rend)
{
	SDL_RenderCopy(mRenderer, tex, clip, rend);
}


void Graphics::Render()
{
	//refresh the backbuffer of that window
	SDL_RenderPresent(mRenderer);
}