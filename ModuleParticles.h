#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include<list>
#include "Globals.h"
#include "Module.h"
#include "Animation.h"
#include "Point.h"
#include "ModuleCollision.h"

enum TypeParticle { WATER, DUST };

struct SDL_Texture;

struct Particle
{
	// TODO 1: Fill in the structure with all the properties you need for each particle
	bool to_delete = false;
	iPoint position = { 0, 0 };
	Animation anim;

	float speed = 0.f;
	int timeToDelete = 0;
	TypeParticle typeParticle;

	Particle();
	Particle(const Particle& p);
	~Particle();

	void Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status PreUpdate(); // clear dirty particles
	update_status Update(); // draw
	bool CleanUp();

	void AddWaterParticle(const Particle& particle, int x, int y); 
	void AddDustParticle(const Particle& particle, int x, int y); 

private:

	SDL_Texture* graphics = nullptr;
	std::list<Particle*> active;

public:

	// prototype particles go here ...
	Particle* water;
	Particle* dust;
};

#endif // __MODULEPARTICLES_H__