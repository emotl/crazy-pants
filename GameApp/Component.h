//Components plug into GameObjects and Controllers.  

#pragma once
class Component
{
public:

	virtual ~Component(void);

	//as a user, call this to connect to the Controller
	virtual void registerToController() = 0;

	//basic "do work" function
	virtual void update(sf::Time deltaTime) = 0;

	//for matching to controller.  controllers and components magic numbers should match.
	virtual int magicNumber() = 0;

protected:
	Component(void);
};

