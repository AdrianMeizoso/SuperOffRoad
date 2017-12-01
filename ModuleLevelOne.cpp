#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleLevelOne.h"
#include "Scoreboard.h"
#include "Player.h"

ModuleLevelOne::ModuleLevelOne(bool active) : Module(active)
{
	rect.h = 385;
	rect.w = 640;
	rect.x = 16;
	rect.y = 415;

	rectAlter.h = 385;
	rectAlter.w = 640;
	rectAlter.x = 656;
	rectAlter.y = 415;

	rectTitleLevel.h = 18;
	rectTitleLevel.w = 128;
	rectTitleLevel.x = 143;
	rectTitleLevel.y = 5311;
}

ModuleLevelOne::~ModuleLevelOne()
{}

// Load assets
bool ModuleLevelOne::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("Resources/Images/Level/levels.png");
	graphics = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0xBA, 0xFE, 0xCA);

	player = new Player();

	scoreboard = new Scoreboard(45, 310);

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

	player->Paint();

	App->renderer->Blit(background, 32, SCREEN_HEIGHT / 2 - rectAlter.h / 2, &rectAlter);

	App->renderer->Blit(graphics, SCREEN_WIDTH / 2 - rectTitleLevel.w / 2, 16, &rectTitleLevel);

	scoreboard->Paint();

	return UPDATE_CONTINUE;
}