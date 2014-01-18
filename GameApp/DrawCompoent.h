#pragma once
#include "component.h"
class DrawCompoent :
	public Component
{
public:
	DrawCompoent(void);
	~DrawCompoent(void);
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

private:
	sf::Sprite* drawSprite;
	sf::Transformable movementVector;

};

