#pragma once
#include "Module.h"
#include <vector>

class Npc;
class Player;

class ModuleCircuits : public Module
{

public:
	ModuleCircuits(bool active);
	~ModuleCircuits();

	bool Start() override;
	update_status Update() override;
	bool CleanUp() override;

	void nextCircuit(Module* moduleOff);

public:
	std::vector<Module*> circuits;
	std::vector<Player*> players;
	std::vector<Npc*> npcs;

	int index = 0;

	int numPlayers = 0;
};

