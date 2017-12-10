#ifndef __ModuleCollision_H__
#define __ModuleCollision_H__

#include<list>
#include "Module.h"

// TODO 9: Create a matrix of game specific types of collision for early discard
// Example: lasers should not collide with lasers but should collider with walls
// enemy shots will collide with other enemies ? and against walls ?

enum TypeCollider { PLAYER, FLAG, NPC };

struct Collider
{
	SDL_Rect rect = { 0,0,0,0 };
	bool to_delete = false;
	TypeCollider typeCollider;

	// TODO 10: Add a way to notify other classes that a collision happened

	class CListener
	{
		public:

		virtual void OnCollide(TypeCollider extType)
		{
			LOG("Nothing Collide");
		}
	};

	CListener* listener = nullptr;

	Collider(SDL_Rect rectangle, TypeCollider typeCollider) : // expand this call if you need to
		rect(rectangle), typeCollider(typeCollider)
	{}

	void SetPos(int x, int y)
	{
		rect.x = x;
		rect.y = y;
	}

	bool CheckCollision(const SDL_Rect& r) const;
};

class ModuleCollision : public Module
{
public:

	ModuleCollision();
	~ModuleCollision();

	update_status PreUpdate();
	update_status Update();

	bool CleanUp();

	Collider* AddCollider(const SDL_Rect& rect, TypeCollider typeCollider, Collider::CListener* listener);
	void DebugDraw();

private:

	std::list<Collider*> colliders;
	bool debug = false;

	//PLAYER FLAG
	bool collisionMatrix[3][3] = { { false, true, false },
									{ true, false, true },
									{ true, true, false } };
};

#endif // __ModuleCollision_H__