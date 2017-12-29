#pragma once
#include "ModuleCollision.h"

class Entity : public Collider::CListener
{
public:

	virtual ~Entity(){}

	virtual void Paint() {};
	virtual void CleanUp() {};
	virtual void OnCollide(Collider* extType) override {};
};

