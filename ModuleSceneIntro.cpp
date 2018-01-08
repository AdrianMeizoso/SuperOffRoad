#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "SDL\include\SDL.h"

ModuleSceneIntro::ModuleSceneIntro(bool active) : Module(active)
{
	rect.h = 400;
	rect.w = 608;
	rect.x = 0;
	rect.y = 800;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading space intro");
	
	background = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0xBA, 0xFE, 0xCA);

	App->audio->PlayMusic("Resources/Music/menu.wav", 1.0f);

	App->renderer->camera.x = App->renderer->camera.y = 0;

	start_time = SDL_GetTicks();
	total_time = (Uint32)(3.0f * 1000.0f);
	
	return true;
}

// UnLoad assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	
	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	Uint32 now = SDL_GetTicks() - start_time;

	App->renderer->Blit(background, SCREEN_WIDTH / 2 - rect.w / 2, SCREEN_HEIGHT / 2 - rect.h / 2, &rect);

	if (now >= total_time && App->fade->isFading() == false)
	{
			App->fade->FadeToBlack((Module*)App->scene_title, this, 0.05f);
	}

	return UPDATE_CONTINUE;
}