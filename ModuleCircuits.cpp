#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCircuits.h"
#include "ModuleCollision.h"


ModuleCircuits::ModuleCircuits(bool active) : Module(active)
{

}


ModuleCircuits::~ModuleCircuits()
{

}

bool ModuleCircuits::Start()
{
	circuits.push_back((Module*)App->scene_levelOne);

	return true;
}

update_status ModuleCircuits::Update()
{

	if ((App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN) && numPlayers == 0 && circuits[0]->IsEnabled()) {
		App->fade->FadeToBlack((Module*)App->scene_title ,circuits[0], 0.05f);
		index = 0;
		numPlayers = 0;
		npcs.clear();
		players.clear();
		App->collision->CleanUp();
	}

	return UPDATE_CONTINUE;
}

bool ModuleCircuits::CleanUp()
{
	for (std::vector<Npc*>::iterator it = npcs.begin(); it != npcs.end(); ++it)
		RELEASE(*it);

	circuits.clear();
	
	return true;
}

void ModuleCircuits::nextCircuit(Module* moduleOff)
{
	unsigned int vsize = circuits.size();
	if (App->fade->isFading() == false)
	{
		if (index >= vsize)
		{
			App->fade->FadeToBlack((Module*)App->scene_intro, moduleOff, 0.05f);
			index = 0;
			numPlayers = 0;
			npcs.clear();
			players.clear();
			App->collision->CleanUp();

		}
		else
		{
			App->fade->FadeToBlack(circuits[index], moduleOff, 0.05f);
			++index;
		}
		
	}
}
