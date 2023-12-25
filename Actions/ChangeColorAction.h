#pragma once

#include "Action.h"

class ChangeColorAction : public Action {


private:
	color SelectedColor;
	string ColorName;
	color lastColor;//the last default color before undoing the action

public:
	ChangeColorAction(ApplicationManager* pApp, ActionType);
	Action* clone() const { return new ChangeColorAction(*this); }

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual void undo();//the undo of the changing default color action

	virtual void redo();//the redo of the changing default color action

};