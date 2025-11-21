#include "game_config.h"
#include "raylib.h"
#include "stdio.h"

#ifndef SCREEN_H_
#define SCREEN_H_

typedef enum {
	MENU,
	LOADING,
	FLAPPY
} Screen;

void ChangeScreen(Screen screen); //CHanges screen
void Transition();

#endif

