#pragma once

#include "SFML\Graphics.hpp"

class Game {

public:
	static void Start(sf::RenderWindow* targetWindow);

private:
	static bool IsExiting();
	static void GameLoop(sf::RenderWindow* targetWindow);

	enum GameState {
		Uninitialized,
		ShowingSplash,
		Paused,
		ShowingMenu,
		Playing,
		Exiting
	};

	static GameState _gameState;
	//don't make SF types static
	sf::RenderWindow _mainWindow;
};

Game::GameState Game::_gameState = Game::Uninitialized;

