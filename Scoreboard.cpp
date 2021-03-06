#include "Globals.h"
#include "Scoreboard.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "Npc.h"
#include "Player.h"
#include "ModuleFonts.h"

#include "ModuleCircuits.h"


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

	if (App->scene_circuits->numPlayers > 0)
	{
		//Red lap
		App->fonts->print(App->scene_circuits->players[0]->lap, false, 69, 356, TEXTRED);
		//Red nitros
		App->fonts->print(App->scene_circuits->players[0]->nitros, true, 60, 374, TEXTRED);

		if (App->scene_circuits->numPlayers == 1)
		{
			//Blue lap
			App->fonts->print(App->scene_circuits->npcs[0]->lap, false, 91, 356, TEXTBLUE);
			//Blue nitros
			App->fonts->print(App->scene_circuits->npcs[0]->nitros, true, 82, 374, TEXTBLUE);

			//Orange lap
			App->fonts->print(App->scene_circuits->npcs[1]->lap, false, 112, 356, TEXTORANGE);
			//Orange nitros
			App->fonts->print(App->scene_circuits->npcs[1]->nitros, true, 104, 374, TEXTORANGE);

			//Gray lap
			App->fonts->print(App->scene_circuits->npcs[2]->lap, false, 135, 356, TEXTGRAY);
			//Gray nitros
			App->fonts->print(App->scene_circuits->npcs[2]->nitros, true, 127, 374, TEXTGRAY);
		}
		else {
			//Blue lap
			App->fonts->print(App->scene_circuits->players[1]->lap, false, 91, 356, TEXTBLUE);
			//Blue nitros
			App->fonts->print(App->scene_circuits->players[1]->nitros, true, 82, 374, TEXTBLUE);

			//Orange lap
			App->fonts->print(App->scene_circuits->npcs[0]->lap, false, 112, 356, TEXTORANGE);
			//Orange nitros
			App->fonts->print(App->scene_circuits->npcs[0]->nitros, true, 104, 374, TEXTORANGE);

			//Gray lap
			App->fonts->print(App->scene_circuits->npcs[1]->lap, false, 135, 356, TEXTGRAY);
			//Gray nitros
			App->fonts->print(App->scene_circuits->npcs[1]->nitros, true, 127, 374, TEXTGRAY);
		}

		
	}
	else {
		//Red lap
		App->fonts->print(App->scene_circuits->npcs[0]->lap, false, 69, 356, TEXTRED);
		//Red nitros
		App->fonts->print(App->scene_circuits->npcs[0]->nitros, true, 60, 374, TEXTRED);

		//Blue lap
		App->fonts->print(App->scene_circuits->npcs[1]->lap, false, 91, 356, TEXTBLUE);
		//Blue nitros
		App->fonts->print(App->scene_circuits->npcs[1]->nitros, true, 82, 374, TEXTBLUE);

		//Orange lap
		App->fonts->print(App->scene_circuits->npcs[2]->lap, false, 112, 356, TEXTORANGE);
		//Orange nitros
		App->fonts->print(App->scene_circuits->npcs[2]->nitros, true, 104, 374, TEXTORANGE);

		//Gray lap
		App->fonts->print(App->scene_circuits->npcs[3]->lap, false, 135, 356, TEXTGRAY);
		//Gray nitros
		App->fonts->print(App->scene_circuits->npcs[3]->nitros, true, 127, 374, TEXTGRAY);
	}
}

void Scoreboard::CleanUp()
{
}
