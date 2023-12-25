#pragma once


#include "Action.h"

class AddSquareAction : public Action {


private:
	Point P1;
	GfxInfo SquareGfxInfo;
	int ID;

public :
	AddSquareAction(ApplicationManager* pApp);
	Action* clone() const { return new AddSquareAction(*this); }

	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void undo();
	virtual void redo();
};