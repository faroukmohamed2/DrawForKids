#include "ChangeToPLayModeAction.h"
#include "../ApplicationManager.h"
#include "Action.h"
#include "../DEFS.h"
ChangeToPlayModeAction::ChangeToPlayModeAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false;
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
