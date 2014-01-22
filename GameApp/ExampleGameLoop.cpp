#include "stdafx.h"
#include "ExampleGameLoop.h"

#define PI 3.14159265

ExampleGameLoop::ExampleGameLoop(void):GameState()
{

}


ExampleGameLoop::~ExampleGameLoop(void)
{
	delete Drawer;
}


void ExampleGameLoop::gameLoop(sf::Time deltaTime)
{
	fish->update(deltaTime);

}
	
//startInformation
void ExampleGameLoop::initialize(sf::SoundBuffer* soundTarget)
{
	fish = new Fish(60,60, 0); 
	
	srand(time(NULL));
}

//draw loop
void ExampleGameLoop::drawLoop(sf::RenderWindow* drawTarget, sf::Time deltaTime)
{
	drawTarget->clear(sf::Color::Blue);

	fish->setPoolSize(drawTarget->getSize().x, drawTarget->getSize().y);

	Drawer = DrawController::getInstance(drawTarget);
	Drawer->update(deltaTime);

	drawTarget->display();
	
}