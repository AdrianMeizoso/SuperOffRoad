#pragma once
#include "Module.h"

class ModulePlayerSelect : public Module
{
public:
	ModulePlayerSelect(bool active = true);
	~ModulePlayerSelect();

	bool Start() override;
	update_status Update() override;
	bool CleanUp() override;

	SDL_Texture* background = nullptr;
	SDL_Rect playerRedRect;
	SDL_Rect playerBlueRect;
	SDL_Rect spreedShopRect;

	Uint32 start_time = 0;
	Uint32 start_timeTemp = 0;

	Uint32 total_time = 0;

	bool firstTime = true;
	bool firstPlayerActive = false;
	bool secondPlayerActive = false;

};

