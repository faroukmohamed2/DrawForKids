#pragma once
#include "Action.h"

class UndoAction : public Action
{



public:


	UndoAction(ApplicationManager* pApp);
	Action* clone() const { return new UndoAction(*this); }

	virtual void ReadActionParameters();
	void Execute();
};
