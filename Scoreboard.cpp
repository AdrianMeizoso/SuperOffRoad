#include "Globals.h"
#include "Scoreboard.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"


Scoreboard::Scoreboard(int x, int y) : x(x), y(y)
{
	rect.h = 62;
	rect.w = 124;
	rect.x = 15;
	rect.y = 6419;

	background = App->textures->LoadWithColorKey("Resources/Images/Level/Levels.png", 0xBA, 0xFE, 0xCA);
}

Scoreboard::~Scoreboard()
{
}

void Scoreboard::Paint() 
{
	App->renderer->Blit(background, x, y, &rect);
}

void Scoreboard::CleanUp()
{
}

void Scoreboard::OnCollide(){ /*No collision*/ }
