#include "game_config.h"
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Vector2 GetResolution()
{
	Vector2 ret;
	ret.x = SCREEN_WIDTH;
	ret.y = SCREEN_HEIGHT;
	return ret;
}
