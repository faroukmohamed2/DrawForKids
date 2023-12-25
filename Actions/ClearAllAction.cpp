#include"Action.h"
#include"ClearAllAction.h"
#include "..\ApplicationManager.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false;//making the action non-undoable
}

void ClearAllAction::ReadActionParameters()
{

}

void ClearAllAction::Execute()
{

	pManager->ClearAll();
	pManager->ClearRecordingHistory();

}
