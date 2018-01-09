#pragma once
#include "Module.h"

struct SDL_Texture;

class ModuleSceneTitle : public Module
{

public:
	ModuleSceneTitle(bool active = true);
	~ModuleSceneTitle();

	bool Start() override;
	update_status Update() override;
	bool CleanUp() override;

public:

	SDL_Texture * background = nullptr;
	SDL_Rect rect;
	Uint32 start_time = 0;
	Uint32 total_time = 0;
};

