#include "AddSquareAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSquareAction::AddSquareAction(ApplicationManager* pApp):Action (pApp)
{
	UndoValidity = true;
	Recordable = true;
}

void AddSquareAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at the center of the square");

	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);

	SquareGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SquareGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

void AddSquareAction::Execute()
{
	ReadActionParameters();
	/////////
	CSquare* R = new CSquare(P1, SquareGfxInfo);

	//Add the rectangle to the list of figures
	ID = pManager->AddFigure(R);
	R->SetId(ID);
}

void AddSquareAction::undo()
{
	Output* pOut = pManager->GetOutput();
	pManager->DeleteFigure(ID);
	pOut->PrintMessage("the add Square action is undoed ");
}

void AddSquareAction::redo()
{
	Output* pOut = pManager->GetOutput();
	CSquare* R = new CSquare(P1, SquareGfxInfo);
	R->SetId(ID);
	pManager->AddFigure(R);
	pOut->PrintMessage("the add Square action is redoed ");
}