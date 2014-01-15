//Controllers iterate over Components to do work.  Controllers should be implemented in a Singleton-ish fashion to aid in
//Components auto-finding the correct Controller

#pragma once
class Controller
{
public:
	virtual ~Controller(void);

	static Controller* getInstance(void);



protected:
	Controller(void);
};

