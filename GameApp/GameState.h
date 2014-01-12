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

	virtual void drawLoop(sf::RenderWindow* drawTarget, sf::Time deltaTime);

	void setReadyToDie();

	bool wantToPop();


protected:
	sf::RenderWindow* targetWindow;
	sf::SoundBuffer* targetAudioPlayer;
	
	//include in parameter list when inheriting
	GameState(void);

private:
	bool killMe;
	
};

