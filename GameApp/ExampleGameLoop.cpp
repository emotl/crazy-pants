#include "stdafx.h"
#include "ExampleGameLoop.h"


ExampleGameLoop::ExampleGameLoop(void):GameState()
{
}


ExampleGameLoop::~ExampleGameLoop(void)
{
}


void ExampleGameLoop::gameLoop(sf::Time deltaTime)
{
}
	
//startInformation
void ExampleGameLoop::initialize(sf::SoundBuffer soundTarget)
{
	//no sound to be had
	pos.setPosition(30,30);
	pos.setRotation(90);
}

//draw loop
void ExampleGameLoop::drawLoop(sf::RenderWindow* drawTarget, sf::Time deltaTime)
{}