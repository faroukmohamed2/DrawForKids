#pragma once

#include "Action.h"
#include "..\ApplicationManager.h"


class MoveAction : public Action {


	bool CanExecute;
	CFigure* ToMove;
	Point NewLocation;
	Point lastLoaction;//we need it in the undo action
	int FigID;
public:
	MoveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void undo();//the undo of moving figure action
	virtual void redo();//the redo of moving figure action
};
