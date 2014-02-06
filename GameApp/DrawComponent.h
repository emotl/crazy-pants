#pragma once
#include "component.h"
#include "ComponentEntityBridge.h"
#include <map>

#define PI 3.14159265

struct Animation;

class DrawController;

class DrawComponent :
	public Component
{
public:

	static const int magicNum = 1;

	DrawComponent(sf::Texture* texture);
	DrawComponent(const DrawComponent& original);
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

	void addAnimation(string name, sf::IntRect startTile, int endFrame, bool looping, float FPS);
	void playAnimation(string animName);
	void pause();

	sf::Vector2f getPosition();
	float getRotation();

	//Controller asks for this for draw order, from 1 to 10, where 1 is under everything.  numbers are normalized from 1 to 10
	int getZDepth();
	void setZdepth(int depth);
	
	int magicNumber() override
	{return magicNum;}

private:
	sf::Sprite* drawSprite;
	sf::Vector2f linearMovement;
	sf::IntRect currentAnimPos;
	float angularMovement;
	float angle;
	float angleChange;

	int zDepth;

	void setupBaseData();

	void registerToController() override;

	map<string, Animation> animSet;

	bool playing;
	int maxFrame;
	bool looping;
	float fps;

	int millisecondsSinceFrameChange;

	void advanceFrame(sf::Time deltaTime);

};

struct Animation
{
	sf::IntRect start;
	bool looping;
	int frameCount;
	float fps;
	
	Animation()
	{
		start = sf::IntRect();
		looping = false;
		frameCount = 0;
		fps = 0;
	}

	Animation(sf::IntRect rect, bool loop, int frames, float FPS)
	{
		start = rect;
		looping = loop;
		frameCount  = frames;
		fps = FPS;
	};
	

};