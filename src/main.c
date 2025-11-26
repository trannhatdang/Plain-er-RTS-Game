#include "main.h"

int main()
{
	Vector2 res = GetResolution();
	InitWindow(res.x, res.y, "game");

	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawScreen();
		Unit_UpdateUnits();

		EndDrawing();
	}

	Unit_FreeUnits();
	CloseWindow();
}
