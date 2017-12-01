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

	void Paint();
	void CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	vector<SDL_Rect> rotationCarSprites;
	vector<SDL_Rect> rotationShadowSprites;
	SDL_Rect currentRect;
	fPoint position;

	float speed = 0;
	float angle = 0;
	float maxSpeed = 12.0;
	float acc = 0.2;
	float dec = 0.3;
	float turnSpeed = 0.08;
};

