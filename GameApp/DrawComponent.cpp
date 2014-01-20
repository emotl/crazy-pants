#include "stdafx.h"
#include "DrawComponent.h"


DrawComponent::DrawComponent(void)
{
}


DrawComponent::~DrawComponent(void)
{
}

//as a user, call this to connect to the Controller
void DrawComponent::registerToController()
{}

//basic "do work" function
void DrawComponent::update(sf::Time deltaTime)
{}

sf::Sprite* DrawComponent::getSprite()
{
	return NULL;
}
	
void DrawComponent::teleport(float x, float y)
{}

void DrawComponent::rotateTo(float degrees)
{}

void DrawComponent::moveAtSpeedPerSecond(float x, float y)
{}

void DrawComponent::moveAtFacing(float speed)
{}

void DrawComponent::rotateAtSpeedSecond(float degreesPerSecond)
{}

void DrawComponent::matchTransform(const sf::Transformable& reference)
{}