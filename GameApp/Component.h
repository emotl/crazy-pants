//Components plug into GameObjects and Controllers.  

#pragma once
class Component
{
public:
	Component(void);
	virtual ~Component(void);

	//returns sprite to be outputted.  Draw Controllers will look here
	virtual sf::Sprite* draw() = 0;
	
	//make this return true if you want Draw to be called
	virtual bool drawable() = 0;

	//as a user, call this to connect to the Controller
	virtual void registerToController() = 0;
};

