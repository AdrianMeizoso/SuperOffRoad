#pragma once
#include "Entity.h"
#include "Animation.h"

struct SDL_Texture;

enum State { DISABLE, LARGE, SMALL };

class Flag : public Entity
{
public:
	Flag(int x, int y);
	~Flag();

	void Paint() override;
	void CleanUp() override;
	void OnCollide(Collider* extType, CollisionState colState) override;

public:
	int x = 0;
	int y = 0;

	bool active = false;
	bool firstTime = true;

	SDL_Texture* background = nullptr;

	Animation idle;
	Animation large;
	Animation small;

	Animation* currentAnimation;

	Collider* flagCollider;

	Uint32 start_time = 0;
	Uint32 total_time = 0;
	
	State state;
};

