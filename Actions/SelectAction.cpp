 #include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include "SelectAction.h"

SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{
	UndoValidity = false;//making the action non-undoable
	Recordable = true;
}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetFigCount() != 0) {
		CanExecute = true;
		pOut->PrintMessage("Selection Tool : Please select the desired Shape");

		pIn->GetPointClicked(P1.x, P1.y);
		pIn->getValidDrawPoint(P1);


		pOut->ClearStatusBar();

	}
	else {
		pOut->PrintMessage("You must draw shapes first to use the Selection Tool");
		CanExecute = false;
	}
}

void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	if (CanExecute) {
		CFigure* OldSelected = pManager->IsSelected();
		if (OldSelected != NULL)
			OldSelected->SetSelected(false);


		CFigure* TheSelected = pManager->GetFigure(P1.x, P1.y);
		while (TheSelected == NULL) {
			ReadActionParameters();
			TheSelected = pManager->GetFigure(P1.x, P1.y);
		}
		if (OldSelected != TheSelected) {
			TheSelected->SetSelected(!(TheSelected->IsSelected()));
			TheSelected->PrintInfo(pOut);
		}
		selectedFigure = TheSelected;
		TheSelected = NULL;
		OldSelected = NULL;
	}
} 

void SelectAction::redo() {
	if (selectedFigure) {
		selectedFigure->ChngDrawClr(MAGENTA);
		selectedFigure->SetSelected(selectedFigure->IsSelected());
	}
}
