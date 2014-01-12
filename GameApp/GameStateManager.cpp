#include "stdafx.h"
#include "GameStateManager.h"



GameStateManager::GameStateManager(void) : stateStack()
{
}


GameStateManager::~GameStateManager(void)
{
	while(!stateStack.empty())
	{
		deleteTopState();
	}
}


void GameStateManager::pushState(GameState* newState)
{
	stateStack.push(newState);
}


void GameStateManager::popState(void)
{
	assert(!stateStack.empty());
	if (!stateStack.empty())
	{
		deleteTopState();
	}
}


void GameStateManager::gameLoop(sf::Time deltaTime)
{

	//ensure suicidal state dies
	GameState* current = stateStack.top();

	if(current->wantToPop())
	{
		deleteTopState();
		current = stateStack.top();
	}

	//do top loop
	current->gameLoop(deltaTime);

}


void GameStateManager::drawLoop(sf::RenderWindow* targetDrawSurface, sf::Time deltaTime)
{
	//do top loop
	stateStack.top()->drawLoop(targetDrawSurface,deltaTime);
}

void GameStateManager::deleteTopState()
{
	GameState* current = stateStack.top();

	delete current;
	stateStack.pop();
}
