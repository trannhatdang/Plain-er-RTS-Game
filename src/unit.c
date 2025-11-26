#include "unit.h"

struct _unit{
	enum UnitType type;
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	int mass;
};

static int numUnits = 0;
static Unit** units = NULL;

Unit* Unit_SpawnUnit(enum UnitType type, Vector2 position, Vector2 velocity, Vector2 acceleration, int mass)
{
	Unit* newUnit = (Unit*)malloc(sizeof(Unit));

	if(!newUnit) 
	{
		return NULL;
	}

	if(!units)
	{
		units = (Unit**)malloc(sizeof(Unit*) * 100);
	}

	newUnit->type = type;
	newUnit->position = position;
	newUnit->velocity = velocity;
	newUnit->acceleration = acceleration;
	newUnit->mass = mass;
	
	units[numUnits] = newUnit;
	numUnits++; //not thread safe? lmao
		    //only might need to care if multi-threaded

	return units[numUnits-1];
}

void Unit_FreeUnits()
{
	for(int i = 0; i < numUnits; ++i)
	{
		free(units[i]);
	}
}

Unit* Unit_FindCloseUnit(Vector2 pos)
{
	float dist = (float)2;
	for(int i = 0; i < numUnits; ++i)
	{
		if(Vector2Distance(pos, units[i]->position) < dist)
		{
			return units[i];
		}
	}
	return NULL;
}

void Unit_UpdateUnits()
{
	for(int i = 0; i < numUnits; ++i)
	{
		units[i]->velocity = Vector2Add(units[i]->velocity, Vector2Scale(units[i]->acceleration, GetFrameTime()));
		units[i]->position = Vector2Add(units[i]->position, Vector2Scale(units[i]->velocity, GetFrameTime()));
	}
}

Vector2 Unit_GetUnitPos(Unit* unit)
{
	return unit->position;
}

Vector2 Unit_GetUnitVel(Unit* unit)
{
	return unit->velocity;
}

Vector2 Unit_GetUnitAcc(Unit* unit)
{
	return unit->acceleration;
}

void Unit_ApplyForce(Unit* unit, Vector2 force)
{
	/*
	float newMass = 1 / (unit->mass * (float)1.0);
	Vector2 newAcce = Vector2Scale(force, newMass);
	unit->acceleration = Vector2Add(unit->acceleration, newAcce);
	printf("%f %f\n", unit->acceleration.x, unit->acceleration.y);
	*/
}
