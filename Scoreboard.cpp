#include "Globals.h"
#include "Scoreboard.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Npc.h"
#include "Player.h"
#include "ModuleFonts.h"

#include "ModuleLevelOne.h"


#include "SDL\include\SDL.h"


Scoreboard::Scoreboard(int x, int y) : Entity(x, y)
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
	App->fonts->print(time, true, 69, 339, TEXTGRAY);

	int lap = App->scene_levelOne->npcAzul->lap;

	//Red lap
	App->fonts->print(App->scene_levelOne->player->lap, false, 69, 356, TEXTRED);
	//Blue lap
	App->fonts->print(App->scene_levelOne->npcAzul->lap, false, 91, 356, TEXTBLUE);
	//Orange lap
	App->fonts->print(App->scene_levelOne->npcYellow->lap, false, 112, 356, TEXTORANGE);
	//Gray lap
	App->fonts->print(App->scene_levelOne->npcGray->lap, false, 135, 356, TEXTGRAY);

	//Red nitros
	App->fonts->print(App->scene_levelOne->player->nitros, true, 60, 374, TEXTRED);
	//Blue nitros
	App->fonts->print(App->scene_levelOne->npcAzul->nitros, true, 82, 374, TEXTBLUE);
	//Orange nitros
	App->fonts->print(App->scene_levelOne->npcYellow->nitros, true, 104, 374, TEXTORANGE);
	//Gray nitros
	App->fonts->print(App->scene_levelOne->npcGray->nitros, true, 127, 374, TEXTGRAY);

}

void Scoreboard::CleanUp()
{
}
