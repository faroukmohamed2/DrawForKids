#include "AddHexaAction.h"
#include "..\Figures\CHexa.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include<Windows.h>

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = true;//making the action undoable
	Recordable = true;
}

void AddHexaAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetSoundState())
	{
		PlaySound("Hexagon.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	pOut->PrintMessage("New Hexagon: Click at The Center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pIn->getValidDrawPoint(P1);

	

	HexaGfxInfo.isFilled = pOut->getCrntFillState();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexaAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	//This action needs to read some parameters first
	ReadActionParameters();

	
	CHexa* R = new CHexa(P1, HexaGfxInfo);

	//Add the rectangle to the list of figures
	ID = pManager->AddFigure(R);
	R->SetId(ID);
	pOut->ClearMsgHistory();

}

void AddHexaAction::undo()
{
	Output* pOut = pManager->GetOutput();
	pManager->DeleteFigure(ID);//in the undo of this acction we delete the figure
	pOut->PrintMessage("the add hexagon action is undoed ");
}

void AddHexaAction::redo()
{
	Output* pOut = pManager->GetOutput();
	CHexa* R = new CHexa(P1, HexaGfxInfo);//in the redo of this action we return the hexagon with its info
	R->SetId(ID);                         //setting the id of the hexagon with its intial id
	pManager->AddFigure(R);//adding the hexagon to the fig list
	pOut->PrintMessage("the add Hexagon action is redoed ");
}