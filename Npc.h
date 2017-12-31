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
	Npc(int x, int y, TypeNpc type, int radius);
	~Npc();

	void Paint() override;
	void CleanUp() override;
	void OnCollide(Collider* extType, CollisionState colState) override;

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
	float maxSpeed = 0.f;
	float acc = 0.f;
	float dec = 0.f;
	float turnSpeed = 0.f;
	int height = 0;
	int radius = 0;
	float angleCalc = 0.f;

	float angleTarget = 0.f;

	int curentSpritePos = 0;
};

