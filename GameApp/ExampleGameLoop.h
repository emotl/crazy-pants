#pragma once
#include "GameState.h"


class ExampleGameLoop :
	public GameState
{
public:
	ExampleGameLoop(void);
	~ExampleGameLoop(void);

	//game loop
	void gameLoop(sf::Time deltaTime);
	
	//startInformation
	void initialize(sf::SoundBuffer soundTarget);

	//draw loop
	void drawLoop(sf::RenderWindow* drawTarget, sf::Time deltaTime);

private:
	//fish position
	sf::Transformable pos;

};

