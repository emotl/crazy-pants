#pragma once

#include <list>
#include "controller.h"
#include "DrawComponent.h"

using namespace std;

class DrawController :
	public Controller
{
public:
	DrawController(void);
	virtual ~DrawController(void);
	void takePupil(Component* pupil) override;
	void update(sf::Time deltaTime) override;

private:
	list<DrawComponent*> registeredComponents;
};

