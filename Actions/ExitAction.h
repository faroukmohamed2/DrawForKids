
#pragma once
#include"Action.h"
#include "..\ApplicationManager.h"
class ExitAction : public Action
{



public:


	ExitAction(ApplicationManager* pApp);
	Action* clone() const { return new ExitAction(*this); }

	virtual void ReadActionParameters();
	void Execute();
};