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

}

void RedoAction::Execute()
{

	pManager->RedoLastAction();

}