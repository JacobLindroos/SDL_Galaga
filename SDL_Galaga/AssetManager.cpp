#include "AssetManager.h"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager* AssetManager::Instance()
{
	if (!sInstance)
	{
		sInstance = new AssetManager();
	}
	return sInstance;
}

void AssetManager::Release()
{
	delete sInstance;
	sInstance = nullptr;
}

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
	for (auto tex : mTexture)
	{
		if (tex.second != nullptr)
		{
			SDL_DestroyTexture(tex.second);
		}
	}
	mTexture.clear();
}


SDL_Texture* AssetManager::GetTexture(std::string fileName)
{
	std::string fullPath = SDL_GetBasePath();
	fullPath.append("Assets/Sprites/" + fileName);

	if (mTexture[fullPath] == nullptr)
	{
		mTexture[fullPath] = Graphics::Instance()->LoadTexture(fullPath);
	}

	return mTexture[fullPath];
}