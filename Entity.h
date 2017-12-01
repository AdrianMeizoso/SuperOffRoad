#pragma once

class Entity
{
public:

	virtual ~Entity(){}

	virtual void Paint() = 0;
	virtual void CleanUp() = 0;
};

