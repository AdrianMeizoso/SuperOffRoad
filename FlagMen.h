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
	void OnCollide(TypeCollider extType) override;

	int x = 0;
	int y = 0;

	bool active = false;

	SDL_Texture* background = nullptr;

	Animation run;
};

