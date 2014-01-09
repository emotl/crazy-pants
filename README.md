## SFML ENGINE ##
=================
### About ###
This Engine is desgined to be a starting base for a barebones game.
Using the SFML library in Visual Studio 2012 (*There is a branch for VS 2013*)


### Key Components ###

- ** Collision Detection **
	The engine needs to be able to watch *Game Objects* and throw 
	an event when they hit something that's deemed *collidable*
	
- ** State System **
	This system manages all the game states and notifies various 
	systems about the change in the state.

- ** Game Objects **
	This can be any renderable entity that is in the game.
	This has sprites, effects, particles and whatnot.
