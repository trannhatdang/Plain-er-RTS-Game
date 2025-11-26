#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#ifndef INPUT_H_
#define INPUT_H_

void InitializeInputModule();
void FreeInputModule();

bool Input_CheckExist();
bool Flappy_GetJumpButton();

#endif //INPUT_H_
