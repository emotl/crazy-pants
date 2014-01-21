// GameApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include "ComponentEntityBridge.h"
#include "DrawController.h"

void mapComponents(sf::RenderWindow &window);

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow screen;
	sf::SoundBuffer music;
	sf::Clock clock;
	screen.create( sf::VideoMode(1024,768,32), "Test Game Loop" );

	GameStateManager gamestateManager;
	
	ExampleGameLoop* firstGameLoop = new ExampleGameLoop();
	firstGameLoop->initialize(&music);

	gamestateManager.pushState(firstGameLoop);

	mapComponents(screen);

	while(screen.isOpen())
	{

		sf::Event event;
		while (screen.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				screen.close();
		}

		sf::Time deltaTime = clock.restart();
		gamestateManager.gameLoop(deltaTime);
		gamestateManager.drawLoop(&screen, deltaTime);

		

	}
	//Game::Start();

	return 0;
}


void mapComponents(sf::RenderWindow &window)
{
	ComponentEntityBridge* mapper = ComponentEntityBridge::getInstance();

	mapper->addParent(DrawController::getInstance(&window));
}

