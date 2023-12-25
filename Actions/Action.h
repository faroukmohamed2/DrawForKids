#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{

protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job
	bool UndoValidity;              //its a bool experssion that used to indicate the undoable actions
	bool Recordable;

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;
	bool GetUndoValidity() { return UndoValidity; }//get the undo ability of the action
	virtual void undo() {}                         //it is a pure function because every action 
	virtual void redo() { this->Execute(); }         //has its implementation of undo and redo
	

	bool isRecordable() { return Recordable; }
};

#endif