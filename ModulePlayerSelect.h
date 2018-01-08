#pragma once
#include "Module.h"

class ModulePlayerSelect : public Module
{
public:
	ModulePlayerSelect(bool active = true);
	~ModulePlayerSelect();

	bool Start();
	update_status Update();
	bool CleanUp();

	SDL_Texture* background = nullptr;
	SDL_Rect playerRedRect;
	SDL_Rect playerBlueRect;
	SDL_Rect spreedShopRect;
	uint fx = 0;
	Uint32 start_time = 0;
	Uint32 start_timeTemp = 0;

	Uint32 total_time = 0;

	bool firstTime = true;
};

