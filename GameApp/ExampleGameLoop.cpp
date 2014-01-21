#include "stdafx.h"
#include "ExampleGameLoop.h"

#define PI 3.14159265

ExampleGameLoop::ExampleGameLoop(void):GameState()
{
}


ExampleGameLoop::~ExampleGameLoop(void)
{
}


void ExampleGameLoop::gameLoop(sf::Time deltaTime)
{
	float rotation = RotationSpeed * ((float)deltaTime.asMicroseconds())/1000000.0;

	sf::Vector2f displacement;
	float cosValue = cos(fishSprite.getRotation() * (PI/180.0));
	float sinValue = sin(fishSprite.getRotation() * (PI/180.0));
	float deltaTimeValue =  ((float)deltaTime.asMicroseconds())/1000.0;
	displacement.x = swimSpeed * cosValue * deltaTimeValue;
	displacement.y = swimSpeed * sinValue * deltaTimeValue;

	if(clock.getElapsedTime().asSeconds() > secondsToChangeDir)
	{
		clock.restart();
		secondsToChangeDir = rand() % 5;
		RotationSpeed *= -1;
	}

	pos.setPosition(displacement);
	pos.setRotation(rotation);

	
	if((fishSprite.getPosition().x > rightBoundry + 50 || fishSprite.getPosition().x < 0 - 50) && !flipped)
	{
		fishSprite.rotate(180);
		fishSprite.setScale(fishSprite.getScale().x , fishSprite.getScale().y * -1);
		flipped = true;
	}

	if((fishSprite.getPosition().y > downBoundry + 50 || fishSprite.getPosition().y < 0 - 50) && !flipped)
	{
		fishSprite.rotate(180);
		fishSprite.setScale(fishSprite.getScale().x * -1, fishSprite.getScale().y );
		flipped = true;
	}

	sf::Vector2f fishPosition = fishSprite.getPosition(); 
	if((fishPosition.x > 0 + 50) && (fishPosition.x < rightBoundry -50) && (fishPosition.y > 0 + 50) && (fishPosition.y < downBoundry -50))
		flipped = false;
}
	
//startInformation
void ExampleGameLoop::initialize(sf::SoundBuffer* soundTarget)
{
	//no sound to be had
	pos.setPosition(60,60);
	pos.setRotation(0);

	fishSprite.setPosition(pos.getPosition());
	fishSprite.setRotation(pos.getRotation());

	if (!fishTexture.loadFromFile("Assets/testFish.png"))
		std::cerr<<"Failed to load fish";

	fishSprite.setOrigin(fishTexture.getSize().x/2, fishTexture.getSize().y/2);
	fishSprite.setTexture(fishTexture);

	swimSpeed = .07;
	secondsToChangeDir = 2;
	RotationSpeed = 8;

	flipped = false;

	srand(time(NULL));

}

//draw loop
void ExampleGameLoop::drawLoop(sf::RenderWindow* drawTarget, sf::Time deltaTime)
{
	rightBoundry = drawTarget->getSize().x;
	downBoundry = drawTarget->getSize().y;

	drawTarget->clear(sf::Color::Blue);
	fishSprite.move(pos.getPosition());
	fishSprite.rotate(pos.getRotation());
	fishSprite.setScale(.5,.5);

}