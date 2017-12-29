#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

#include "Entity.h"

struct SDL_Texture;

class Scoreboard : public Entity
{
public:
	Scoreboard(int x, int y);
	~Scoreboard();

	void Paint() override;
	void CleanUp() override;

public:
	int x = 0;
	int y = 0;

	SDL_Rect rect;
	SDL_Texture* background = nullptr;
};

#endif
