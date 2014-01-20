//Controllers iterate over Components to do work.  Controllers should be implemented in a Singleton-ish fashion to aid in
//Components auto-finding the correct Controller

#pragma once
class Component;
class Controller
{
public:
	virtual ~Controller(void);

	virtual void update(sf::Time deltaTime) = 0;

	virtual void takePupil(Component* pupil) = 0;

	virtual int magicNumber() = 0;

protected:
	Controller(void);
};

