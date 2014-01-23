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
	DrawComponent* temp = (DrawComponent*)pupil;

	if(temp->getZDepth() <= 0)
		temp->setZdepth(1);
	if(temp->getZDepth() >= 11)
		temp->setZdepth(10);

	registeredComponents[temp->getZDepth()].push_front(temp);
}

void DrawController::update(sf::Time deltaTime)
{
	list<DrawComponent*>::iterator iter;
	DrawComponent* temp;

	for (int i = 1; i <= 10; i++)
	{
		for(iter = registeredComponents[i].begin(); iter != registeredComponents[i].end(); iter++)
		{
			temp = *iter;

			//do work
			temp->update(deltaTime);
		}
	}

	//all actual drawing happens here
	for (int i = 1; i <= 10; i++)
	{
		for(iter = registeredComponents[i].begin(); iter != registeredComponents[i].end(); iter++)
		{
			//get DrawComponent
			temp = (*iter);

			//send to screen
			targetWindow->draw(*(temp->getSprite()));
		}
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
