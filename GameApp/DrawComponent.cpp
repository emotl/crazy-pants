#include "stdafx.h"
#include "DrawComponent.h"



DrawComponent::DrawComponent(sf::Texture* texture):animSet()
{
	drawSprite = new sf::Sprite(*texture);
	setupBaseData();
	registerToController();
}

void DrawComponent::setupBaseData()
{
	angle = 0;
	angleChange = 0;
	linearMovement.x = 0;
	linearMovement.y = 0;
	angularMovement = 0;
	zDepth = 1;

	if(drawSprite->getTexture() != NULL)
	{
		sf::Vector2u textureSize = drawSprite->getTexture()->getSize();
		animSet["default"]  = Animation(sf::IntRect(0,0, textureSize.x,textureSize.y), false, 1, 0);
		currentAnimPos.height = textureSize.y;
		currentAnimPos.width = textureSize.x;
	}

	playAnimation("default");
	playing = false;

	millisecondsSinceFrameChange = 0;
	currentAnimPos.left = 0;
	currentAnimPos.top = 0;

	rotationOffset = 0;

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
{
	//move position work
	float speedPerFrame = ((float)deltaTime.asMicroseconds())/1000000.0f;

	float cosValue = cos(angle * (PI/180.0f));
	float sinValue = sin(angle * (PI/180.0f));
	if(angularMovement > .01)
	{
		linearMovement.x = angularMovement * cosValue;
		linearMovement.y = angularMovement * sinValue;
	}

	angle += angleChange * speedPerFrame;
	drawSprite->setRotation(angle + rotationOffset);

	float xMov = drawSprite->getPosition().x + linearMovement.x * speedPerFrame;
	float yMov = drawSprite->getPosition().y + linearMovement.y * speedPerFrame;
	drawSprite->setPosition(xMov, yMov);

	//Frame position work
	if(playing)
	{
		advanceFrame(deltaTime);
	}
	drawSprite->setTextureRect(currentAnimPos);
}

void DrawComponent::advanceFrame(sf::Time deltaTime)
{
	millisecondsSinceFrameChange += deltaTime.asMicroseconds()/1000000.0;
	if(millisecondsSinceFrameChange >= (1.0/fps))
	{
		millisecondsSinceFrameChange = 0;

		//advance
		currentAnimPos.left += currentAnimPos.width;

		if(currentAnimPos.left > maxFrame * currentAnimPos.width)
		{
			currentAnimPos.left = 0;
		}
	}
}


sf::Sprite* DrawComponent::getSprite()
{
	return drawSprite;
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
	angle = degrees;
	drawSprite->setRotation(degrees);
}

//sets x/y movement componants.  Overrides moveAtFacing()
void DrawComponent::moveAtSpeedPerSecond(float x, float y)
{
	angularMovement = 0;
	linearMovement.x = x;
	linearMovement.y = y;
}

//sets speed to move at with facing.  Set facing with rotateTo or rotateAtSpeedSecond, overrides moveAtSpeedPerSecond
void DrawComponent::moveAtFacing(float speed)
{
	angularMovement = speed;
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

void DrawComponent::setOrigin(float x, float y)
{
	drawSprite->setOrigin(x,y);
}

sf::Vector2f DrawComponent::getPosition()
{
	return drawSprite->getPosition();
}

float DrawComponent::getRotation()
{
	return drawSprite->getRotation();
}

void DrawComponent::setScale(float x, float y)
{
	drawSprite->setScale(x,y);
}

int DrawComponent::getZDepth()
{
	return zDepth;
}
void DrawComponent::setZdepth(int depth)
{
	zDepth = depth;
}

void DrawComponent::addAnimation(string name, sf::IntRect startTile, int endFrame, bool looping, float FPS)
{
	animSet[name] = Animation(startTile, looping, endFrame, FPS);
}

void DrawComponent::playAnimation(string animName)
{
	playing = true;
	
	Animation current = animSet[animName];
	maxFrame = current.frameCount;
	looping = current.looping;
	fps = current.fps;

	currentAnimPos = current.start;
	currentAnimPos.left = 0;

	drawSprite->setOrigin(current.start.width/2, current.start.height/2);
}
void DrawComponent::pause()
{
	playing = false;
}