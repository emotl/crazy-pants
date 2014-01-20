#pragma once

#include "Component.h"
#include "Controller.h"

class ComponentEntityBridge
{
public:

	~ComponentEntityBridge(void);

	ComponentEntityBridge* getInstance();
	void giveComponentToController(Component* pupil);

private:
	ComponentEntityBridge(void);
};

