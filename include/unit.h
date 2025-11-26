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

typedef struct Unit Unit;

bool Unit_CheckUnit();
Unit* Unit_SpawnUnit(enum UnitType type, Vector2 position, Vector2 velocity, Vector2 acceleration, int mass);
Unit* Unit_FindCloseUnit(Vector2 pos);

Vector2 Unit_GetUnitPos(Unit* unit);
Vector2 Unit_GetUnitVel(Unit* unit);
Vector2 Unit_GetUnitAcc(Unit* unit);
void Unit_ApplyForce(Unit* unit, Vector2 force);

void InitializeUnits();
void FreeUnits();
void UpdateUnits();
