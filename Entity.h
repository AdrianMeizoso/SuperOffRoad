#pragma once
#include "ModuleCollision.h"

class Entity : public Collider::CListener
{
public:

	Entity(){};
	Entity(int x, int y) : x(x), y(y) {};
	virtual ~Entity(){}

	virtual void Paint() {};
	virtual void CleanUp() {};
	virtual void OnCollide(Collider* extType, CollisionState colState) override {};

public:

	int x = 0;
	int y = 0;
};

