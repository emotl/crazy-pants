#include "Game.h"

void Game::Start( void ) {
	if(_gameState != Uninitialized)
		return;	// Throw an error would be correct, but returning closes the game anyways.

	_mainWindow.create( sf::VideoMode(1024,768,32), "Pang!" );
	_gameState = Game::Playing;

	while( !IsExiting() ){
		GameLoop();
	}

	_mainWindow.close();
}


bool Game::IsExiting() {
	if(_gameState == Game::Exiting)
		return true;
	else
		return false;
}


void Game::GameLoop() {
	sf::Event currentEvent;

	while( _mainWindow.pollEvent(currentEvent) ) {
		
		switch( _gameState ) {
		
			case Game::Playing: {
				_mainWindow.clear(sf::Color(255,0,0));
				_mainWindow.display();

				if( currentEvent.type == sf::Event::Closed){
					_gameState = Game::Exiting;
				}
				break;
			}
		}
	}
}

Game::GameState Game::_gameState = Game::Uninitialized;
sf::RenderWindow Game::_mainWindow;