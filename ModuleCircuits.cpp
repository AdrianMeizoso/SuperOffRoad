#include "Globals.h"
#include "Application.h"
#include "ModuleFadeToBlack.h"
#include "ModuleCircuits.h"


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
			App->fade->FadeToBlack((Module*)App->scene_intro, circuits[index - 1], 0.05f);
			index = 0;
			numPlayers = 0;
			npcs.clear();
			players.clear();
		}
		else
		{
			App->fade->FadeToBlack(circuits[index], moduleOff, 0.05f);
			++index;
		}
		
	}
}
