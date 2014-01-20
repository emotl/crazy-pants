#include "stdafx.h"
#include "DrawComponent.h"


DrawComponent::DrawComponent(void)
{
}


DrawComponent::~DrawComponent(void)
{
}

//as a user, call this to connect to the Controller
void registerToController()
{}

//basic "do work" function
void update(sf::Time deltaTime)
{}

sf::Sprite* getSprite()
{}
	
void teleport(float x, float y)
{}

void rotateTo(float degrees)
{}

void moveAtSpeedPerSecond(float x, float y)
{}

void moveAtFacing(float speed)
{}

void rotateAtSpeedSecond(float degreesPerSecond)
{}

void matchTransform(const sf::Transformable& reference)
{}