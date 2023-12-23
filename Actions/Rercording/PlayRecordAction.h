#pragma once
#include "../Action.h"
class PlayRecordAction :
    public Action
{
public:
	PlayRecordAction(ApplicationManager* pApp);

	void ReadActionParameters();

	//Execute action (code depends on action type)
	void Execute();
};

