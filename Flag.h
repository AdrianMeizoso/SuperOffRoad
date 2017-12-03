#pragma once
#include "Entity.h"
#include "Animation.h"

struct SDL_Texture;

class Flag : public Entity
{
public:
	Flag(int x, int y);
	~Flag();

	void Paint() override;
	void CleanUp() override;

public:
	int x = 0;
	int y = 0;

	SDL_Texture* background = nullptr;

	Animation idle;
	Animation large;
	Animation small;

	Animation* currentAnimation;
};

