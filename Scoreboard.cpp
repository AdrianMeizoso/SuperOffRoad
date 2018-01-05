#include "Globals.h"
#include "Scoreboard.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"

#include "SDL\include\SDL.h"


Scoreboard::Scoreboard(int x, int y) : x(x), y(y)
{
	rect.h = 62;
	rect.w = 124;
	rect.x = 15;
	rect.y = 6419;

	start_time = SDL_GetTicks();

	background = App->textures->LoadWithColorKey("Resources/Images/Level/Levels.png", 0xBA, 0xFE, 0xCA);
}

Scoreboard::~Scoreboard()
{
}

void Scoreboard::Paint() 
{
	App->renderer->Blit(background, x, y, &rect);

	Uint32 now = SDL_GetTicks() - start_time;
	float time = now / 1000.0f;

	//Print time
	App->fonts->print(time, true, 69, 339, GRAY);

	//Red lap
	App->fonts->print(0, false, 69, 356, RED);
	//Blue lap
	App->fonts->print(0, false, 91, 356, BLUE);
	//Orange lap
	App->fonts->print(0, false, 112, 356, ORANGE);
	//Gray lap
	App->fonts->print(0, false, 135, 356, GRAY);

	//Red nitros
	App->fonts->print(0, true, 60, 374, RED);
	//Blue nitros
	App->fonts->print(0, true, 82, 374, BLUE);
	//Orange nitros
	App->fonts->print(0, true, 104, 374, ORANGE);
	//Gray nitros
	App->fonts->print(0, true, 127, 374, GRAY);

}

void Scoreboard::CleanUp()
{
}
