#include "stdafx.h"
#include "HandleInputComponent.h"

HandleInputComponent::HandleInputComponent(sf::Event::JoystickButtonEvent* sfEvent)
{
}

HandleInputComponent::HandleInputComponent(sf::Event::JoystickMoveEvent* sfEvent)
{
}

HandleInputComponent::HandleInputComponent(sf::Event::MouseButtonEvent* sfEvent)
{
}

HandleInputComponent::HandleInputComponent(sf::Event::MouseMoveEvent* sfEvent)
{
}

HandleInputComponent::HandleInputComponent(sf::Event::MouseWheelEvent* sfEvent)
{
}

HandleInputComponent::HandleInputComponent(sf::Event::KeyEvent* sfEvent)
{
}

HandleInputComponent::~HandleInputComponent(void)
{
}

void HandleInputComponent::setupBaseData()
{
	// Nothing to setup.
}

//as a user, call this to connect to the controller
void HandleInputComponent::registerToController()
{
	ComponentEntityBridge* finder = ComponentEntityBridge::getInstance();
	finder->findParent(this);
}

//basic "do work" function, called by the controller
void HandleInputComponent::update(sf::Time deltaTime)
{
	// I don't know what this should be doing every update.
}