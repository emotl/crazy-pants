#pragma once
#include "component.h"
#include "ComponentEntityBridge.h"

#define PI 3.14159265

class DrawController;

class DrawComponent :
	public Component
{
public:

	static const int magicNum = 1;

	DrawComponent(sf::Texture* texture);
	DrawComponent(const DrawComponent& original);
	DrawComponent(void);
	~DrawComponent(void);

	sf::Texture* sourceTexture;

	//basic "do work" function
	void update(sf::Time deltaTime) override;

	sf::Sprite* getSprite();
	void setTexture(sf::Texture* texture);
	
	void teleport(float x, float y);
	void rotateTo(float degrees);

	void moveAtSpeedPerSecond(float x, float y);
	void moveAtFacing(float speed);
	void rotateAtSpeedSecond(float degreesPerSecond);

	void matchTransform(const sf::Transformable& reference);

	void setOrigin(float x, float y);
	void setScale(float x, float y);

	sf::Vector2f getPosition();
	float getRotation();
	
	int magicNumber() override
	{return magicNum;}

private:
	sf::Sprite* drawSprite;
	sf::Vector2f linearMovement;
	float angle;
	float angleChange;

	void setupBaseData();

	void registerToController() override;


};

