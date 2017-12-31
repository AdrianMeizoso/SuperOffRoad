#include "Globals.h"
#include "Application.h"
#include "Flag.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "Player.h"

#include "SDL\include\SDL.h"



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
	small.frames.push_back({ 876, 6448, 10, 32 });
	small.frames.push_back({ 896, 6448, 14, 32 });
	small.speed = 0.08f;
	large.loop = true;

	background = App->textures->LoadWithColorKey("Resources/Images/Level/Levels2.png", 0xBA, 0xFE, 0xCA);

	App->collision->AddCollider({x - 4 ,y - 12,10,10}, FLAG, this, this);

	state = DISABLE;
}


Flag::~Flag()
{
}

void Flag::Paint()
{
	if (state == LARGE)
	{
		if (firstTime)
		{
			firstTime = false;
			start_time = SDL_GetTicks();
			total_time = (Uint32)(3.0f * 1000.0f);
		}

		Uint32 now = SDL_GetTicks() - start_time;

		if (now < total_time)
		{
			int xRelative = x - (large.GetCurrentFrame().w / 2);
			int yRelative = y - large.GetCurrentFrame().h;

			App->renderer->Blit(background, xRelative, yRelative, &(large.GetCurrentFrame()));
		}
		else {
			state = SMALL;
			firstTime = true;
		}
		

	}
	else if (state == SMALL)
	{
		if (firstTime)
		{
			firstTime = false;
			start_time = SDL_GetTicks();
			total_time = (Uint32)(1.0f * 1000.0f);
		}

		Uint32 now = SDL_GetTicks() - start_time;

		if (now < total_time)
		{
			int xRelative = x - (small.GetCurrentFrame().w / 2);
			int yRelative = y - small.GetCurrentFrame().h;

			App->renderer->Blit(background, xRelative, yRelative, &(small.GetCurrentFrame()));
		}
		else {
			state = DISABLE;
			firstTime = true;
		}
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

void Flag::OnCollide(Collider* extType, CollisionState colState)
{
	if (state == DISABLE)
	{
		state = LARGE;
	}
}
