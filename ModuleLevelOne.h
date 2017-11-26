#ifndef __MODULELEVELONE_H__
#define __MODULELEVELONE_H__

#include "Module.h"

struct SDL_Texture;

class ModuleLevelOne : public Module
{
public:
	ModuleLevelOne(bool active = true);
	~ModuleLevelOne();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
	SDL_Rect rect;
};

#endif // __MODULESCENESPACE_H__