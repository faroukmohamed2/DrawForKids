#pragma once

#include "Action.h"
#include "..\ApplicationManager.h"


class MoveAction : public Action {


	bool CanExecute;
	CFigure* ToMove;
	Point NewLocation;

public:
	MoveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};
