#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager * pApp):Action(pApp)
{
	UndoValidity = true;
}

void AddCircleAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the center");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);
	
	pOut->PrintMessage("New Circle: Click at The Desired Radius");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->getValidDrawPoint(P2);

	CircleGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CCircle*R=new CCircle(P1, P2, CircleGfxInfo);

	//Add the rectangle to the list of figures
	ID = pManager->AddFigure(R);
	R->SetId(ID);
	SetActionState(true);
}

void AddCircleAction::undo()
{
	pManager->DeleteFigure(ID);
	SetActionState(false);
}

void AddCircleAction::redo()
{
	CCircle* R = new CCircle(P1, P2, CircleGfxInfo);


	ID = pManager->AddFigure(R);
	R->SetId(ID);
	SetActionState(true);
}