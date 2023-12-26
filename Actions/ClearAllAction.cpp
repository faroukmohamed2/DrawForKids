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
	Output* pOut=pManager->GetOutput();
	pManager->ClearAll();//calling the clear all function that it clear the undo history and the figlist and reset the variables
	pManager->ClearRecordingHistory();//calling the clear record history that reset the recorded actions array
	// we seperate the two functions to use the clearall only in the record action
	pOut->PrintMessage("you clear all figures");
}
