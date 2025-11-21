#include "screen.h"

static Screen curr_screen = MENU;

void ChangeScreen(Screen screen)
{
	curr_screen = screen;
}//Changes screen

void Transition()
{
	int steps = 100;
	float time = (float)2;
	BeginBlendMode(0);
	Color col = BLACK;
	col.a = 100;
	for(int i = 0; i < steps; ++i)
	{
		BeginDrawing();
		DrawRectangle(800, 600, 0, 0, col);
		col.a -= 100/steps;
		printf("%d", col.a);
		WaitTime(time/ steps);
		EndDrawing();
	}
	EndBlendMode();
}



