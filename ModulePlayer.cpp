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
	rect.h = 29;
	rect.w = 46;
	rect.x = 8;
	rect.y = 24;


}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	graphics = App->textures->LoadWithColorKey("Resources/Images/Level/General_Sprites.png", 0xBA, 0xFE, 0xCA);

	speed = 0;
	angle = 90;
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

	// Draw everything --------------------------------------
	App->renderer->BlitWithAngle(graphics, position.x, position.y, &rect, 0, angle - 90);

	return UPDATE_CONTINUE;
}

// TODO 13: Make so is the laser collides, it is removed and create an explosion particle at its position

// TODO 14: Make so if the player collides, it is removed and create few explosions at its positions
// then fade away back to the first screen (use the "destroyed" bool already created 
// You will need to create, update and destroy the collider with the player
