#include "gameplay/unit.h"

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 600;
	InitWindow(screenWidth, screenHeight, "game");
	

	Image image = LoadImage("flapsheet.png");
	Texture2D texture = LoadTextureFromImage(image);

	SetTargetFPS(60);





	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawTexture(texture, screenWidth/2 - texture.width/2, screenHeight/2 - texture.height/2, WHITE);

		DrawText("hi", 300, 370, 10, GRAY);

		EndDrawing();
	}

	UnloadTexture(texture);


	CloseWindow();
}
