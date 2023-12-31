#pragma once


#include "Action.h"

class SelectAction : public Action {


	Point P1;
	//CFigure* selectedFigure;
	int selectedId = -1;
	bool CanExecute = false;

public : 
	SelectAction(ApplicationManager* pApp);
	Action* clone() const { return new SelectAction(*this); }

	virtual void ReadActionParameters();

	virtual void Execute();

	void redo();


}; 