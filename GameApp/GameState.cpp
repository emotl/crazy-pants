#include "stdafx.h"
#include "GameState.h"


GameState::GameState(void)
{
	killMe = false;
}


GameState::~GameState(void)
{
}

void GameState::gameLoop(sf::Time deltaTime)
{
}

void GameState::initialize(sf::SoundBuffer soundTarget)
{
}


void GameState::drawLoop(sf::RenderWindow* drawTarget, sf::Time deltaTime)
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
