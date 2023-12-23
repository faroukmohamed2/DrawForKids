#pragma once
#include"Action.h"
#include "..\ApplicationManager.h"
class ClearAllAction : public Action
{



public:


	ClearAllAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	void Execute();
};