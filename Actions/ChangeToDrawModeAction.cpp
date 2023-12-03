#include "ChangeToDrawModeAction.h"
#include "../ApplicationManager.h"
#include "Action.h"
#include "../DEFS.h"

ChangeToDrawModeAction::ChangeToDrawModeAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ChangeToDrawModeAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();

}

void ChangeToDrawModeAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (pOut != NULL)
	{
		pOut->CreateDrawToolBar();
		pOut->PrintMessage("change to draw mode");
		pOut->ClearStatusBar();
	}
	pOut = NULL;
}

