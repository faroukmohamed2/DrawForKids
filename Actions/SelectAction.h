#pragma once


#include "Action.h"

class SelectAction : public Action {


	Point P1;

public : 
	SelectAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();


}; 