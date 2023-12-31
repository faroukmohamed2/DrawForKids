#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"



class ChangeFillAction : public Action {


private:
	color SelectedColor;
	string ColorName;
	CFigure* ToChange;
	color lastSelected;
	enum Style { Border, Fill };
	Style  ReqStyle;
	int FGindex;
	bool lastFillstate;// we will use it in the undo and redo action
	bool CurrentState;

public:
	ChangeFillAction(ApplicationManager* pApp, ActionType);
	Action* clone() const { return new ChangeFillAction(*this); }

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

	virtual void undo();//the undo action of changing color of the figure(border and fill)

	virtual void redo();//the redo action of changing color of the figure(border and fill)

};
