#pragma once

#include "Graphics.h"
#include <map>


class AssetManager
{
public:

private:
	static AssetManager* sInstance;

	std::map<std::string, SDL_Texture*> mTexture;

public:
	static AssetManager* Instance();
	static void Release();

	SDL_Texture* GetTexture(std::string fileName);

private:
	AssetManager();
	~AssetManager();
	
};

