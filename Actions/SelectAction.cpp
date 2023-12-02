 #include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include "SelectAction.h"

SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{

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
	ReadActionParameters();
	CFigure* TheSelected = pManager->GetFigure(P1.x, P1.y);
	while (TheSelected == NULL) {
		ReadActionParameters();
		TheSelected = pManager->GetFigure(P1.x, P1.y);
	}
	if (TheSelected != NULL)
	TheSelected->SetSelected(!(TheSelected->IsSelected()));
	
	TheSelected = NULL;

} 
