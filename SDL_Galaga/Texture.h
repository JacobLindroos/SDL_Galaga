#pragma once

#include "GameEntity.h"
#include "AssetManager.h"

class Texture : public GameEntity
{
public:

private:
	SDL_Texture* mTexture;
	Graphics* mGraphics;

	int mWidth;
	int mHeight;
	
	bool mClipped;
	SDL_Rect mRenderRect;
	SDL_Rect mClipRect;

public:
	//getting a image-file and uploading it
	Texture(std::string fileName);
	Texture(std::string fileName, int x, int y, int w, int h);
	//clearing the heap memory upon shuting down 
	~Texture();

	virtual void Render();

};

