#pragma once
#include "Action.h"
class LoadAction :
    public Action
{
	string name;
public:
	LoadAction(ApplicationManager* pApp);	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	void ReadActionParameters();

	//Execute action (code depends on action type)
	void Execute();
};

