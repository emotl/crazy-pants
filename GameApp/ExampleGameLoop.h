#pragma once
#include "GameState.h"
#include "DrawController.h"
#include "Fish.h"
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


class ExampleGameLoop :
	public GameState
{
public:
	ExampleGameLoop(void);
	~ExampleGameLoop(void);

	//game loop
	void gameLoop(sf::Time deltaTime);
	
	//startInformation
	void initialize(sf::SoundBuffer* soundTarget);

	//draw loop
	void drawLoop(sf::RenderWindow* drawTarget, sf::Time deltaTime);

private:

	sf::Clock clock;
	Fish* fish[10];
	DrawController* Drawer;

};

