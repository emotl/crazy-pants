//GameState.h
//Game State that can be stacked on other game states.  override to make your own game loops
//slots into a GameStateManager

#pragma once

#include "stdafx.h"

class GameState
{
public:
	virtual ~GameState(void);

	//game loop
	virtual void gameLoop(sf::Time deltaTime) = 0;
	
	//startInformation
	virtual void initialize(sf::SoundBuffer* soundTarget) = 0;

	//draw loop
	virtual void drawLoop(sf::RenderWindow* drawTarget, sf::Time deltaTime) = 0;

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

