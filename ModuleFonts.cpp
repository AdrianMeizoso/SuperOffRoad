#include "Globals.h"
#include "Application.h"
#include "ModuleFonts.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include <sstream>
#include <vector>



ModuleFonts::ModuleFonts()
{
}


ModuleFonts::~ModuleFonts()
{
}

bool ModuleFonts::Init()
{
	charRect = {160, 6413, 10, 16};
	colonRect = { 368, 6464, 6, 16 };

	fontSelectPlayer['0'] = { 12, 1634, 24, 30 };
	fontSelectPlayer['1'] = { 44, 1634, 20, 30 };
	fontSelectPlayer['2'] = { 76, 1634, 24, 30 };
	fontSelectPlayer['3'] = { 108, 1634, 24, 30 };
	fontSelectPlayer['4'] = { 140, 1634, 24, 30 };
	fontSelectPlayer['5'] = { 172, 1634, 24, 30 };
	fontSelectPlayer['6'] = { 204, 1634, 24, 30 };
	fontSelectPlayer['7'] = { 236, 1634, 24, 30 };
	fontSelectPlayer['8'] = { 268, 1634, 24, 30 };
	fontSelectPlayer['9'] = { 300, 1634, 24, 30 };
	fontSelectPlayer['A'] = { 332, 1634, 24, 30 };
	fontSelectPlayer['B'] = { 364, 1634, 24, 30 };
	fontSelectPlayer['C'] = { 396, 1634, 24, 30 };
	fontSelectPlayer['D'] = { 428, 1634, 24, 30 };
	fontSelectPlayer['E'] = { 460, 1634, 24, 30 };
	fontSelectPlayer['F'] = { 492, 1634, 24, 30 };
	fontSelectPlayer['G'] = { 524, 1634, 24, 30 };
	fontSelectPlayer['H'] = { 556, 1634, 24, 30 };
	fontSelectPlayer['I'] = { 558, 1634, 20, 30 };
	fontSelectPlayer['J'] = { 620, 1634, 24, 30 };
	fontSelectPlayer['K'] = { 652, 1634, 24, 30 };
	fontSelectPlayer['L'] = { 684, 1634, 24, 30 };
	fontSelectPlayer['M'] = { 716, 1634, 24, 30 };
	fontSelectPlayer['N'] = { 748, 1634, 24, 30 };
	fontSelectPlayer['O'] = { 780, 1634, 24, 30 };
	fontSelectPlayer['P'] = { 812, 1634, 24, 30 };
	fontSelectPlayer['Q'] = { 844, 1634, 24, 30 };
	fontSelectPlayer['R'] = { 876, 1634, 24, 30 };
	fontSelectPlayer['S'] = { 908, 1634, 24, 30 };
	fontSelectPlayer['T'] = { 940, 1634, 24, 30 };
	fontSelectPlayer['U'] = { 972, 1634, 24, 30 };
	fontSelectPlayer['V'] = { 1004, 1634, 24, 30 };
	fontSelectPlayer['W'] = { 1036, 1634, 24, 30 };
	fontSelectPlayer['X'] = { 1068, 1634, 24, 30 };
	fontSelectPlayer['Y'] = { 1100, 1634, 24, 30 };
	fontSelectPlayer['Z'] = { 1132, 1634, 24, 30 };
	fontSelectPlayer[' '] = { 1068, 1666, 24, 30 };

	fontSelectPlayer['!'] = { 160, 1634, 10, 16 };
	fontSelectPlayer['"'] = { 160, 1634, 10, 16 };
	fontSelectPlayer['.'] = { 160, 1634, 10, 16 };
	fontSelectPlayer[','] = { 160, 1634, 10, 16 };
	fontSelectPlayer['_'] = { 160, 1634, 10, 16 };
	fontSelectPlayer['?'] = { 160, 1634, 10, 16 };
	fontSelectPlayer['*'] = { 160, 1634, 10, 16 };
	fontSelectPlayer['º'] = { 160, 1634, 10, 16 };
	fontSelectPlayer['+'] = { 160, 1634, 10, 16 };
	fontSelectPlayer['€'] = { 160, 1634, 10, 16 };
	fontSelectPlayer[';'] = { 160, 1634, 10, 16 };

	graphics = App->textures->LoadWithColorKey("Resources/Images/Level/Levels2.png", 0xBA, 0xFE, 0xCA);
	fontBack = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0xBA, 0xFE, 0xCA);

	return true;
}

void ModuleFonts::print(int num, bool doubleNumber, int x, int y, TextColor color)
{
	SDL_Rect colorRect = charRect;
	colorRect.y += charRect.h * color + color;

	if (num < 10)
	{
		if (doubleNumber) App->renderer->Blit(graphics, x, y , &colorRect);
		SDL_Rect numRect = colorRect;
		numRect.x += charRect.w * num + 6 * num;
		if (doubleNumber)
		{
			App->renderer->Blit(graphics, x + charRect.w, y, &numRect);
		}
		else {
			App->renderer->Blit(graphics, x, y, &numRect);
		}
	}
	else {
		int first = num / 10;
		int second = num % 10;

		SDL_Rect firstNumRect = colorRect;
		firstNumRect.x += charRect.w * first + 6 * first;

		SDL_Rect secondNumRect = colorRect;
		secondNumRect.x += charRect.w * second + 6 * second;

		App->renderer->Blit(graphics, x, y, &firstNumRect);
		App->renderer->Blit(graphics, x + charRect.w, y, &secondNumRect);
	}

}

void ModuleFonts::print(float num, bool doubleNumber, int x, int y, TextColor color)
{
	SDL_Rect colorRect = charRect;
	colorRect.y += charRect.h * color + color;

	if (num < 10) {
		App->renderer->Blit(graphics, x, y, &colorRect);
		int second = 0;

		if (num < 1)
		{
			App->renderer->Blit(graphics, x + charRect.w, y, &colorRect);

			second = num * 10;
		}
		else {
			int temp = num * 10;

			int first = num;
			second = temp % 10;

			print(first, false, x + charRect.w, y, color);
		}

		App->renderer->Blit(graphics, x + charRect.w * 2, y, &colonRect);
		print(second, false, x + charRect.w * 2 + colonRect.w, y, color);
	}
	else
	{
		int first = num;
		print(first, false, x, y, color);

		int temp = num * 10;
		int second = temp % 10;

		App->renderer->Blit(graphics, x + charRect.w * 2 , y, &colonRect);
		print(second, false, x + charRect.w * 2  + colonRect.w, y, color);
	}
}

void ModuleFonts::print(char let, int x, int y)
{
	SDL_Rect* currentRect = &fontSelectPlayer[let];
	App->renderer->Blit(fontBack, x, y, currentRect);
}

void ModuleFonts::print(std::string phr, int x, int y)
{
	std::stringstream ss(phr);
	char let;
	std::vector<std::string> seglist;
	int newX = x;

	while (ss >> let) {
		print(let, newX, y);
		newX += 16;
	}
}

