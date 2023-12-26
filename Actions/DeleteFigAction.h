#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class DeleteFigAction : public Action {

private:
	//bool CanExecute;
	CFigure* ToDelete;
	int  FigID;
public:
	DeleteFigAction(ApplicationManager* pApp);
	Action* clone() const { return new DeleteFigAction(*this); }

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual void undo();

	virtual void redo();
	~DeleteFigAction();

};


