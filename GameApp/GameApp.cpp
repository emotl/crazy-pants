// GameApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

int _tmain(int argc, _TCHAR* argv[])
{
	sf::RenderWindow screen;
	screen.create( sf::VideoMode(1024,768,32), "Pang!" );

	Game::Start();

	return 0;
}

