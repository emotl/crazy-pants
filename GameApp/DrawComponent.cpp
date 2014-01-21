#include "stdafx.h"
#include "DrawComponent.h"


DrawComponent::DrawComponent(void)
{
	drawSprite = new sf::Sprite();
	angle = 0;
	angleChange = 0;
}

DrawComponent::DrawComponent(sf::Texture* texture)
{
	drawSprite = new sf::Sprite(*texture);
	angle = 0;
	angleChange = 0;
}

DrawComponent::~DrawComponent(void)
{
	delete drawSprite;
}

DrawComponent::DrawComponent(const DrawComponent& original)
{
	drawSprite = new sf::Sprite(*(original.drawSprite));
}

//as a user, call this to connect to the Controller
void DrawComponent::registerToController()
{
	ComponentEntityBridge* finder = ComponentEntityBridge::getInstance();
	finder->findParent(this);
}

//basic "do work" function, called by controller
void DrawComponent::update(sf::Time deltaTime)
{}

sf::Sprite* DrawComponent::getSprite()
{
	return NULL;
}

void DrawComponent::setTexture(sf::Texture* texture)
{
	drawSprite = new sf::Sprite(*texture);
}
	
void DrawComponent::teleport(float x, float y)
{
	drawSprite->setPosition(x,y);
}

void DrawComponent::rotateTo(float degrees)
{
	drawSprite->setRotation(degrees);
}

//sets x/y movement componants.  Overrides moveAtFacing()
void DrawComponent::moveAtSpeedPerSecond(float x, float y)
{
	linearMovement.x = x;
	linearMovement.y = y;
}

//sets speed to move at with facing.  Set facing with rotateTo or rotateAtSpeedSecond, overrides moveAtSpeedPerSecond
void DrawComponent::moveAtFacing(float speed)
{
	float cosValue = cos(angle * (PI/180.0));
	float sinValue = sin(angle * (PI/180.0));
	linearMovement.x = speed * cosValue;
	linearMovement.y = speed * sinValue;
}

void DrawComponent::rotateAtSpeedSecond(float degreesPerSecond)
{
	angleChange = degreesPerSecond;
}

void DrawComponent::matchTransform(const sf::Transformable& reference)
{
	drawSprite->setPosition(reference.getPosition());
	drawSprite->setRotation(reference.getRotation());
}