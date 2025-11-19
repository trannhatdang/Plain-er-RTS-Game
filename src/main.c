#include "main.h"

int main()
{
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "game");

	SetTargetFPS(60);
	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("MULTI GAME HIHI", 180, 0, 100, BLACK);

		Rectangle rect;
		rect.x=180; rect.y=200; rect.width=600; rect.height=100;

		Vector2 mousepos = GetMousePosition();
		if(mousepos.x > rect.x && mousepos.x < (rect.x + rect.width) && mousepos.y > (rect.y) && mousepos.y < (rect.y + rect.height))
		{
			Rectangle inside_rect = rect;
			inside_rect.x += 10;
			inside_rect.y += 10;
			inside_rect.width -= 20;
			inside_rect.height -= 20;
			DrawRectangleRec(inside_rect, LIGHTGRAY);
		}
		DrawRectangleLinesEx(rect, (float)10, BLACK);
		DrawText("PLAY FLAPPY_DENG", 200, 230, 50, BLACK);

		EndDrawing();
	}
	lmao();
	Transition();
	CloseWindow();
}
