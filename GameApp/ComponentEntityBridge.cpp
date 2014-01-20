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
{}

Controller* ComponentEntityBridge::findParent(Component* child)
{}
