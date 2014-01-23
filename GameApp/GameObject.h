#pragma once

#include <list>
#include "Component.h"

using namespace std;

class GameObject
{
public:
	GameObject(void);
	~GameObject(void);
	list<Component*> parts;
};

