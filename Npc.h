#pragma once

#include "Entity.h"
#include "Path.h"
#include "Animation.h"

struct SDL_Texture;

class path;

enum TypeNpc { GRAY, BLUE, YELLOW };

class Npc : public Entity
{
public:
	Npc(int x, int y, TypeNpc type);
	~Npc();

	void Paint() override;
	void CleanUp() override;
	void OnCollide(TypeCollider extType) override;

private:
	float GetAngleSprite(float angle);
	fPoint PathFollowing();

public:
	SDL_Texture* graphics = nullptr;
	vector<SDL_Rect> rotationCarSprites;
	vector<SDL_Rect> rotationShadowSprites;
	vector<float> anglesRot;
	SDL_Rect currentRect;
	fPoint position;

	Collider* collider = nullptr;

	Path* path = nullptr;
	int currentNode = 0;

	TypeNpc type;

	int x = 0;
	int y = 0;

	float speed = 0.f;
	float angle = 0.f;
	float maxSpeed = 12.0f;
	float acc = 0.2f;
	float dec = 0.3f;
	float turnSpeed = 0.08f;
	int height = 0;

	float angleTarget = 0;

	int curentSpritePos = 0;
};

