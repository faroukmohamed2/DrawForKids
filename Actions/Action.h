#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
private:
	
	bool ActionState;
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	bool UndoValidity;

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;
	virtual void undo() {}
	virtual void redo(){}
	bool GetActionState() { return ActionState; }
	bool GetUndoValidity() { return UndoValidity; }
	void SetActionState(bool x) { ActionState = x; }
	

};

#endif