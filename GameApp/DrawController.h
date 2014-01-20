#pragma once

#include <list>
#include "controller.h"
#include "DrawComponent.h"

using namespace std;

class DrawController :
	public Controller
{
public:

	const int magicNum = 1;

	DrawController(void);
	virtual ~DrawController(void);
	void takePupil(Component* pupil) override;
	void update(sf::Time deltaTime) override;

	int magicNumber() override
	{return magicNum;}

private:
	list<DrawComponent*> registeredComponents;
};

