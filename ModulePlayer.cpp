#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleParticles.h"
#include "ModuleRender.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModulePlayer.h"

float radiansFromDegrees(float deg)
{
	return deg*(M_PI / 180.0f);
}

float degreesFromRadians(float rad)
{
	return rad / (M_PI / 180.0f);
}

ModulePlayer::ModulePlayer(bool active) : Module(active)
{
	// input: x, y, w, h
	
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
	rotationCarSprites.push_back({ 760, 24, 46, 29 });
	rotationCarSprites.push_back({ 712, 24, 46, 29 });
	rotationCarSprites.push_back({ 664, 23, 46, 29 });
	rotationCarSprites.push_back({ 615, 22, 46, 29 });
	rotationCarSprites.push_back({ 564, 21, 46, 29 });
	rotationCarSprites.push_back({ 516, 21, 46, 29 });
	rotationCarSprites.push_back({ 481, 21, 46, 29 });
	rotationCarSprites.push_back({ 435, 21, 46, 29 });

	currentRect = rotationCarSprites[0];
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0xBA, 0xFE, 0xCA);

	speed = 0;
	angle = 0;
	maxSpeed = 2.5;
	acc = 0.03, dec = 0.05;
	turnSpeed = 3.2;

	position.x = 150;
	position.y = 120;

	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_REPEAT && speed < maxSpeed)
	{
 		speed += acc;
	}

	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_IDLE)
	{
		if (speed - dec > 0) speed -= dec;
		else speed = 0;
	}

	if(App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
	{
		angle -= turnSpeed;
	}

	if(App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
	{
		angle += turnSpeed;
	}

	float mx = sinf(radiansFromDegrees(angle))*speed;
	float my = -cosf(radiansFromDegrees(angle))*speed;

	position.x += mx;
	position.y += my;
	
	/*
	if (mx != 0)LOG("Mx: %f", mx);
	LOG("positionX: %d", position.x);
	if (my != 0)LOG("My: %f", my);
	LOG("positionY: %d", position.y);
	*/

	LOG("angle: %f", angle);
	int calcRect = 0;

	if (angle < 0)
	{
		calcRect = trunc(((((int)angle * -1) % 360) * 32) / 360);
	}
	else
	{
		calcRect = trunc((((int)angle % 360) * 32) / 360);
	}
	
	currentRect = rotationCarSprites[calcRect];

	// Draw everything --------------------------------------
	App->renderer->Blit(graphics, position.x, position.y, &currentRect);

	return UPDATE_CONTINUE;
}

// TODO 13: Make so is the laser collides, it is removed and create an explosion particle at its position

// TODO 14: Make so if the player collides, it is removed and create few explosions at its positions
// then fade away back to the first screen (use the "destroyed" bool already created 
// You will need to create, update and destroy the collider with the player
