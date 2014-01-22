#pragma once
#include "gameobject.h"
#include "DrawComponent.h"
#include <stdlib.h>
#include <time.h>

using namespace std;


class Fish :
	public GameObject
{
public:
	Fish(float x, float y, float heading);
	Fish(void);
	~Fish(void);
	void SetLocation(float x, float y, float heading);

	void SetSpeed(float speed);
	void SetTurnSpeed(float speed);

	void update(sf::Time deltaTime);

	void setPoolSize(int width, int hieght);



private:

	void initialize();
	void addDrawComponent();

	static sf::Texture* fishTexture;
	DrawComponent* drawComp;

	sf::Clock clock;

	float rightBoundry;
	float downBoundry;

	float secondsToChangeDir;
	float swimSpeed;
	float RotationSpeed;
	bool flipped;


};

