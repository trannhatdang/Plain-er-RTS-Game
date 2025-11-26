#include "main.h"

int main()
{
	Vector2 res = GetResolution();
	InitWindow(res.x, res.y, "game");

	SetTargetFPS(60);
	InitializeInputModule();
	InitializeUnits();

	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawScreen();
		UpdateUnits();

		EndDrawing();
	}

	FreeInputModule();
	FreeUnits();
	CloseWindow();
}
