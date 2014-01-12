#pragma once

#include "stdafx.h"

class GameState
{
public:
	virtual ~GameState(void);

	//get GameState Going
	virtual void gameLoop(sf::Time deltaTime);
	
	//startInformation
	virtual void initialize(sf::SoundBuffer soundTarget);


protected:
	sf::RenderWindow* targetWindow;
	sf::SoundBuffer* targetAudioPlayer;

private:
	//interface, cannot actually make
	GameState(void);
public:
	virtual void drawLoop(sf::RenderWindow* drawTarget);
};

