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
	rect.w = 640;
	rect.x = 608;
	rect.y = 800;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading space intro");
	
	background = App->textures->Load("Resources/Images/Level/General_Sprites.png");

	//App->audio->PlayMusic("Resources/Music/title.ogg", 1.0f);

	if(fx == 0)
		fx = App->audio->LoadFx("rtype/starting.wav");

	App->renderer->camera.x = App->renderer->camera.y = 0;
	
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
	App->renderer->Blit(background, 0, SCREEN_HEIGHT / 2 - rect.h / 2, &rect);

	if(App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN && App->fade->isFading() == false)
	{
		App->fade->FadeToBlack((Module*)App->scene_levelOne, this);
		App->audio->PlayFx(fx);
	}

	return UPDATE_CONTINUE;
}