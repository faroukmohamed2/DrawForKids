#include "DeleteFigAction.h"

DeleteFigAction::DeleteFigAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = true;//making the action undoable
	Recordable = true;
}

void DeleteFigAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ToDelete = pManager->IsSelected();
	
	if (ToDelete != NULL) {
		copy = ToDelete->clone();
		FigID=pManager->IsSelected()->GetID();
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
		pManager->DeleteFigure(ToDelete->GetID());
	}

}

void DeleteFigAction::undo()
{
	Output* pOut = pManager->GetOutput();
	if (CanExecute) {//if there was a selected figure to delete 
		
		//copy->SetHide(false);
		CFigure* newFig = copy->clone();
		pManager->AddFigure(newFig);//returned the figure to the fig list
		newFig->SetId(FigID);
		newFig->SetSelected(false);
		pOut->PrintMessage("the delete figure action is undoed ");
	}
	else pOut->PrintMessage("you didn't select a figure to delete so you can't undo the action ");//in case we press the undo without selecting a figure

}

void DeleteFigAction::redo()
{
	Output* pOut = pManager->GetOutput();
	if (CanExecute) {//if there was a selected figure to delete
		//copy->SetHide(true);
		pManager->DeleteFigure(FigID);//redoing the action and deleting the figure

		
		pOut->PrintMessage("the delete figure action is redoed ");
	}
	else pOut->PrintMessage("you didn't select a figure to delete so you can't redo the action ");//in case we press the undo without selecting a figure
}

DeleteFigAction::~DeleteFigAction()
{
	/*if(copy)
		delete copy;
	copy = NULL;*/
}
