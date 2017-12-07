#pragma once
#include "ModuleCollision.h"

class Entity : public Collider::CListener
{
public:

	virtual ~Entity(){}

	virtual void Paint() = 0;
	virtual void CleanUp() = 0;
	virtual void OnCollide() override = 0;
};

