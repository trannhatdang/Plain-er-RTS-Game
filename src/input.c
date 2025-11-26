#include "input.h"

typedef struct {
	int JumpButtons[2];
} FlappyControls;

FlappyControls* m_flapControls;

void InitializeInputModule()
{
	m_flapControls = (FlappyControls*)malloc(sizeof(FlappyControls));

	m_flapControls->JumpButtons[0] = KEY_SPACE;
	m_flapControls->JumpButtons[1] = KEY_F;
}

void FreeInputModule()
{
	free(m_flapControls);
}

bool Input_CheckExist()
{
	if(!m_flapControls)
	{
		printf("You haven't initialized the input module yet!");
		return false;
	}
	return true;
}

bool Flappy_GetJumpButton()
{
	Input_CheckExist();
	return (IsKeyPressed(m_flapControls->JumpButtons[0]) || IsKeyPressed(m_flapControls->JumpButtons[1]));
}
