#pragma once

#include "Entity.h"
#include "Animation.h"
#include "Point.h"

struct SDL_Texture;

class Path;

class Player: public Entity
{
public:
	Player(fPoint posiiton, int numPlayer);
	~Player();

	void Paint() override;
	void CleanUp() override;
	void OnCollide(Collider* extType, CollisionState colState) override;
	void DebugDraw();

private:
	float GetAngleSprite(float angle);
	fPoint PathFollowing();

public:

	SDL_Texture* graphics = nullptr;
	vector<SDL_Rect> rotationCarSprites;
	vector<SDL_Rect> rotationShadowSprites;
	vector<float> anglesRot;
	SDL_Rect currentRect;
	fPoint position;

	Path* path = nullptr;
	int currentNode = 0;

	Collider* collider = nullptr;

	float speed = 0.f;
	float angle = 0.f;
	float maxSpeed = 12.0f;
	float acc = 0.2f;
	float dec = 0.3f;
	float turnSpeed = 0.08f;
	int height = 0;

	int lap = 0;
	int nitros = 10;

	int curentSpritePos = 0;

	int numPlayer = 1;

	bool debug = false;
};

