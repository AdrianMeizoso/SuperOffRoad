#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayerSelect.h"
#include "ModuleFonts.h"
#include "SDL\include\SDL.h"



ModulePlayerSelect::ModulePlayerSelect(bool active) : Module(active)
{
	playerRedRect.w = 208;
	playerRedRect.h = 288;
	playerRedRect.x = 16;
	playerRedRect.y = 1328;

	playerBlueRect.w = 208;
	playerBlueRect.h = 288;
	playerBlueRect.x = 240;
	playerBlueRect.y = 1328;

	spreedShopRect.w = 640;
	spreedShopRect.h = 96;
	spreedShopRect.x = 16;
	spreedShopRect.y = 1216;
}


ModulePlayerSelect::~ModulePlayerSelect()
{

}

bool ModulePlayerSelect::Start()
{
	LOG("Loading player select scene");

	background = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0xBA, 0xFE, 0xCA);

	//App->audio->PlayMusic("Resources/Music/title.ogg", 1.0f);

	if (fx == 0)
		fx = App->audio->LoadFx("rtype/starting.wav");

	start_time = SDL_GetTicks();

	return true;
}

update_status ModulePlayerSelect::Update()
{
	char buffer[5];

	Uint32 now = SDL_GetTicks() - start_time;
	int time = 6 - (now / 1000.0f);
	

	App->renderer->Blit(background, 0, 20, &spreedShopRect);
	App->renderer->Blit(background, 50, 140, &playerRedRect);
	App->renderer->Blit(background, 50 + playerRedRect.w + 100, 140, &playerBlueRect);

	if (time >= 0)
	{
		App->fonts->print("PRESS", 115, 235);
		App->fonts->print("START", 115, 267);

		App->fonts->print(itoa(time, buffer, 10), 145, 315);

		App->fonts->print("PRESS", 115 + playerRedRect.w + 100, 235);
		App->fonts->print("START", 115 + playerRedRect.w + 100, 267);

		App->fonts->print(itoa(time, buffer, 10), 145 + playerRedRect.w + 100, 315);
	}
	else {
		if (firstTime) {
			start_timeTemp = SDL_GetTicks();
			total_time = (Uint32)(3.0f * 1000.0f);
			firstTime = false;
		}

		Uint32 nowTemp = SDL_GetTicks() - start_timeTemp;

		if (nowTemp >= total_time && App->fade->isFading() == false)
		{
			App->fade->FadeToBlack((Module*)App->scene_intro, this, 0.05f);
		}

		App->fonts->print("NO", 215, 235);
		App->fonts->print("PLAYER", 254, 235);
		App->fonts->print("SELECTED", 359, 235);

	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN && App->fade->isFading() == false)
	{
		App->fade->FadeToBlack((Module*)App->scene_levelOne, this, 0.05f);
		App->audio->PlayFx(fx);
	}

	return UPDATE_CONTINUE;
}

bool ModulePlayerSelect::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);

	return true;
}
