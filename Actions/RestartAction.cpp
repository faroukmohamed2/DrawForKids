#include "RestartAction.h"
#include "../ApplicationManager.h"
Restart::Restart(ApplicationManager* pApp):Action(pApp)
{
	UndoValidity = false;//making the action non-undoable
}

void Restart::ReadActionParameters()
{
}

void Restart::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Restart The Game");
	pManager->show();
}

