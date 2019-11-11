#pragma once

#include "MathHelper.h"

//gameentity will be our base class for every game object we create
class GameEntity
{
public:

	enum SPACE {local = 0, world = 1};

private:

	Vector2 mPosition;
	float mRotation;

	//will tell us if the game object is active or not
	bool mActive;

	//This will make us able to get one entity and make it a child to another entity..
	//..e.g linking objects togehter, so if we have x objects attached to one parent..
	//..and we are rotating the parent we might want to rotatet those attached object with..
	//..the parent
	GameEntity* mParent;

public:

	GameEntity(float x = 0.0f, float y = 0.0f);
	~GameEntity();

	//setter for entity position
	void Position(Vector2 pos);
	//getter of entity position
	//local space = relative to the parent
	//world space = relative to the normal grid
	Vector2 Position(SPACE space = world);

	void Rotation(float rotation);
	float Rotation(SPACE space = world);

	void Active(bool active);
	bool Active();

	void Parent(GameEntity* parent);
	GameEntity* Parent();

	virtual void Update();
	virtual void Render();
};