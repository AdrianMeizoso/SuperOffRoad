#include <math.h>
#include "ModuleParticles.h"
#include "Application.h"
#include "ModuleAudio.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0xBA, 0xFE, 0xCA);


	// TODO 2: Create a prototype for the laser particle
	// audio: rtype/laser.wav
	// coords: {232, 103, 16, 12}; {249, 103, 16, 12};

	water = new Particle();
	water->typeParticle = WATER;
	water->anim.frames.push_back({ 815, 760, 28, 23 });
	water->anim.frames.push_back({ 854, 760, 32, 24 });
	water->anim.frames.push_back({ 912, 760, 32, 24 });
	water->anim.speed = 0.2f;
	water->anim.loop = false;

	dust = new Particle();
	dust->typeParticle = DUST;
	dust->anim.frames.push_back({ 14, 751, 32, 32 });
	dust->anim.frames.push_back({ 64, 752, 32, 32 });
	dust->anim.frames.push_back({ 112, 752, 32, 32 });
	dust->anim.frames.push_back({ 160, 752, 32, 32 });
	dust->anim.frames.push_back({ 208, 752, 32, 32 });
	dust->anim.frames.push_back({ 253, 752, 32, 32 });
	dust->anim.frames.push_back({ 300, 752, 32, 32 });
	dust->anim.frames.push_back({ 346, 752, 32, 32 });
	dust->anim.speed = 0.3f;
	dust->anim.loop = false;

	// TODO 12: Create a new "Explosion" particle 
	// audio: rtype/explosion.wav
	// coords: {274, 296, 33, 30}; {313, 296, 33, 30}; {346, 296, 33, 30}; {382, 296, 33, 30}; {419, 296, 33, 30}; {457, 296, 33, 30};

	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (list<Particle*>::iterator it = active.begin(); it != active.end(); ++it)
		RELEASE(*it);

	active.clear();

	return true;
}

// PreUpdate to clear up all dirty particles
update_status ModuleParticles::PreUpdate()
{
	for (list<Particle*>::iterator it = active.begin(); it != active.end();)
	{
		if ((*it)->to_delete == true)
		{
			RELEASE(*it);
			it = active.erase(it);
		}
		else
			++it;
	}

	return UPDATE_CONTINUE;
}

// Update all particle logic and draw them
update_status ModuleParticles::Update()
{
	for (list<Particle*>::iterator it = active.begin(); it != active.end(); ++it)
	{
		Particle* p = *it;

		p->Update();
		App->renderer->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));

		// Handle particle fx here ?
	}

	return UPDATE_CONTINUE;
}


void ModuleParticles::AddWaterParticle(const Particle& p, int x, int y)
{
	bool containWater = false;
	for (list<Particle*>::iterator it = active.begin(); it != active.end(); ++it) {
		if ((*it)->typeParticle == WATER)
		{
			containWater = true;
		}
	}

	if (!containWater) {
		// TODO 4: Fill in a method to create an instance of a prototype particle
  		Particle* newParticle = new Particle(p);
		//SDL_Rect particlePosition = {x, y, 25, 25};
		newParticle->position = { x,y };
		//newParticle->collider = App->collision->AddCollider({ x, y, 20, 12 }, PARTICLE);
		//newParticle->collider->listener = newParticle;
		active.push_back(newParticle);
		//App->audio->PlayFx(fxparticle);
	}
}

void ModuleParticles::AddDustParticle(const Particle & particle, int x, int y)
{
	Particle* newParticle = new Particle(particle);
	//SDL_Rect particlePosition = {x, y, 25, 25};
	newParticle->position = { x,y };
	//newParticle->collider = App->collision->AddCollider({ x, y, 20, 12 }, PARTICLE);
	//newParticle->collider->listener = newParticle;
	active.push_back(newParticle);
	//App->audio->PlayFx(fxparticle);
}


// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{}

// TODO 3: Fill in a copy constructor
Particle::Particle(const Particle& p) : anim(p.anim), position(p.position), speed(p.speed), typeParticle(p.typeParticle)
{}

Particle::~Particle()
{
}

void Particle::Update()
{
	// TODO 5: This is the core of the particle logic
	// draw and audio will be managed by ModuleParticle::Update()
	// Note: Set to_delete to true is you want it deleted

	if (this->anim.Finished())
	{
		this->to_delete = true;
	}

}

