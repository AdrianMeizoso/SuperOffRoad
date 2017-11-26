#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer(bool active = true);
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

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

#endif