#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = true;//making the action undoable
	Recordable = true;
}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	pIn->getValidDrawPoint(P2);

	RectGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	ID = pManager->AddFigure(R);
	R->SetId(ID);

}

void AddRectAction::undo()
{ 
	Output* pOut = pManager->GetOutput();
	pManager->DeleteFigure(ID);//in the undo of this acction we delete the figure
	pOut->PrintMessage("the add Rectangle action is undoed ");
}

void AddRectAction::redo()
{
	Output* pOut = pManager->GetOutput();
	CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);//in the redo of this action we return the rectangle with its info
	R->SetId(ID);//setting the id of the rectangle with its intial id
	pManager->AddFigure(R);//adding the rectangle to fig list
	pOut->PrintMessage("the add Rectangle action is redoed ");
}
