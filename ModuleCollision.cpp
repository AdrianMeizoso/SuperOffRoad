#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "Entity.h"
#include "SDL/include/SDL.h"

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
					if (collisionStateMatrix[i][j] == COLL_IDLE)
						collisionStateMatrix[i][j] = COLL_FIRST;
					else
						collisionStateMatrix[i][j] = COLL_REPEAT;

					if ((*iti)->listener != nullptr)((*iti)->listener)->OnCollide(*itj, collisionStateMatrix[i][j]);
					if ((*itj)->listener != nullptr)((*itj)->listener)->OnCollide(*iti, collisionStateMatrix[i][j]);
				}
				else
				{
					collisionStateMatrix[i][j] = COLL_IDLE;
				}
			}
		};
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
		App->renderer->DrawQuad((*it)->rect, 0, 255, 0, 80);
}

// Called before quitting
bool ModuleCollision::CleanUp()
{
	LOG("Freeing all colliders");

	for (list<Collider*>::iterator it = colliders.begin(); it != colliders.end();) {
		RELEASE(*it);
		it = colliders.erase(it);
	}

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
	return SDL_HasIntersection(&r, &rect);
}
