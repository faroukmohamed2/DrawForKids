#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{

protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	bool UndoValidity;
	bool Recordable;

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;
	bool GetUndoValidity() { return UndoValidity; }
	virtual void undo() {}
	virtual void redo() { this->Execute(); }

	bool isRecordable() { return Recordable; }
};

#endif