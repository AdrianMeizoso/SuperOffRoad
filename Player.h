#pragma once

#include "Entity.h"
#include "Animation.h"
#include "Point.h"

struct SDL_Texture;

class Player: public Entity
{
public:
	Player();
	~Player();

	void Paint() override;
	void CleanUp() override;
	void OnCollide(Collider* extType, CollisionState colState) override;

private:
	float GetAngleSprite(float angle);

public:

	SDL_Texture* graphics = nullptr;
	vector<SDL_Rect> rotationCarSprites;
	vector<SDL_Rect> rotationShadowSprites;
	vector<float> anglesRot;
	SDL_Rect currentRect;
	fPoint position;

	Collider* collider = nullptr;

	float speed = 0.f;
	float angle = 0.f;
	float maxSpeed = 12.0f;
	float acc = 0.2f;
	float dec = 0.3f;
	float turnSpeed = 0.08f;
	int height = 0;

	int curentSpritePos = 0;
};

