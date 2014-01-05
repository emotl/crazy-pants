#include "Game.h"

void Game::Start( sf::RenderWindow* targetWindow ) {
	if(_gameState != Uninitialized)
		return;	// Throw an error would be correct, but returning closes the game anyways.

	targetWindow->create(sf::VideoMode(1024, 768, 32), "Pang!");
	_gameState = Game::Playing;

	while( !IsExiting() ){
		GameLoop(targetWindow);
	}

	targetWindow->close();
}


bool Game::IsExiting() {
	if(_gameState == Game::Exiting)
		return true;
	else
		return false;
}


void Game::GameLoop(sf::RenderWindow* targetWindow) {
	sf::Event currentEvent;

	while (targetWindow->pollEvent(currentEvent)) {
		
		switch( _gameState ) {
		
			case Game::Playing: {
				targetWindow->clear(sf::Color(255, 0, 0));
				targetWindow->display();

				if( currentEvent.type == sf::Event::Closed){
					_gameState = Game::Exiting;
				}
				break;
			}
		}
	}
}

