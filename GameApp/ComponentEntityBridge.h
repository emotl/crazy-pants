#pragma once

#include <list>

#include "Component.h"
#include "Controller.h"

using namespace std;

class ComponentEntityBridge
{
public:

	~ComponentEntityBridge(void);

	static ComponentEntityBridge* getInstance();
	void addParent(Controller* master);
	Controller* findParent(Component* child);

private:
	ComponentEntityBridge(void);

	static ComponentEntityBridge* instance;

	list<Controller*> parents;
};


