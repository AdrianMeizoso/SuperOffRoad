#include "Globals.h"
#include "Application.h"
#include "Npc.h"
#include "Point.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include <cmath>

fPoint Npc::PathFollowing(){
	fPoint target;

	if (path != nullptr) {
		target = path->nodes[currentNode];

		if (position.DistanceTo(target) <= 50) {

			currentNode += 1;

			LOG("Llegue");

			if (currentNode >= path->nodes.size()) {
				currentNode = 0;
			}
		}
	}

	return target;
}

Npc::Npc(int x, int y, TypeNpc type) : x(x), y(y), type(type)
{
	LOG("Loading npc");

	// input: x, y, w, h

	//Sprites rotation on simple ground

	rotationCarSprites.push_back({ 760, 24, 46, 29 });
	rotationCarSprites.push_back({ 712, 24, 46, 29 });
	rotationCarSprites.push_back({ 664, 23, 46, 29 });
	rotationCarSprites.push_back({ 615, 22, 46, 29 });
	rotationCarSprites.push_back({ 564, 21, 46, 29 });
	rotationCarSprites.push_back({ 516, 21, 46, 29 });
	rotationCarSprites.push_back({ 481, 21, 46, 29 });
	rotationCarSprites.push_back({ 435, 21, 46, 29 });
	rotationCarSprites.push_back({ 388, 21, 46, 29 });
	rotationCarSprites.push_back({ 343, 21, 46, 29 });
	rotationCarSprites.push_back({ 296, 21, 46, 29 });
	rotationCarSprites.push_back({ 249, 21, 46, 29 });
	rotationCarSprites.push_back({ 202, 22, 46, 29 });
	rotationCarSprites.push_back({ 153, 23, 46, 29 });
	rotationCarSprites.push_back({ 105, 23, 46, 29 });
	rotationCarSprites.push_back({ 57, 24, 46, 29 });
	rotationCarSprites.push_back({ 8, 24, 46, 29 });
	rotationCarSprites.push_back({ 1465, 23, 46, 29 });
	rotationCarSprites.push_back({ 1416, 22, 46, 29 });
	rotationCarSprites.push_back({ 1367, 22, 46, 29 });
	rotationCarSprites.push_back({ 1318, 22, 46, 29 });
	rotationCarSprites.push_back({ 1267, 21, 46, 29 });
	rotationCarSprites.push_back({ 1234, 21, 46, 29 });
	rotationCarSprites.push_back({ 1187, 21, 46, 29 });
	rotationCarSprites.push_back({ 1141, 21, 46, 29 });
	rotationCarSprites.push_back({ 1094, 21, 46, 29 });
	rotationCarSprites.push_back({ 1047, 21, 46, 29 });
	rotationCarSprites.push_back({ 1000, 21, 46, 29 });
	rotationCarSprites.push_back({ 953, 22, 46, 29 });
	rotationCarSprites.push_back({ 904, 23, 46, 29 });
	rotationCarSprites.push_back({ 855, 23, 46, 29 });
	rotationCarSprites.push_back({ 808, 23, 46, 29 });


	//Sprites rotation on simple ground

	rotationShadowSprites.push_back({ 760, 648, 46, 29 });
	rotationShadowSprites.push_back({ 712, 648, 46, 29 });
	rotationShadowSprites.push_back({ 664, 647, 46, 29 });
	rotationShadowSprites.push_back({ 615, 646, 46, 29 });
	rotationShadowSprites.push_back({ 564, 645, 46, 29 });
	rotationShadowSprites.push_back({ 516, 645, 46, 29 });
	rotationShadowSprites.push_back({ 481, 645, 46, 29 });
	rotationShadowSprites.push_back({ 435, 645, 46, 29 });
	rotationShadowSprites.push_back({ 388, 645, 46, 29 });
	rotationShadowSprites.push_back({ 343, 645, 46, 29 });
	rotationShadowSprites.push_back({ 296, 645, 46, 29 });
	rotationShadowSprites.push_back({ 249, 645, 46, 29 });
	rotationShadowSprites.push_back({ 202, 646, 46, 29 });
	rotationShadowSprites.push_back({ 153, 647, 46, 29 });
	rotationShadowSprites.push_back({ 105, 647, 46, 29 });
	rotationShadowSprites.push_back({ 57, 648, 46, 29 });
	rotationShadowSprites.push_back({ 8, 648, 46, 29 });
	rotationShadowSprites.push_back({ 1465, 647, 46, 29 });
	rotationShadowSprites.push_back({ 1416, 646, 46, 29 });
	rotationShadowSprites.push_back({ 1367, 646, 46, 29 });
	rotationShadowSprites.push_back({ 1318, 646, 46, 29 });
	rotationShadowSprites.push_back({ 1267, 645, 46, 29 });
	rotationShadowSprites.push_back({ 1234, 645, 46, 29 });
	rotationShadowSprites.push_back({ 1187, 645, 46, 29 });
	rotationShadowSprites.push_back({ 1141, 645, 46, 29 });
	rotationShadowSprites.push_back({ 1094, 645, 46, 29 });
	rotationShadowSprites.push_back({ 1047, 645, 46, 29 });
	rotationShadowSprites.push_back({ 1000, 645, 46, 29 });
	rotationShadowSprites.push_back({ 953, 646, 46, 29 });
	rotationShadowSprites.push_back({ 904, 647, 46, 29 });
	rotationShadowSprites.push_back({ 855, 647, 46, 29 });
	rotationShadowSprites.push_back({ 808, 647, 46, 29 });


	currentRect = rotationCarSprites[0];

	graphics = App->textures->LoadWithColorKey("Resources/Images/Level/sheet_coche_azul.png", 0xBA, 0xFE, 0xCA);

	speed = 0.f;
	angle = 0.f;
	maxSpeed = 2.5f;
	acc = 0.03f, dec = 0.05f;
	turnSpeed = 3.f;

	position.x = x;
	position.y = y;


	path = new Path();
	path->addNode({ 238,374 });
	path->addNode({ 307,188 });
	path->addNode({ 497,182 });
	path->addNode({ 497,115 });
	path->addNode({ 158,109 });
	path->addNode({ 107,255 });
	path->addNode({ 512,274 });
	path->addNode({ 471,377 });


	//collider = App->collision->AddCollider({ (int)position.x, (int)position.y,46,29 }, PLAYER, this);

	float ptemp = 0.f;

	while (ptemp < 360.f) {
		anglesRot.push_back(ptemp);
		ptemp += (11.25f);
	}
}

float radiansFromDegrees2(float deg)
{
	return deg * (M_PI / 180.0f);
}

float degreesFromRadians2(float rad)
{
	return rad / (M_PI / 180.0f);
}

Npc::~Npc()
{
	LOG("Unloading npc");

	App->textures->Unload(graphics);
}

float Npc::GetAngleSprite(float angle)
{
	for (unsigned int i = 0; i < anglesRot.size(); i++)
	{
		if (angle < anglesRot[i])
		{
			if (((anglesRot[i] + anglesRot[i - 1]) / 2) > angle)
			{
				curentSpritePos = i - 1;
				return anglesRot[i - 1];
			}
			else
			{
				curentSpritePos = i;
				return anglesRot[i];
			}
		}
	}
	curentSpritePos = 0;
	return 0;
}

void Npc::Paint()
{
	/*
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT && speed < maxSpeed)
	{
		if (speed < 0)
		{
			speed += acc * 2;
		}
		else {
			speed += acc;
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_IDLE)
	{
		if (speed - dec > 0)
		{
			speed -= dec;
			if (speed < 0)
			{
				speed = 0;
			}
		}
		else if (speed - dec < 0)
		{
			speed += dec;
			if (speed > 0)
			{
				speed = 0;
			}
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		angle -= turnSpeed;
		if (angle < 0)
		{
			angle = 360 - turnSpeed;
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		angle += turnSpeed;
		if (angle > 360)
		{
			angle = turnSpeed;
		}
	}

	if (App->input->GetKey(SDL_SCANCODE_R) == KEY_DOWN)
	{
		//Player();
	}
	*/
	
	fPoint target = PathFollowing();
	fPoint initPoint = position;
	initPoint.x -= 1;

	fPoint targetVector = target - position;
	fPoint initVector = initPoint - position;

	float angleTarget = degreesFromRadians2(acos((initVector.dotProd(targetVector)) 
		/ (initVector.lenght()*targetVector.lenght()))); 

	if (target.y > position.y)
	{
		angleTarget = 360 - angleTarget;
	}

	/**
	fPoint target = PathFollowing();
	float angleTarget = degreesFromRadians2(atan2(-target.x + position.x, target.y - position.y));
	*/
	

	

	
	if (angleTarget != angle)
	{
		if (angleTarget > angle)
		{
			if (angleTarget - angle < 180)
			{
				angle += turnSpeed;
				if (angle > 360)
				{
					angle = turnSpeed;
				}
			}
			else
			{
				angle -= turnSpeed;
				if (angle < 0)
				{
					angle = 360 - turnSpeed;
				}

			}
		}
		else
		{
			if (angle - angleTarget > 180)
			{
				angle += turnSpeed;
				if (angle > 360)
				{
					angle = turnSpeed;
				}
			}
			else
			{
				angle -= turnSpeed;
				if (angle < 0)
				{
					angle = 360 - turnSpeed;
				}

			}

		}
	}
	
	LOG("angleTarget: %f, angle: %f", angleTarget, angle);

	//angle = angleTarget;

	if (speed < maxSpeed)
	{
		if (speed < 0)
		{
			speed += acc * 2;
		}
		else {
			speed += acc;
		}
	}

	/*
	angle += turnSpeed;
	if (angle > 360)
	{
		angle = turnSpeed;
	}
	*/

	float angleCalc = angle;

	
	//Calculation of deviation of perspective
	if (angleCalc > 180)
	{
		angleCalc += sinf(radiansFromDegrees2(angleCalc)) * 26.58f;
	}
	else
	{
		angleCalc -= (sinf(radiansFromDegrees2(angleCalc)) * 26.58f);
	}
	

	GetAngleSprite(angleCalc);

	/*
	
	//Calculation of deviation of perspective
	if (angleCalc > 180)
	{
		angleCalc += sinf(radiansFromDegrees2(angleCalc)) * 26.58f;
	}
	else
	{
		angleCalc -= sinf(radiansFromDegrees2(angleCalc)) * 26.58f;
	}
	*/

	float mx = -cosf(radiansFromDegrees2(angle))*speed;
	float my = -sinf(radiansFromDegrees2(angle))*speed;

	position.x += mx;
	position.y += my;

	//LOG("position.x: %f, position.y: %f", position.x, position.y);

	currentRect = rotationCarSprites[curentSpritePos];

	//collider->SetPos((int)position.x, (int)position.y);

	// Draw everything --------------------------------------
	App->renderer->Blit(graphics, position.x + 2.f - currentRect.w / 2, position.y + 2.f - currentRect.h / 2, &rotationShadowSprites[curentSpritePos]);
	App->renderer->Blit(graphics, position.x - currentRect.w / 2, position.y - currentRect.h / 2, &currentRect);

	if (position.x <= -7)
	{
		speed *= -1;
	}

}

void Npc::CleanUp()
{
}

void Npc::OnCollide(TypeCollider extType)
{
}