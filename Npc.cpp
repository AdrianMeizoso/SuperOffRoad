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
#include "ModuleLevelOne.h"
#include "Player.h"

float radiansFromDegrees(float deg)
{
	return deg * (M_PI / 180.0f);
}

float degreesFromRadians(float rad)
{
	return rad / (M_PI / 180.0f);
}

fPoint Npc::PathFollowing(){
	fPoint target;

	if (path != nullptr) {
		if (App->input->GetKey(SDL_SCANCODE_F1) == KEY_DOWN)
			debug = !debug;

		if (debug == true)
			DebugDraw();

		target = path->nodes[currentNode];

		if (position.DistanceTo(target) <= radius) {
			if (currentNode == 0)
			{
				++lap;
				App->scene_levelOne->DidLap();
			}

			currentNode += 1;	

			if (currentNode >= path->nodes.size()) {
				currentNode = 0;
			}
		}
	}

	return target;
}

void Npc::DebugDraw()
{
	
	for (vector<fPoint>::iterator it = path->nodes.begin(); it != path->nodes.end(); ++it)
		App->renderer->DrawQuad({(int)(*it).x, (int)(*it).y, 10, 10}, 0, 0, 255, 80);
		
}

Npc::Npc(int x, int y, TypeNpc type, int radius) : Entity(x, y) , type(type), radius(radius)
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

	switch (type)
	{
		case GRAY:
			graphics = App->textures->LoadWithColorKey("Resources/Images/Level/sheet_coche_gris.png", 0x96, 0xFE, 0xC9);
			break;
		case BLUE:
			graphics = App->textures->LoadWithColorKey("Resources/Images/Level/sheet_coche_azul.png", 0x96, 0xFE, 0xC9);
			break;
		case YELLOW:
			graphics = App->textures->LoadWithColorKey("Resources/Images/Level/sheet_coche_amarillo.png", 0x96, 0xFE, 0xC9);
			break;
		case RED:
			graphics = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0x96, 0xFE, 0xC9);
			break;
		default:
			break;
	}
	

	speed = 0.f;
	angle = 0.f;
	maxSpeed = 2.5f;
	acc = 0.03f, dec = 0.05f;
	turnSpeed = 3.f;

	position.x = x;
	position.y = y;


	path = new Path();
	path->addNode({ 346,378 });
	path->addNode({ 238,374 });
	path->addNode({ 307,188 });
	path->addNode({ 497,182 });
	path->addNode({ 497,115 });
	path->addNode({ 158,109 });
	path->addNode({ 107,255 });
	path->addNode({ 512,274 });
	path->addNode({ 471,377 });


	collider = App->collision->AddCollider({ (int)position.x - 13, (int)position.y - 10, 28, 14 }, NPC, this, this);

	float ptemp = 0.f;

	while (ptemp < 360.f) {
		anglesRot.push_back(ptemp);
		ptemp += (11.25f);
	}
}



Npc::~Npc()
{
	LOG("Unloading npc");

	App->textures->Unload(graphics);
	delete collider;
	delete path;

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
	if (!App->fade->isFading())
	{

		if (App->scene_levelOne->getTextureInPosition(position.x, position.y) == 5)
		{
			App->particles->AddWaterParticle(*App->particles->water, position.x - 15, position.y - 10);
		}

		fPoint target = PathFollowing();
		fPoint initPoint = position;
		initPoint.x -= 1;

		fPoint targetVector = target - position;
		fPoint initVector = initPoint - position;

		float angleTarget = degreesFromRadians(acos((initVector.dotProd(targetVector))
			/ (initVector.lenght()*targetVector.lenght())));



		if (target.y > position.y)
		{
			angleTarget = 360 - angleTarget;
		}



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
		else if (speed > maxSpeed) {
			speed -= dec;
			if (speed < maxSpeed)
			{
				speed = maxSpeed;
			}
		}



		angleCalc = angle;


		//Calculation of deviation of perspective
		if (angleCalc > 180)
		{
			angleCalc += sinf(radiansFromDegrees(angle)) * 26.58f;
		}
		else
		{
			angleCalc -= (sinf(radiansFromDegrees(angle)) * 26.58f);
		}


		GetAngleSprite(angleCalc);


		float mx = -cosf(radiansFromDegrees(angle))*speed;
		float my = -sinf(radiansFromDegrees(angle))*speed;

		position.x += mx;
		position.y += my;

		//LOG("position.x: %f, position.y: %f", position.x, position.y);

	}
	
	currentRect = rotationCarSprites[curentSpritePos];

	collider->SetPos((int)position.x - 13, (int)position.y - 6);

	// Draw everything --------------------------------------
	App->renderer->Blit(graphics, position.x + 2.f - currentRect.w / 2, position.y + 2.f - currentRect.h / 2, &rotationShadowSprites[curentSpritePos]);
	App->renderer->Blit(graphics, position.x - currentRect.w / 2, position.y - currentRect.h / 2, &currentRect);

}

void Npc::CleanUp()
{
	App->textures->Unload(graphics);
}

void Npc::OnCollide(Collider* extType, CollisionState colState)
{
	if (colState == COLL_FIRST)
	{
		if (extType->typeCollider == PLAYER)
		{
			//speed *= -1;
			Player* p = (Player*)extType->entity;
	
			if ((angleCalc - p->angle > 155 && angleCalc - p->angle < 205) ||
				 (p->angle - angleCalc > 155 && p->angle - angleCalc < 205)) {
					speed *= -1;
			}
			else if (angleCalc - p->angle > 335 || (angleCalc - p->angle < 25 && angleCalc - p->angle >= 0)  ||
				p->angle - angleCalc > 335 || (p->angle - angleCalc < 25 && p->angle - angleCalc >= 0)) 
			{
				if (p->speed > speed)
				{
					speed = p->speed;
				}
			}
			else {
				if (speed == 0)
				{

				}
			}
		}
	}
	else {
		if (extType->typeCollider == PLAYER)
		{
			if (speed != 0)
			{
				int angleForcol = angleCalc + 180;
				angleForcol = angleForcol % 360;

				float mx = -cosf(radiansFromDegrees(angleForcol));
				float my = -sinf(radiansFromDegrees(angleForcol));

				position.x += mx;
				position.y += my;

			}
			
			Player* p = (Player*)extType->entity;
			if (angleCalc - p->angle > 335 || (angleCalc - p->angle < 25 && angleCalc - p->angle >= 0) ||
				p->angle - angleCalc > 335 || (p->angle - angleCalc < 25 && p->angle - angleCalc >= 0))
			{
				if (p->speed > speed)
				{
					speed = p->speed;
				}
			}
		}
	}
}