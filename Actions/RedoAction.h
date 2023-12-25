#pragma once
#include"Action.h"
class RedoAction : public Action
{



public:


	RedoAction(ApplicationManager* pApp);
	Action* clone() const { return new RedoAction(*this); }

	virtual void ReadActionParameters();
	void Execute();
};