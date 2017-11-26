#ifndef __MODULETEXTURES_H__
#define __MODULETEXTURES_H__

#include<list>
#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleTextures : public Module
{
public:
	ModuleTextures();
	~ModuleTextures();

	bool Init();
	bool CleanUp();

	SDL_Texture* const Load(const char* path);
	SDL_Texture * const LoadWithColorKey(const char * path, Uint8 red, Uint8 green, Uint8 blue);
	void Unload(SDL_Texture* texture);

private:
	std::list<SDL_Texture*> textures;
};

#endif // __MODULETEXTURES_H__