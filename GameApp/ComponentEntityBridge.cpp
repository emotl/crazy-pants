#include "stdafx.h"
#include "ComponentEntityBridge.h"


ComponentEntityBridge::ComponentEntityBridge(void):parents()
{
}


ComponentEntityBridge::~ComponentEntityBridge(void)
{
}

ComponentEntityBridge* ComponentEntityBridge::getInstance()
{
	if (ComponentEntityBridge::instance == NULL)
	{
		instance = new ComponentEntityBridge();
	}

	return instance;
}
	


void ComponentEntityBridge::addParent(Controller* master)
{
	parents.push_front(master);
}

Controller* ComponentEntityBridge::findParent(Component* child)
{
	list<Controller*>::iterator iter;
	
	int magicNumber = child->magicNumber();

	for(iter = parents.begin(); iter != parents.end(); iter++)
	{
		if(magicNumber == (*iter)->magicNumber())
		{
			(*iter)->takePupil(child);

			return *iter;
		}

	}
	return NULL;
}
