#include "raylib.h"
#include "raymath.h"
#include "stdio.h"
#include <stddef.h>
#include <stdlib.h>

enum UnitType
{
	PERSON,
	BUILDING
};

typedef struct _unit Unit;

Unit* Unit_SpawnUnit(enum UnitType type, Vector2 position, Vector2 velocity, Vector2 acceleration, int mass);
void Unit_FreeUnits();
Unit* Unit_FindCloseUnit(Vector2 pos);
void Unit_UpdateUnits();

Vector2 Unit_GetUnitPos(Unit* unit);
Vector2 Unit_GetUnitVel(Unit* unit);
Vector2 Unit_GetUnitAcc(Unit* unit);
void Unit_ApplyForce(Unit* unit, Vector2 force);
