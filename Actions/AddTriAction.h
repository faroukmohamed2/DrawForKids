#pragma once

#include "Action.h"

class AddTriAction : public Action {


private:
	Point P1, P2 , P3;
	GfxInfo TriGfxInfo;
	int ID;
public:
	AddTriAction(ApplicationManager* pApp);
	Action* clone() const { return new AddTriAction(*this); }

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();
	virtual void redo();
};


