#pragma once
#include "Component.h"
#include "ComponentEntityBridge.h"

class HandleInputComponent : 
	public Component
{
public: 

	static const int magicNum = 2;

	HandleInputComponent(sf::Event::JoystickButtonEvent* sfEvent);
	HandleInputComponent(sf::Event::JoystickMoveEvent* sfEvent);
	HandleInputComponent(sf::Event::MouseButtonEvent* sfEvent);
	HandleInputComponent(sf::Event::MouseMoveEvent* sfEvent);
	HandleInputComponent(sf::Event::MouseWheelEvent* sfEvent);
	HandleInputComponent(sf::Event::KeyEvent* sfEvent);
	//HandleInputComponent(void); // We only want to handle events
	~HandleInputComponent(void);

	//basic "do work" function
	void update(sf::Time deltaTime) override;

	int magicNumber() override
	{return magicNum;}

private:
	void setupBaseData();

	void registerToController() override;

};