#include "Globals.h"
#include "Application.h"
#include "FlagMen.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"



FlagMen::FlagMen(int x, int y) : x(x), y(y)
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
		int xRelative = x - (run.GetCurrentFrame().w / 2);
		int yRelative = y - run.GetCurrentFrame().h;

		App->renderer->Blit(background, xRelative, yRelative, &(run.GetCurrentFrame()));
	}
}
void FlagMen::CleanUp()
{
}

void FlagMen::OnCollide(TypeCollider extType)
{
}
