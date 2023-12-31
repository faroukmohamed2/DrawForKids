#include "ChangeFillAction.h"



#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



ChangeFillAction::ChangeFillAction(ApplicationManager* pApp, ActionType ChngStyle) :Action(pApp)
{
	Recordable = true;

	if (ChngStyle == Fill_Tool)
		ReqStyle = Fill;

	else if (ChngStyle == Pencile_Tool)
		ReqStyle = Border;

	UndoValidity = true;//making the action undoable
}

void ChangeFillAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ToChange = pManager->IsSelected();
	

	if (ToChange != NULL) {
		FGindex = pManager->IsSelected()->GetID();
		lastFillstate = ToChange->getfillstate();
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
		if (ReqStyle == Fill)
		pOut->PrintMessage("you must select a shape before using the fill bucket");
		else
		pOut->PrintMessage("you must select a shape before using the Pencil Tool");

		CanExecute = false;
	}
}

void ChangeFillAction::Execute()
{
	ReadActionParameters();

	if (CanExecute) {

		if (ReqStyle == Fill) {
			lastSelected = pManager->GetFigure(FGindex)->GetFigColor();
			pManager->GetFigure(FGindex)->ChngFillClr(SelectedColor);
			//pManager->GetFigure(FGindex)->SetSelected(!(pManager->GetFigure(FGindex)->IsSelected()));
			UI.FillColor = SelectedColor;
			UI.FillState = true;
		}
		else if (ReqStyle == Border) {
			lastSelected = pManager->GetFigure(FGindex)->GetborderColor();
			pManager->GetFigure(FGindex)->ChngDrawClr(SelectedColor);
			//pManager->GetFigure(FGindex)->SetSelected(!(pManager->GetFigure(FGindex)->IsSelected()));
			UI.DrawColor = SelectedColor;

		}
	}
	
}

void ChangeFillAction::undo()
{
	Output* pOut = pManager->GetOutput();
	if (CanExecute) {//if there was a figure to chang its color
		if (ReqStyle == Fill) {//if we changed the fill color
			CurrentState = UI.FillState;
			UI.FillState = lastFillstate;
			if (lastFillstate)//checking that the figure was filled or not before excuting the change color action
			{

				pManager->GetFigure(FGindex)->ChngFillClr(lastSelected);//return it to the last fill color before changing it
				pOut->PrintMessage("the change fill color of the figure action is undoed ");
				UI.FillColor = lastSelected;
				
			}
			else pManager->GetFigure(FGindex)->setfillstate(false);//retrun it to non filled if it is not filled before changing the fill color
		
		}
		else if (ReqStyle == Border) {//if we changed the border color
			pManager->GetFigure(FGindex)->ChngDrawClr(lastSelected);//return it to last border color before changing
			pOut->PrintMessage("the change border color of the figure action is undoed ");

		}
	}
	
}

void ChangeFillAction::redo()
{
	Output* pOut = pManager->GetOutput();
	if (CanExecute) {
		if (ReqStyle == Fill) {//in case of fill changing
			UI.FillState = CurrentState;
			pManager->GetFigure(FGindex)->ChngFillClr(SelectedColor);//redo the action and return the color to the selected one
			pOut->PrintMessage("the change fill color of the figure action is redoed ");
			
		}
		else if (ReqStyle == Border) {//in case of border changing

			pManager->GetFigure(FGindex)->ChngDrawClr(SelectedColor);//redo the action and return the color to the selected one
			pOut->PrintMessage("the change border color of the figure action is redoed ");
		}pManager->GetFigure(FGindex)->SetSelected(false);
	}
	
	
}
