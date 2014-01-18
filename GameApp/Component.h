//Components plug into GameObjects and Controllers.  

#pragma once
class Component
{
public:
	Component(void);
	virtual ~Component(void);

	//as a user, call this to connect to the Controller
	virtual void registerToController() = 0;

	//basic "do work" function
	virtual void update(sf::Time deltaTime) = 0;
};

