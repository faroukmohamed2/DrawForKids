#include"Action.h"
#include"ClearAllAction.h"
#include "..\ApplicationManager.h"

ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false;
}

void ClearAllAction::ReadActionParameters()
{

}

void ClearAllAction::Execute()
{

	pManager->ClearAll();

}
