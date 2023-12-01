#pragma once

#include "Action.h"

class AddCircleAction : public Action {


private :
	Point P1, P2;
	GfxInfo CircleGfxInfo;
public :
	AddCircleAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};
