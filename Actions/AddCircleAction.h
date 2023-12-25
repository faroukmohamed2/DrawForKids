#pragma once

#include "Action.h"

class AddCircleAction : public Action {


private :
	Point P1, P2;
	GfxInfo CircleGfxInfo;
	int ID;
public :
	AddCircleAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();//the undo of add circle action
	virtual void redo();//the redo of add circle action

};
