#include "ChangeToPLayModeAction.h"
#include "../ApplicationManager.h"
#include "Action.h"
#include "../DEFS.h"
ChangeToPlayModeAction::ChangeToPlayModeAction(ApplicationManager* pApp) :Action(pApp)
{}
void ChangeToPlayModeAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Change to Play Mode");
	pOut->ClearStatusBar();

}
void ChangeToPlayModeAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	if (pOut != NULL)
		pOut->CreatePlayToolBar();
}
