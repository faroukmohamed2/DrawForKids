#pragma once
#include "Action.h"

class UndoAction : public Action
{

	

public:
	
	
	UndoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void Execute();
};

