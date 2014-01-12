#pragma once

#include "GameState.h"

class GameStateManager
{
public:
	GameStateManager(void);
	~GameStateManager(void);
	void pushState(GameState* newState);
	void popState(void);
	void gameLoop(sf::Time deltaTime);
	void drawLoop(sf::RenderWindow* targetDrawSurface, sf::Time deltaTime);
};

