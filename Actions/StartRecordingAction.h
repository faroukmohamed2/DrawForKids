#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class StartRecordingAction : public Action
{
public:
	StartRecordingAction(ApplicationManager* pApp);
	
	void ReadActionParameters();

	//Execute action (code depends on action type)
	void Execute();
};

