#include "main.h"

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

