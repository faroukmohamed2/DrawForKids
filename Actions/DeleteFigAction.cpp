#include "DeleteFigAction.h"

DeleteFigAction::DeleteFigAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = true;
	Recordable = true;
}

void DeleteFigAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ToDelete = pManager->IsSelected();
	Refrence = ToDelete;
	FigID = ToDelete->GetId();
	if (ToDelete != NULL) {

		pOut->PrintMessage("The figure is deleted succefully");
		CanExecute = true;
	}

	else {
		pOut->PrintMessage("you must select a shape before using the delete action");
		CanExecute = false;
	}
}

void DeleteFigAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (CanExecute) {
		ToDelete->SetSelected(false);
		//ToDelete->Delete(pOut);
		pManager->DeleteFigure(ToDelete->GetID());
	}

}

void DeleteFigAction::undo()
{
	Output* pOut = pManager->GetOutput();
	Refrence->SetHide(false);
	pManager->AddFigure(Refrence);
	
}

void DeleteFigAction::redo()
{
	Output* pOut = pManager->GetOutput();
	Refrence->SetHide(true);
	//Refrence->Delete(pOut);
	pManager->DeleteFigure(FigID);
}
