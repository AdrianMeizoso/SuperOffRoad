#ifndef __MODULELEVELONE_H__
#define __MODULELEVELONE_H__

#include "Module.h"

class Flag;
class Npc;
class Scoreboard;
class Player;

struct SDL_Texture;

class ModuleLevelOne : public Module
{
public:
	ModuleLevelOne(bool active = true);
	~ModuleLevelOne();

	bool Start();
	update_status Update();
	bool CleanUp();

	int getHeightInPosition();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* stars = nullptr;
	SDL_Rect rect;
	SDL_Rect rectAlter;
	SDL_Rect rectTitleLevel;

	Scoreboard* scoreboard;
	Player* player;
	Npc* npcAzul;
	Flag* flag;
	Flag* flag2;
	Flag* flag3;

	int* heightMap = nullptr;
};

#endif // __MODULESCENESPACE_H__