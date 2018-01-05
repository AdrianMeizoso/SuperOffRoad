#include "Globals.h"
#include "Application.h"
#include "ModuleLevelOne.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleParticles.h"
#include "ModuleInput.h"
#include "Scoreboard.h"
#include "Player.h"
#include "Flag.h"
#include "Npc.h"
#include "FlagMen.h"
#include "ModuleReadFile.h"

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

int ModuleLevelOne::getHeightInPosition()
{
	int index = 0;
	if (player->position.y > 0 && player->position.y < 449 && player->position.x > 0 && player->position.x < 640)
	{
		index = 448 * (int)player->position.x + (int)player->position.y;
	}

	return heightMap[index];
}

int ModuleLevelOne::getTextureInPosition()
{
	int index = 0;
	if (player->position.y > 0 && player->position.y < 449 && player->position.x > 0 && player->position.x < 640)
	{
		index = 448 * (int)player->position.x + (int)player->position.y;
	}

	return textureMap[index];
}

void ModuleLevelOne::DidLap()
{
	flagMen->active = true;
}

// Load assets
bool ModuleLevelOne::Start()
{
	LOG("Loading space scene");

	background = App->textures->Load("Resources/Images/Level/levels.png");
	graphics = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0xBA, 0xFE, 0xCA);

	heightMap = App->readFile->readHeightMap("Resources/Images/Level/LevelOne/HeightMap.txt");
	textureMap = App->readFile->readTextureMap("Resources/Images/Level/LevelOne/textureMap.txt");

	player = new Player();

	npcAzul = new Npc(376, 375, BLUE, 40);
	npcYellow = new Npc(425, 375, YELLOW, 50);
	npcYellow->maxSpeed = 2.8f;

	/*
	npcAzul = new Npc(376, 100, BLUE, 50);
	npcAzul->angle = 180.f;
	*/

	scoreboard = new Scoreboard(26, 333);
	flag = new Flag(204, 298);
	flag2 = new Flag(300, 305);
	flag3 = new Flag(361, 212);
	flagMen = new FlagMen(328, 405);

	flagMen->active = false;

	return true;
}

// UnLoad assets
bool ModuleLevelOne::CleanUp()
{
	LOG("Unloading space scene");

	App->textures->Unload(background);
	npcAzul->CleanUp();

	return true;
}

// Update: draw background
update_status ModuleLevelOne::Update()
{
	if (App->input->GetMouseButtonDown(1) == KEY_DOWN)
	{
		LOG("x = %d,y = %d", App->input->GetMousePosition().x, App->input->GetMousePosition().y);
	}

	// Draw everything --------------------------------------
	App->renderer->Blit(background, 0, SCREEN_HEIGHT / 2 - rect.h / 2, &rect);

	if (getTextureInPosition() == 5)
	{
		App->particles->AddWaterParticle(*App->particles->water, player->position.x - 15, player->position.y - 10);
	}

	npcAzul->Paint();
	npcYellow->Paint();
	player->Paint();

	App->renderer->Blit(background, 32, SCREEN_HEIGHT / 2 - rectAlter.h / 2, &rectAlter);

	flag->Paint();
	flag2->Paint();
	flag3->Paint();

	flagMen->Paint();

	App->renderer->Blit(graphics, SCREEN_WIDTH / 2 - rectTitleLevel.w / 2, 16, &rectTitleLevel);

	scoreboard->Paint();

	return UPDATE_CONTINUE;
}