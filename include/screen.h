#include "game_config.h"
#include "raylib.h"
#include "stdio.h"

#ifndef SCREEN_H_
#define SCREEN_H_

typedef enum {
	MENU,
	LOADING,
	FLAPPY,
	TRANSITION
} Screen;

void ChangeScreen(Screen screen, bool transition); //Changes screen
void DrawScreen();
void DrawMenu();
void DrawFlappy();
void DrawTransition();

#endif

