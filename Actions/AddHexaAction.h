#pragma once

#include "Action.h"

class AddHexaAction : public Action {

	Point P1;
	GfxInfo HexaGfxInfo;
	int ID;

public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();
	void redo();
};