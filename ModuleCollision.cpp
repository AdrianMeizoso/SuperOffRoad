#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "Entity.h"

using namespace std;

ModuleCollision::ModuleCollision()
{
}

// Destructor
ModuleCollision::~ModuleCollision()
{}

update_status ModuleCollision::PreUpdate()
{
	// Remove all colliders scheduled for deletion
	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end();)
	{
		if ((*it)->to_delete == true)
		{
			RELEASE(*it);
			it = colliders.erase(it);
		}
		else
			++it;
	}


	return UPDATE_CONTINUE;
}

update_status ModuleCollision::Update()
{
	// TODO 8: Check collisions between all colliders. 
	// After making it work, review that you are doing the minumum checks possible

	list<Collider*>::iterator iti = colliders.begin();
	for (int i = 0; i < (int)(colliders.size() - 1); ++i)
	{
		list<Collider*>::iterator itj = iti;
		for (int j = (i + 1); j < colliders.size(); ++j)
		{
			++itj;
			if (collisionMatrix[(*iti)->typeCollider][(*itj)->typeCollider])
			{
				if ((*iti)->CheckCollision((*itj)->rect))
				{
					if ((*iti)->listener != nullptr)((*iti)->listener)->OnCollide(*itj);
					if ((*itj)->listener != nullptr)((*itj)->listener)->OnCollide(*iti);
				}
			}
		}
		++iti;
	}

	if(App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
		debug = !debug;

	if(debug == true)
		DebugDraw();

	return UPDATE_CONTINUE;
}

void ModuleCollision::DebugDraw()
{
	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
		App->renderer->DrawQuad((*it)->rect, 255, 0, 0, 80);
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end(); ++it)
		RELEASE(*it);

	colliders.clear();

	return true;
}

Collider* ModuleCollision::AddCollider(const SDL_Rect& rect, TypeCollider typecollider, Collider::CListener* listener, Entity* entity)
{
	Collider* ret = new Collider(rect, typecollider);
	ret->listener = listener;
	ret->entity = entity;

	colliders.push_back(ret);

	return ret;
}

// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	// TODO 7: Create by hand (avoid consulting the internet) a simple collision test
	// Return true if rectangle argument "r" if intersecting with "this->rect"

	if (((r.y - r.h) > rect.y)) return false;
	if ((r.y < (rect.y - rect.h))) return false;
	if ((r.x >(rect.x + rect.w))) return false;
	if (((r.x + r.w) < rect.x)) return false;
	return true;
}
