#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleLevelOne.h"

ModuleLevelOne::ModuleLevelOne(bool active) : Module(active)
{
	rect.h = 385;
	rect.w = 640;
	rect.x = 16;
	rect.y = 816;
}

ModuleLevelOne::~ModuleLevelOne()
{}

// Load assets
bool ModuleLevelOne::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("Resources/Images/Level/levels.png");

	App->player->Enable();

	return true;
}

// UnLoad assets
bool ModuleLevelOne::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);

	return true;
}

// Update: draw background
update_status ModuleLevelOne::Update()
{
	// Draw everything --------------------------------------
	App->renderer->Blit(background, 0, SCREEN_HEIGHT / 2 - rect.h / 2, &rect);

	return UPDATE_CONTINUE;
}