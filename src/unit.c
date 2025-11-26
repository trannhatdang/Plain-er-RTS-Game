#include "unit.h"

struct Unit{
	enum UnitType type;
	Vector2 position;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 forceAccum;
	int mass;
};

static int numUnits = 0;
static Unit** units = NULL;

bool Unit_CheckUnit()
{
	if(!units)
	{
		printf("You haven't initialized units!\n");
		return false;
	}
	return true;
}

Unit* Unit_SpawnUnit(enum UnitType type, Vector2 position, Vector2 velocity, Vector2 acceleration, int mass)
{
	Unit* newUnit = (Unit*)malloc(sizeof(Unit));

	if(!newUnit) 
	{
		return NULL;
	}

	if(!Unit_CheckUnit()) return NULL;

	newUnit->type = type;
	newUnit->position = position;
	newUnit->velocity = velocity;
	newUnit->acceleration = acceleration;
	newUnit->mass = mass;
	newUnit->forceAccum = Vector2Zero();
	
	units[numUnits] = newUnit;
	numUnits++; //not thread safe? lmao
		    //only might need to care if multi-threaded

	return units[numUnits-1];
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
	unit->forceAccum = Vector2Add(unit->forceAccum, force);
}

void InitializeUnits()
{
	units = (Unit**)malloc(sizeof(Unit*) * 100);
}

void FreeUnits()
{
	for(int i = 0; i < numUnits; ++i)
	{
		free(units[i]);
	}
}

void UpdateUnits()
{
	for(int i = 0; i < numUnits; ++i)
	{
		double InverseMass = 1.0/units[i]->mass;
		units[i]->acceleration = Vector2Scale(units[i]->forceAccum, InverseMass);
		units[i]->velocity = Vector2Add(units[i]->velocity, Vector2Scale(units[i]->acceleration, (double)0.02));
		units[i]->position = Vector2Add(units[i]->position, Vector2Scale(units[i]->velocity, (double)0.02));
		units[i]->forceAccum = Vector2Zero();
	}
}
