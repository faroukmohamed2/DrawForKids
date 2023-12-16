
#include "DeleteFigAction.h"
#include"AddRectAction.h"
#include "..\Figures\CRectangle.h"
DeleteFigAction::DeleteFigAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = true;
}

void DeleteFigAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ToDelete = pManager->IsSelected();
	Refrence = ToDelete;
	if (ToDelete != NULL) {

		pOut->PrintMessage("The figure is deleted succefully");
		CanExecute = true;
	}
	
	else {
		pOut->PrintMessage("you must select a shape before using the fill bucket");
		CanExecute = false;
	}
	
}


void DeleteFigAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	ToDelete->SetSelected(false);
	
	//ToDelete->Delete(pOut);
	pManager->DeleteFigure(ToDelete->GetID());
	SetActionState(true);
}

void DeleteFigAction::undo()
{
	Output* pOut = pManager->GetOutput();
	pManager->AddFigure(Refrence);
	SetActionState(false);
}

void DeleteFigAction::redo()
{
	ToDelete->SetSelected(false);

	//ToDelete->Delete(pOut);
	pManager->DeleteFigure(ToDelete->GetID());
	SetActionState(true);
}