#ifndef __MODULELEVELONE_H__
#define __MODULELEVELONE_H__

#include "Module.h"

class Flag;
class Npc;
class Scoreboard;
class Player;
class FlagMen;

struct SDL_Texture;

class ModuleLevelOne : public Module
{
public:
	ModuleLevelOne(bool active = true);
	~ModuleLevelOne();

	bool Start() override;
	update_status Update() override;
	bool CleanUp() override;

	int getHeightInPosition(int x, int y);
	int getTextureInPosition(int x, int y);
	void DidLap();

public:

	SDL_Texture* background = nullptr;
	SDL_Texture* graphics = nullptr;
	SDL_Texture* stars = nullptr;
	SDL_Rect rect;
	SDL_Rect rectAlter;
	SDL_Rect rectTitleLevel;

	Scoreboard* scoreboard = nullptr;

	Player* player = nullptr;
	Player* player2 = nullptr;

	Npc* npcAzul = nullptr;
	Npc* npcRed = nullptr;
	Npc* npcYellow = nullptr;
	Npc* npcGray = nullptr;

	Flag* flag = nullptr;
	Flag* flag2 = nullptr;
	Flag* flag3 = nullptr;

	FlagMen* flagMen;

	int* heightMap = nullptr;
	int* textureMap = nullptr;
};

#endif // __MODULESCENESPACE_H__