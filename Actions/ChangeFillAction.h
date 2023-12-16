#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"



class ChangeFillAction : public Action {


private:
	color SelectedColor;
	string ColorName;
	bool CanExecute;
	CFigure* ToChange;
	color lastSelected;
	bool lastFillstate;
	enum Style { Border, Fill };
	Style  ReqStyle;
	int FGindex;

public:
	ChangeFillAction(ApplicationManager* pApp, ActionType);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void undo();
	virtual void redo();
};
