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
	void OnCollide() override;

public:
	int x = 0;
	int y = 0;

	bool active = false;

	SDL_Texture* background = nullptr;

	Animation idle;
	Animation large;
	Animation small;

	Animation* currentAnimation;

	Collider* flagCollider;
};

