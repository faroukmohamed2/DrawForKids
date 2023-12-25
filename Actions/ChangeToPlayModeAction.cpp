#include "ChangeToPLayModeAction.h"
#include "../ApplicationManager.h"
#include "Action.h"
#include "../DEFS.h"
ChangeToPlayModeAction::ChangeToPlayModeAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false;//making the action non-undoable
}
void ChangeToPlayModeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Changed to Play Mode");
}
void ChangeToPlayModeAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (pOut != NULL)
		pOut->CreatePlayToolBar();
}
