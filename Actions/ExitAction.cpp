#include"Action.h"
#include"ExitAction.h"
#include "..\ApplicationManager.h"

ExitAction::ExitAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false;//making the action non-undoable
}

void ExitAction::ReadActionParameters()
{

}

void ExitAction::Execute()
{

	pManager->ClearAll();//clearing the figlist and the action list of the last 5 actions 
	pManager->ClearRecordingHistory();//clearing the record history
}
