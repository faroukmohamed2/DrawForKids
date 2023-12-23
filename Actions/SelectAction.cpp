 #include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include "SelectAction.h"

SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{
	UndoValidity = false;
	Recordable = true;
}

void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Selection Tool : Please select the desired Shape");

	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);


	pOut->ClearStatusBar();




}

void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

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

	TheSelected = NULL;
	OldSelected = NULL;
	

	

} 
