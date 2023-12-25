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
	enum Style { Border, Fill };
	Style  ReqStyle;
	int FGindex;
	bool lastFillstate;// we will use it in the undo and redo action

public:
	ChangeFillAction(ApplicationManager* pApp, ActionType);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual void undo();//the undo action of changing color of the figure(border and fill)

	virtual void redo();//the redo action of changing color of the figure(border and fill)

};
