#include "ChangeFillAction.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



ChangeFillAction::ChangeFillAction(ApplicationManager* pApp, ActionType ChngStyle) :Action(pApp)
{
	if (ChngStyle == Fill_Tool)
		ReqStyle = Fill;

	else if (ChngStyle == Pencile_Tool)
		ReqStyle = Border;
}

void ChangeFillAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ToChange = pManager->IsSelected();
	if (ToChange != NULL) {

		if (ReqStyle == Fill)
			pOut->PrintMessage("changing the fill color of the selected shape, please choose a color");
		else if (ReqStyle == Border)
			pOut->PrintMessage("changing the Border color of the selected shape, please choose a color");

		ActionType UserAction;

		do {
			UserAction = pIn->GetUserAction();
		} while (!(UserAction >= DRW_Red && UserAction <= DRW_Black));

		switch (UserAction)
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


		if (ReqStyle == Fill)
			pOut->PrintMessage("Changed the fill color to:" + ColorName);

		else if (ReqStyle == Border)
			pOut->PrintMessage("Changed the Border color to:" + ColorName);


	}


	else {
		pOut->PrintMessage("you must select a shape before using the fill bucket");
		CanExecute = false;
	}
}

void ChangeFillAction::Execute()
{
	ReadActionParameters();

	if (CanExecute) {

		if (ReqStyle == Fill) {
			ToChange->ChngFillClr(SelectedColor);
			ToChange->SetSelected(!(ToChange->IsSelected()));
			UI.FillColor = SelectedColor;
		}
		else if (ReqStyle == Border) {
			ToChange->ChngDrawClr(SelectedColor);
			ToChange->SetSelected(!(ToChange->IsSelected()));
			//UI.FillColor = SelectedColor;

		}


	}
}
