#include "UndoAction.h"
#include "..\ApplicationManager.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false; //making the action non-undoable
	Recordable = true;
}

void UndoAction::ReadActionParameters()
{
	//we didn't take any parameters form the user after clicking on the undo action
}

void UndoAction::Execute()
{
	if (pManager->GetSoundState())
	{
		PlaySound("Undo.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	pManager->UndoLastAction();//calling the undolastAction function in the appmanager
	                           //and the undolastAction call the undo function of the last action in the array
	                           //very important note (every action is responsible to undo it self)->the undolastaction only call the undo function of every action
	                           //the undo of every action is a virtual function because every action has its implementation of the undo
}
