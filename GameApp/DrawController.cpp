#include "stdafx.h"
#include "DrawController.h"

DrawController* DrawController::instance = NULL;

DrawController::DrawController(sf::RenderWindow* target):registeredComponents()
{
	targetWindow = target;
}


DrawController::~DrawController(void)
{
}

void DrawController::takePupil(Component* pupil) 
{
	registeredComponents.push_front((DrawComponent*)pupil);
}

void DrawController::update(sf::Time deltaTime)
{
	list<DrawComponent*>::iterator iter;
	DrawComponent* temp;


	for(iter = registeredComponents.begin(); iter != registeredComponents.end(); iter++)
	{
		temp = *iter;

		//do work
		temp->update(deltaTime);
	}

	//all actual drawing happens here

	for(iter = registeredComponents.begin(); iter != registeredComponents.end(); iter++)
	{
		//get DrawComponent
		temp = (*iter);

		//send to screen
		targetWindow->draw(*(temp->getSprite()));
	}
}

DrawController* DrawController::getInstance(sf::RenderWindow* target)
{
	if(instance == NULL)
	{
		instance = new DrawController(target);
	}
	return instance;
}
