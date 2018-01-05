#pragma once
#include "Entity.h"
#include "Animation.h"

struct SDL_Texture;

class FlagMen : public Entity
{
public:
	FlagMen(int x, int y);
	~FlagMen();

	void Paint() override;
	void CleanUp() override;

public:
	bool active = false;
	bool firstTime = true;

	SDL_Texture* background = nullptr;

	Uint32 start_time = 0;
	Uint32 total_time = 0;

	Animation run;
};

