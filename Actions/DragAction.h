#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class DragAction : public Action {
	bool CanExecute;
	CFigure* ToMove;
	Point NewLocation;
	Point lastLoaction;
	int FigID;
public:
	DragAction(ApplicationManager* pApp);

	Action* clone() const { return new DragAction(*this); }

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void undo();
	virtual void redo();







};
