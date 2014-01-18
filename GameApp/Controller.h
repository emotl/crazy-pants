//Controllers iterate over Components to do work.  Controllers should be implemented in a Singleton-ish fashion to aid in
//Components auto-finding the correct Controller

#pragma once
class Controller
{
public:
	virtual ~Controller(void);

	virtual void update(sf::Time deltaTime) = 0;

protected:
	Controller(void);
};

