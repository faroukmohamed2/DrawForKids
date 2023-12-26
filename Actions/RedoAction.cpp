#include"RedoAction.h"
#include "UndoAction.h"
#include "..\ApplicationManager.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false;//making the action non-undoable
	Recordable = true;
}

void RedoAction::ReadActionParameters()
{
	//we didn't take any parameters form the user after clicking on the undo action
}

void RedoAction::Execute()
{
	if (pManager->GetSoundState())
	{
		PlaySound("Redo.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	pManager->RedoLastAction();//calling the redolastAction function in the appmanager
	                           //and the redoLastAction call the redo function of the last undid in the array
	                           //very important note (every action is responsible to redo it self)->the redolastAction only call the undo function of every action
	                           //the redo of every action is a virtual function because every action has its implementation of the redo
}

