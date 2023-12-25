#pragma once
#include "../Action.h"
class PlayRecordAction :
    public Action
{
public:
	PlayRecordAction(ApplicationManager* pApp);
	Action* clone() const { return new PlayRecordAction(*this); }
	void ReadActionParameters();

	//Execute action (code depends on action type)
	void Execute();
};

