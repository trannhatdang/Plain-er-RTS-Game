#include "screen.h"

static Screen curr_screen = MENU;
static Screen next_screen = MENU;
static bool isInTransition = false;

void ChangeScreen(Screen screen, bool transition)
{
	if(transition)
	{
		curr_screen = TRANSITION;
		next_screen = screen;
		return;
	}

	curr_screen = screen;
}

void DrawScreen()
{
	switch(curr_screen)
	{
		case MENU:
			DrawMenu();
			break;
		case FLAPPY:
			DrawFlappy();
			break;
		case TRANSITION:
			DrawTransition();
			break;
		default:
			break;
	}

}

void DrawMenu()
{
	DrawText("MULTI GAME HIHI", 180, 0, 100, BLACK);
	Rectangle rect;
	rect.x=180; rect.y=200; rect.width=600; rect.height=100;

	Vector2 mousepos = GetMousePosition();
	if(mousepos.x > rect.x && mousepos.x < (rect.x + rect.width) && mousepos.y > (rect.y) && mousepos.y < (rect.y + rect.height)){
		Rectangle inside_rect = rect;
		inside_rect.x += 10;
		inside_rect.y += 10;
		inside_rect.width -= 20;
		inside_rect.height -= 20;
		DrawRectangleRec(inside_rect, LIGHTGRAY);
	}

	DrawRectangleLinesEx(rect, (float)10, BLACK);
	DrawText("PLAY FLAPPY_DENG", 200, 230, 50, BLACK);

	if(IsKeyPressed(KEY_F)){
		ChangeScreen(FLAPPY, true);
	}
}


void DrawTransition()
{
	static int alpha = 0;

	alpha += 1;
	Color col = BLACK;
	col.a = alpha;
	DrawRectangle(0, 0, 1280, 720, col);
	if(alpha == 100)
	{
		alpha = 0;
		ChangeScreen(next_screen, false);
	}
}

void DrawFlappy()
{

}
