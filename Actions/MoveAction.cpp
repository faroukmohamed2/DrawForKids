#include "MoveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CCircle.h"

MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = true;//making the action undoable
	Recordable = true;
}

void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ToMove = pManager->IsSelected();
	
	if (ToMove != NULL) {
		lastLoaction = ToMove->getlocation();
		FigID = ToMove->GetID();
		pOut->PrintMessage("Move figures tool is selected , please select the new location");
		CanExecute = true;

		pIn->GetPointClicked(NewLocation.x, NewLocation.y);
		pIn->getValidDrawPoint(NewLocation);
		
		pOut->PrintMessage("Figure moved successfully");


	}

	else {
		pOut->PrintMessage("you must select a shape before using the move tool");
		CanExecute = false;
	}
}

void MoveAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters(); 
	if (CanExecute) {
		ToMove->SetSelected(false);
		pOut->ClearDrawArea();
		ToMove->Move(NewLocation);
	}
}

void MoveAction::undo()
{
	Output* pOut = pManager->GetOutput();
	if (CanExecute) {//if there was a selected figure to move
		pOut->ClearDrawArea();
		pManager->GetFigure(FigID)->Move(lastLoaction);//in the undo action we return the figure to its previous location
		pOut->PrintMessage("the move figure action is undoed ");
	}
   
}

void MoveAction::redo()
{
	Output* pOut = pManager->GetOutput();
	if (CanExecute) {//if there was a selected figure to move
		pOut->ClearDrawArea();
		pManager->GetFigure(FigID)->Move(NewLocation);//in the redo action we return the figure to its last location
		pOut->PrintMessage("the move figure action is redoed ");
	}
	
}
