#include "flappy.h"

static Unit* bird;
static Unit** pipes;
static int n_pipes = 0;

Unit* GetBird()
{
	if(!bird)
	{
		Vector2 pos = {0, 720/2};
		Vector2 vel = {0, 0};
		Vector2 acc = {0, 0};
		int mass = 1;

		bird = Unit_SpawnUnit(PERSON, pos, vel, acc, mass);
	}
	return bird;
}

Unit** GetPipes()
{
	if(!pipes)
	{
		pipes = malloc(sizeof(Unit*) * 3);
	}
	return pipes;
}

int GetPipesNum()
{
	return n_pipes;
}

bool GetPipesCollision()
{

}

void UpdateFlappyScreen()
{
	Unit* _bird = GetBird();
	if(Flappy_GetJumpButton())
	{
		Vector2 jumpForce = {0, -20000};
		Unit_ApplyForce(_bird, jumpForce);
	}

	Vector2 gravity = {0, 98};
	Unit_ApplyForce(bird, gravity);
	Unit_ApplyForce(bird, Vector2Scale(Unit_GetUnitVel(_bird), -.1));

	GetPipesCollision();
}
