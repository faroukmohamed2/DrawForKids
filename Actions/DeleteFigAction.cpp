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
	
	if (ToDelete != NULL) {

		pOut->PrintMessage("The figure is deleted succefully");
		FigID = ToDelete->GetId();
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
	if (CanExecute) {
		
		ToDelete->SetHide(false);
		pManager->AddFigure(ToDelete);
		pOut->PrintMessage("the delete figure action is undoed ");
	}
	else pOut->PrintMessage("you didn't select a figure to delete so you can't undo the action ");

}

void DeleteFigAction::redo()
{
	Output* pOut = pManager->GetOutput();
	if (CanExecute) {
		ToDelete->SetHide(true);
		//Refrence->Delete(pOut);
		pManager->DeleteFigure(FigID);
		pOut->PrintMessage("the delete figure action is redoed ");
	}
	else pOut->PrintMessage("you didn't select a figure to delete so you can't redo the action ");
}

DeleteFigAction::~DeleteFigAction()
{
	delete ToDelete;
}
