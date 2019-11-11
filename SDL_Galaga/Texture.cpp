#include "Texture.h"

Texture::Texture(std::string fileName)
{
	mGraphics = Graphics::Instance();

	mTexture = AssetManager::Instance()->GetTexture(fileName);

	SDL_QueryTexture(mTexture, NULL, NULL, &mWidth, &mHeight);

	mClipped = false;

	mRenderRect.w = mWidth;
	mRenderRect.h = mHeight;
}

Texture::Texture(std::string fileName, int x, int y, int w, int h)
{
	mGraphics = Graphics::Instance();

	mTexture = AssetManager::Instance()->GetTexture(fileName);

	mClipped = true;

	mWidth = w;
	mHeight = h;

	mRenderRect.w = mWidth;
	mRenderRect.h = mHeight;

	mClipRect.x = x;
	mClipRect.y = y;
	mClipRect.w = mWidth;
	mClipRect.h = mHeight;
}

Texture::~Texture()
{
	//setting the variables to nullptr's, just to get rid of dangling ptr 
	mTexture = nullptr;
	mGraphics = nullptr;
}

void Texture::Render()
{
	Vector2 pos = Position(world);
	//gives a centerposition
	mRenderRect.x = (int)(pos.x - mWidth * 0.5f);
	mRenderRect.y = (int)(pos.y - mHeight * 0.5f);

	mGraphics->DrawTexture(mTexture,(mClipped)? &mClipRect : NULL, &mRenderRect);
}
