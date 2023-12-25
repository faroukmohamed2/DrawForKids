#include "UndoAction.h"
#include "..\ApplicationManager.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false; //making the action non-undoable
	Recordable = true;
}

void UndoAction::ReadActionParameters()
{

}

void UndoAction::Execute()
{
	pManager->UndoLastAction();

}
