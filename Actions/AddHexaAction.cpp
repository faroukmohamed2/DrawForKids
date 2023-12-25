#include "AddHexaAction.h"
#include "..\Figures\CHexa.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp)
{
	Recordable = true;
}

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at The Center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);

	

	HexaGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexaAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user
	CHexa* R = new CHexa(P1, HexaGfxInfo);

	//Add the rectangle to the list of figures
	ID = pManager->AddFigure(R);
	R->SetId(ID);
	
}

void AddHexaAction::undo()
{
	Output* pOut = pManager->GetOutput();
	pManager->DeleteFigure(ID);
	pOut->PrintMessage("the add hexagon action is undoed ");
}

void AddHexaAction::redo()
{
	Output* pOut = pManager->GetOutput();
	CHexa* R = new CHexa(P1, HexaGfxInfo);
	R->SetId(ID);
	pManager->AddFigure(R);
	pOut->PrintMessage("the add Hexagon action is redoed ");
}