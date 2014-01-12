#include "stdafx.h"
#include "GameState.h"


GameState::GameState(void)
{
	killMe = false;
}


GameState::~GameState(void)
{
}

bool GameState::wantToPop()
{
	return killMe;
}

void GameState::setReadyToDie()
{
	killMe = true;
}
