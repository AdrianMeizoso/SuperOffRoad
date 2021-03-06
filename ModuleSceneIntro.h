#ifndef __MODULESCENEINTRO_H__
#define __MODULESCENEINTRO_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(bool active = true);
	~ModuleSceneIntro();

	bool Start() override;
	update_status Update() override;
	bool CleanUp() override;

public:
	
	SDL_Texture* background = nullptr;
	SDL_Rect rect;
	Uint32 start_time = 0;
	Uint32 total_time = 0;
};

#endif // __MODULESCENEINTRO_H__