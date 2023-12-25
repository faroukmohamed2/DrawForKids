#pragma once

#include "Action.h"

class ChangeColorAction : public Action {


private:
	color SelectedColor;
	string ColorName;
	string lastColorName;
	color lastColor;

public:
	ChangeColorAction(ApplicationManager* pApp, ActionType);
	Action* clone() const { return new ChangeColorAction(*this); }

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual void undo();

	virtual void redo();

};