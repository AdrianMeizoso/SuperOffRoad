#pragma once
#include "Module.h"

struct SDL_Texture;

enum TextColor
{
	TEXTGRAY = 0,
	TEXTORANGE = 1,
	TEXTBLUE = 2,
	TEXTRED = 3
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

