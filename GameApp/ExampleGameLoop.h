#pragma once
#include "GameState.h"
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
	//fish position
	sf::Transformable pos;
	sf::Texture fishTexture;
	sf::Sprite fishSprite;

	float secondsToChangeDir;
	float swimSpeed;
	float RotationSpeed;

	float rightBoundry;
	float downBoundry;

	bool flipped;

	sf::Clock clock;

};

