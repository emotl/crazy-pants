#include "stdafx.h"
#include "Fish.h"


sf::Texture* Fish::fishTexture = NULL;

Fish::Fish(void)
{
	initialize();
	float startAngle =  (float)(rand() % 360);
	SetLocation((float)(rand() % 800), (float)( rand()% 600), startAngle);
}


Fish::~Fish(void)
{
	delete drawComp;
}

Fish::Fish(float x, float y, float heading)
{
	initialize();
	SetLocation(x,y,heading);
}

void Fish::SetSpeed(float speed)
{
	drawComp->moveAtFacing(speed);
}

void Fish::SetTurnSpeed(float speed)
{
	drawComp->rotateAtSpeedSecond(speed);
}

void Fish::SetLocation(float x, float y, float heading)
{
	drawComp->teleport(x,y);
	drawComp->rotateTo(heading);
}

void Fish::initialize()
{
	addDrawComponent();

	SetSpeed(30);
	secondsToChangeDir = 4;
	SetTurnSpeed(8);
	RotationSpeed = 8;

	rightBoundry = 800;
	downBoundry = 600;

	flipped = false;
}

void Fish::addDrawComponent()
{
	if(fishTexture == NULL)
	{
		fishTexture = new sf::Texture();
		if (!fishTexture->loadFromFile("Assets/testFish.png"))
			std::cerr<<"Failed to load fish";
	}

	drawComp = new DrawComponent(fishTexture);
	parts.push_front(drawComp);

	drawComp->setOrigin(fishTexture->getSize().x/2, fishTexture->getSize().y/2);
	drawComp->setScale(.75,.75);
	drawComp->setZdepth(2);
}

void Fish::update(sf::Time deltaTime)
{

	if(clock.getElapsedTime().asSeconds() > secondsToChangeDir)
	{
		clock.restart();
		secondsToChangeDir = rand() % 5;
		RotationSpeed *= -1;
		SetTurnSpeed(RotationSpeed);
	}

		
	if((drawComp->getPosition().x > rightBoundry + 50 || drawComp->getPosition().x < 0 - 50) && !flipped)
	{
		drawComp->rotateTo(drawComp->getRotation() + 180);
		flipped = true;
	}

	if((drawComp->getPosition().y > downBoundry + 50 || drawComp->getPosition().y < 0 - 50) && !flipped)
	{
		drawComp->rotateTo(drawComp->getRotation() + 180);
		flipped = true;
	}
	if((drawComp->getPosition().y > downBoundry + 500 || drawComp->getPosition().y < 0 - 500) ||
		(drawComp->getPosition().y > downBoundry + 500 || drawComp->getPosition().y < 0 - 500) )
	{
		drawComp->teleport(-30,-30);
		drawComp->rotateTo(-45);
	}

	sf::Vector2f fishPosition = drawComp->getPosition(); 
	if((fishPosition.x > 0 + 50) && (fishPosition.x < rightBoundry -50) && (fishPosition.y > 0 + 50) && (fishPosition.y < downBoundry -50))
		flipped = false;

}

void Fish::setPoolSize(int width, int hieght)
{
	rightBoundry = width;
	downBoundry = hieght;
}


