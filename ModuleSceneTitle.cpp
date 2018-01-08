#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneTitle.h"
#include "SDL\include\SDL.h"



ModuleSceneTitle::ModuleSceneTitle(bool active) : Module(active)
{
	rect.h = 400;
	rect.w = 640;
	rect.x = 608;
	rect.y = 800;
}


ModuleSceneTitle::~ModuleSceneTitle()
{
}


// Load assets
bool ModuleSceneTitle::Start()
{
	LOG("Loading space title");

	background = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0xBA, 0xFE, 0xCA);

	//App->audio->PlayMusic("Resources/Music/title.ogg", 1.0f);

	if (fx == 0)
		fx = App->audio->LoadFx("rtype/starting.wav");

	start_time = SDL_GetTicks();
	total_time = (Uint32)(7.0f * 1000.0f);

	return true;
}

// UnLoad assets
bool ModuleSceneTitle::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleSceneTitle::Update()
{
	Uint32 now = SDL_GetTicks() - start_time;

	App->renderer->Blit(background, 0, SCREEN_HEIGHT / 2 - rect.h / 2, &rect);

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN && App->fade->isFading() == false)
	{
		App->fade->FadeToBlack((Module*)App->scene_levelOne, this, 0.05f);
		App->audio->PlayFx(fx);
	}


	if (now >= total_time)
	{
		/*
		rect.h = 400;
		rect.w = 640;
		rect.x = 608;
		rect.y = 800;

		App->renderer->Blit(background, 0, SCREEN_HEIGHT / 2 - rect.h / 2, &rect);

		if (App->input->GetKey(SDL_SCANCODE_INSERT) == KEY_DOWN && App->fade->isFading() == false)
		{
			App->fade->FadeToBlack((Module*)App->scene_levelOne, this, 1);
			App->audio->PlayFx(fx);
		}
		*/
	}

	return UPDATE_CONTINUE;
}