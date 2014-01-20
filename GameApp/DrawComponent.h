#pragma once
#include "component.h"

class DrawController;

class DrawComponent :
	public Component
{
public:

	static const int magicNum = 1;

	DrawComponent(void);
	~DrawComponent(void);
	sf::Texture* sourceTexture;

	//as a user, call this to connect to the Controller
	void registerToController() override;

	//basic "do work" function
	void update(sf::Time deltaTime) override;

	sf::Sprite* getSprite();
	
	void teleport(float x, float y);
	void rotateTo(float degrees);

	void moveAtSpeedPerSecond(float x, float y);
	void moveAtFacing(float speed);
	void rotateAtSpeedSecond(float degreesPerSecond);

	void matchTransform(const sf::Transformable& reference);

	
	int magicNumber() override
	{return magicNum;}

private:
	sf::Sprite* drawSprite;
	sf::Transformable movementVector;

};

