#pragma once

#include "Action.h"

class ChangeColorAction : public Action {


private:
	color SelectedColor;
	string ColorName;
	color lastSelectedColor;
	string lastSelectedNameColor;

public:
	ChangeColorAction(ApplicationManager* pApp, ActionType);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();
};