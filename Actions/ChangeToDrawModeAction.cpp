#include "ChangeToDrawModeAction.h"
#include "../ApplicationManager.h"
#include "Action.h"
#include "../DEFS.h"

ChangeToDrawModeAction::ChangeToDrawModeAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ChangeToDrawModeAction::ReadActionParameters()
{
	const Output* pOut = pManager->GetOutput();
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

