#include "stdafx.h"
#include "ExampleGameLoop.h"

#define PI 3.14159265

ExampleGameLoop::ExampleGameLoop(void):GameState()
{

}


ExampleGameLoop::~ExampleGameLoop(void)
{
	delete Drawer;
	for (int i = 0; i < 10; i++)
		delete fish[i];
}


void ExampleGameLoop::gameLoop(sf::Time deltaTime)
{
	for (int i = 0; i < 10; i++)
		fish[i]->update(deltaTime);

}
	
//startInformation
void ExampleGameLoop::initialize(sf::SoundBuffer* soundTarget)
{
	for (int i = 0; i < 10; i++)
		fish[i] = new Fish(); 

	//example on how to live composite a object
	GameObject lake;
	sf::Texture* lakeImage = new sf::Texture();
	lakeImage->loadFromFile("Assets/pondBG.png");
	DrawComponent* lakeDisplay = new DrawComponent(lakeImage);
	lakeDisplay->setScale(2,2);
	lake.parts.push_front(lakeDisplay);
	lakeDisplay->setOrigin(0,0);
	
	srand(time(NULL));
}

//draw loop
void ExampleGameLoop::drawLoop(sf::RenderWindow* drawTarget, sf::Time deltaTime)
{
	drawTarget->clear(sf::Color::Blue);
	
	for (int i = 0; i < 10; i++)
		fish[i]->setPoolSize(drawTarget->getSize().x, drawTarget->getSize().y);

	Drawer = DrawController::getInstance(drawTarget);
	Drawer->update(deltaTime);

	drawTarget->display();
	
}