//GameStateManager.h
//GameStateManager keeps and manages GameStates.  gameLoop and Drawloop should be invoked somewhere near the main of 
//your program
//deltaTime is the amount of time passed since the last execution of the game loop.

#pragma once

#include <stack>
#include <assert.h>
#include "GameState.h"

using namespace std;

class GameStateManager
{
public:

	GameStateManager(void);
	~GameStateManager(void);
	void pushState(GameState* newState);
	void popState(void);
	void gameLoop(sf::Time deltaTime);
	void drawLoop(sf::RenderWindow* targetDrawSurface, sf::Time deltaTime);

private:

	stack<GameState*> stateStack;

	void deleteTopState();
};

