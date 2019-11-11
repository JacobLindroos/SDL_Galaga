#include "GameEntity.h"

GameEntity::GameEntity(float x, float y)
{
	mPosition.x = x;
	mPosition.y = y;

	mRotation = 0.0f;

	mActive = true;

	mParent = nullptr;
}

GameEntity::~GameEntity()
{
	mParent = nullptr;
}

void GameEntity::Position(Vector2 pos)
{
	mPosition = pos;
}

Vector2 GameEntity::Position(SPACE space)
{
	if (space == local || mParent == nullptr)
	{
		return mPosition;
	}
	
	return mParent->Position(world) + RotateVector(mPosition, mParent->Rotation(local));
}


//to keep our rotation between 0-360 degrees
void GameEntity::Rotation(float rotation)
{
	mRotation = rotation;

	if (mRotation > 360.0f)
	{
		mRotation -= 360.0f;
	}

	if (mRotation < 0.0f)
	{
		mRotation += 360.0f;
	}
}

float GameEntity::Rotation(SPACE space)
{
	if (space == local || mParent == nullptr)
	{
		return mRotation;
	}

	return mParent->Rotation(world) + mRotation;
}

void GameEntity::Active(bool active)
{
	mActive = active;
}

bool GameEntity::Active()
{
	return mActive;
}

void GameEntity::Parent(GameEntity* parent)
{
	mPosition = Position(world) - parent->Position(world);

	mParent = parent;
}

GameEntity* GameEntity::Parent()
{
	return mParent;
}

void GameEntity::Update()
{

}

void GameEntity::Render()
{
}
