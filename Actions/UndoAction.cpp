#include "UndoAction.h"
#include "..\ApplicationManager.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false;
}

void UndoAction::ReadActionParameters()
{

}

void UndoAction::Execute()
{

	pManager->UndoLastAction();

}