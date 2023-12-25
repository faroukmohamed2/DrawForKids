#pragma once

#include "Action.h"

class AddHexaAction : public Action {

	Point P1;
	GfxInfo HexaGfxInfo;
	int ID;
public:
	AddHexaAction(ApplicationManager* pApp);
	Action* clone() const { return new AddHexaAction(*this); }
	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();//the undo of add hexagon action
	virtual void redo();//the redo of add hexagon action

};