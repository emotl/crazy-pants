#pragma once

#include <list>
#include "controller.h"
#include "DrawComponent.h"

using namespace std;

class DrawController :
	public Controller
{
public:

	static const int magicNum = 1;

	static DrawController* getInstance();

	virtual ~DrawController(void);
	void takePupil(Component* pupil) override;
	void update(sf::Time deltaTime) override;

	int magicNumber() override
	{return magicNum;}

private:
	DrawController(void);
	list<DrawComponent*> registeredComponents;

	static DrawController* instance;
};



