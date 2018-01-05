#include "Globals.h"
#include "Application.h"
#include "FlagMen.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

#include "SDL\include\SDL.h"

FlagMen::FlagMen(int x, int y) : Entity(x, y)
{
	run.frames.push_back({ 292, 716, 32, 20 });
	run.frames.push_back({ 340, 714, 32, 22 });
	run.frames.push_back({ 388, 712, 32, 24 });
	run.frames.push_back({ 444, 708, 20, 28 });
	run.frames.push_back({ 480, 712, 20, 24 });
	run.frames.push_back({ 512, 716, 32, 20 });
	run.frames.push_back({ 560, 714, 32, 22 });
	run.frames.push_back({ 608, 712, 32, 24 });
	run.frames.push_back({ 656, 708, 20, 28 });
	run.frames.push_back({ 682, 712, 20, 24 });
	run.speed = 0.1f;
	run.loop = true;

	background = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0xBA, 0xFE, 0xCA);
}


FlagMen::~FlagMen()
{
}

void FlagMen::Paint()
{
	if (active)
	{
		if (firstTime)
		{
			firstTime = false;
			start_time = SDL_GetTicks();
			total_time = (Uint32)(1.0f * 3000.0f);
		}

		Uint32 now = SDL_GetTicks() - start_time;

		if (now < total_time)
		{
			int xRelative = x - (run.GetCurrentFrame().w / 2);
			int yRelative = y - run.GetCurrentFrame().h;

			App->renderer->Blit(background, xRelative, yRelative, &(run.GetCurrentFrame()));
		}
		else {
			active = false;
			firstTime = true;
		}
	}
	else
	{
		int xRelative = x - ((run.frames[0]).w / 2);
		int yRelative = y - (run.frames[0]).h;

		App->renderer->Blit(background, xRelative, yRelative, &(run.frames[0]));
	}
}
void FlagMen::CleanUp()
{
}
