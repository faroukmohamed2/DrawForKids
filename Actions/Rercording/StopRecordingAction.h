#pragma once
#include "../Action.h"

class StopRecordingAction : public Action
{
public:
	StopRecordingAction(ApplicationManager* pApp);

	void ReadActionParameters();

	//Execute action (code depends on action type)
	void Execute();
};

