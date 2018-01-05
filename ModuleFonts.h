#pragma once
#include "Module.h"

struct SDL_Texture;

enum TextColor
{
	GRAY = 0,
	ORANGE = 1,
	BLUE = 2,
	RED = 3
};

class ModuleFonts : public Module
{
public:
	ModuleFonts();
	~ModuleFonts();

	bool Init() override;

	void print(int num, bool doubleNumber, int x, int y, TextColor color);
	void print(float num, bool doubleNumber, int x, int y, TextColor color);

public:

	SDL_Texture * graphics = nullptr;
	SDL_Rect charRect;
	SDL_Rect colonRect;
};

