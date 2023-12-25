#pragma once
#include"Action.h"
#include "..\ApplicationManager.h"
class ClearAllAction : public Action
{



public:


	ClearAllAction(ApplicationManager* pApp);
	Action* clone() const { return new ClearAllAction(*this); }

	virtual void ReadActionParameters();
	void Execute();
};