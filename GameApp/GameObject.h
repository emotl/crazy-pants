#pragma once
class GameObject
{
public:
	GameObject(void);
	~GameObject(void);
	List<Componant*> parts;
};

