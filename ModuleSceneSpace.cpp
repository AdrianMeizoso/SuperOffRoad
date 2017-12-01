#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleSceneSpace.h"

ModuleSceneSpace::ModuleSceneSpace(bool active) : Module(active)
{}

ModuleSceneSpace::~ModuleSceneSpace()
{}

// Load assets
bool ModuleSceneSpace::Start()
{
	LOG("Loading space scene");
	
	background = App->textures->Load("rtype/background.png");

	/*
	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();

	App->audio->PlayMusic("rtype/stage1.ogg", 1.0f);
	*/
	
	// TODO 15: create some colliders for the walls
	// solution wall coords: {0, 224, 3930, 16} {1375, 0, 111, 96} {1375, 145, 111, 96}

	return true;
}

// UnLoad assets
bool ModuleSceneSpace::CleanUp()
{
	LOG("Unloading space scene");

	/*
 	App->textures->Unload(background);
	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();
	*/
	
	return true;
}

// Update: draw background
update_status ModuleSceneSpace::Update()
{
	/*
	// Move camera forward -----------------------------
	int scroll_speed = 1;

	App->player->position.x += 1;
	App->renderer->camera.x -= 3;

	*/
	
	// Draw everything --------------------------------------
	App->renderer->Blit(background, 0, 0, NULL);
	
	return UPDATE_CONTINUE;
}