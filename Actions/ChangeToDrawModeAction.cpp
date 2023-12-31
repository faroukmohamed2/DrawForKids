#include "ChangeToDrawModeAction.h"
#include "../ApplicationManager.h"
#include "Action.h"
#include "../DEFS.h"

ChangeToDrawModeAction::ChangeToDrawModeAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false;//making the action non-undoable
}

void ChangeToDrawModeAction::ReadActionParameters()
{
     Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Changed to Draw mode");
}

void ChangeToDrawModeAction::Execute()
{
	ReadActionParameters();
	const Output* pOut = pManager->GetOutput();
	if (pOut != NULL)
	{
		pOut->CreateDrawToolBar();
		pManager->show();
	}

}



