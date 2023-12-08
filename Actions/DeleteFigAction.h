#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"

class DeleteFigAction : public Action {

private:
	bool CanExecute;
	CFigure* ToDelete;
public:
	DeleteFigAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

