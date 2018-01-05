#include "Globals.h"
#include "Application.h"
#include "ModuleFonts.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"



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

	graphics = App->textures->LoadWithColorKey("Resources/Images/Level/Levels2.png", 0xBA, 0xFE, 0xCA);

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
