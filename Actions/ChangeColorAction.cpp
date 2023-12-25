#include "ChangeColorAction.h"

#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"








ChangeColorAction::ChangeColorAction(ApplicationManager* pApp, ActionType TheColor) :Action(pApp)
{
	Recordable = true;
   UndoValidity = true; //making the action undoable
	switch (TheColor)
	{
	case DRW_Red:
		SelectedColor = RED;
		ColorName = "Red";
		break;
	case DRW_Orange:
		SelectedColor = ORANGE;
		ColorName = "Orange";
		break;
	case DRW_Blue:
		SelectedColor = BLUE;
		ColorName = "Blue";
		break;
	case DRW_Yellow:
		SelectedColor = YELLOW;
		ColorName = "Yellow";
		break;
	case DRW_Green:
		SelectedColor = GREEN;
		ColorName = "Green";
		break;
	case DRW_Black:
		SelectedColor = BLACK;
		ColorName = "Black";
		break;
	default:
		break;
	}
	
}

void ChangeColorAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	pOut->PrintMessage("Change the default drawing color to: " + ColorName);

}



void ChangeColorAction::Execute()
{
	ReadActionParameters();
	lastColor = UI.DrawColor;//assigning the lastcolor by the user interface current color before the changing
	UI.DrawColor = SelectedColor;
	
}

void ChangeColorAction::undo()
{
	Output* pOut = pManager->GetOutput();
	UI.DrawColor = lastColor;//return the default color to the last color before the changing
	pOut->PrintMessage("the default color changing action is undoed");
}
void ChangeColorAction::redo()
{
	Output* pOut = pManager->GetOutput();
	lastColor = UI.DrawColor;
	UI.DrawColor = SelectedColor;//redo the action and make the default color to the selected one
	pOut->PrintMessage("the default color changing action is redoed");
}