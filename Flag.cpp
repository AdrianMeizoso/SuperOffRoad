#include "Globals.h"
#include "Application.h"
#include "Flag.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

Flag::Flag(int x, int y) : x(x), y(y)
{
	idle.frames.push_back({ 394, 6448, 14, 32 }); //Idle
	idle.speed = 0.08f;

	large.frames.push_back({ 430, 6448, 18, 32 }); //Large movement
	large.frames.push_back({ 464, 6450, 22, 30 });
	large.frames.push_back({ 496, 6452, 26, 28 });
	large.frames.push_back({ 528, 6450, 30, 30 });
	large.frames.push_back({ 560, 6448, 30, 32 });
	large.frames.push_back({ 592, 6448, 26, 32 });

	large.frames.push_back({ 710, 6450, 22, 30 });
	large.frames.push_back({ 737, 6452, 26, 28 });
	large.frames.push_back({ 763, 6450, 30, 30 });
	large.frames.push_back({ 795, 6448, 30, 32 });
	large.frames.push_back({ 832, 6448, 26, 32 });
	large.speed = 0.1f;
	large.loop = true;

	small.frames.push_back({ 624, 6448, 10, 32 }); //Small Movement
	small.frames.push_back({ 656, 6448, 14, 32 });
	small.speed = 0.1f;

	background = App->textures->LoadWithColorKey("Resources/Images/Level/Levels2.png", 0xBA, 0xFE, 0xCA);

	App->collision->AddCollider({x,y,10,20}, FLAG, this);
}


Flag::~Flag()
{
}

void Flag::Paint()
{
	if (active)
	{
		int xRelative = x - (large.GetCurrentFrame().w / 2);
		int yRelative = y - large.GetCurrentFrame().h;

		App->renderer->Blit(background, xRelative, yRelative, &(large.GetCurrentFrame()));
	}
	else
	{
		int xRelative = x - (idle.GetCurrentFrame().w / 2);
		int yRelative = y - idle.GetCurrentFrame().h;

		App->renderer->Blit(background, xRelative, yRelative, &(idle.GetCurrentFrame()));
	}
}

void Flag::CleanUp()
{
}

void Flag::OnCollide(TypeCollider extType)
{
	active = true;
}
