#include "screen.h"

static Screen curr_screen = MENU;

void ChangeScreen(Screen screen)
{
	curr_screen = screen;
}//CHanges screen

void Transition()
{
	int steps = 100;
	float time = (float)2;
	BeginBlendMode(0);
	Color col = WHITE;
	col.a = 0;
	for(int i = 0; i < steps; ++i)
	{
		DrawRectangle(0,0, GetResolution().x, GetResolution().y, col);
		col.a += 100/steps;
		printf("%d", col.a);
		WaitTime(time/ steps);
	}
	EndBlendMode();
}



