#include "stdafx.h"
#include "DrawController.h"

DrawController* DrawController::instance = NULL;

DrawController::DrawController(void)
{
}


DrawController::~DrawController(void)
{
}

void DrawController::takePupil(Component* pupil) 
{
}

void DrawController::update(sf::Time deltaTime)
{

}

DrawController* DrawController::getInstance()
{
	if(instance == NULL)
	{
		instance = new DrawController;
	}
	return instance;
}
