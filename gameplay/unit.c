#include "unit.h"

Unit* SpawnUnit(enum UnitType type)
{
	Unit* newUnit = malloc(sizeof(Unit));

	if(!newUnit) 
	{
		return NULL;
	}
	
	newUnit->type = type;
	newUnit->speed = (float)10;
	units[numUnits] = newUnit;
	numUnits++; //not thread safe? lmao
		    //
		    //

	return units[numUnits-1];
}

void FreeUnits()
{
	for(int i = 0; i < numUnits; ++i)
	{
		free(units[i]);
	}
}

Unit* FindCloseUnit(Vector2 pos)
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

void UpdateUnits()
{
	for(int i = 0; i < numUnits; ++i)
	{
		Vector2 dist = Vector2DotProduct(units[i]->velocity, units[i]->speed);
		units[i]->position = Vector2Add(units[i]->position, dist);
	}
}
