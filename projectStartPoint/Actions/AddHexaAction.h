#pragma once

#include "Action.h"

class AddHexaAction : public Action {

	Point P1;
	GfxInfo HexaGfxInfo;

public:
	AddHexaAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};