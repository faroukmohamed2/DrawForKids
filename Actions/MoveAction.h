#pragma once

#include "Action.h"
#include "..\ApplicationManager.h"


class MoveAction : public Action {


	bool CanExecute;
	CFigure* ToMove;
	Point NewLocation;
	Point lastLoaction;
	int FigID;
public:
	MoveAction(ApplicationManager* pApp);
	Action* clone() const { return new MoveAction(*this); }

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void undo();
	virtual void redo();
};
