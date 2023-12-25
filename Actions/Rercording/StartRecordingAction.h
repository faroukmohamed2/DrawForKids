#pragma once
#include "../Action.h"
#include "../../ApplicationManager.h"

class StartRecordingAction : public Action
{
public:
	StartRecordingAction(ApplicationManager* pApp);
	Action* clone() const { return new StartRecordingAction(*this); }

	void ReadActionParameters();

	//Execute action (code depends on action type)
	void Execute();
};

