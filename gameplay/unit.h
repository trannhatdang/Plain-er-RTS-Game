#include "raylib.h"
#include <cstddef>


enum UnitType
{
	PERSON,
	BUILDING
};

typedef struct
{
	enum UnitType type;
	Vector2 position;
	Vector2 velocity;
	Image sprite;
	float speed;
}
Unit;

static int numUnits = 0;
static Unit** units = NULL;

Unit* SpawnUnit(enum UnitType type);
void FreeUnits();
Unit* FindCloseUnit(Vector2 pos);
void UpdateUnits();
