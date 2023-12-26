#include "DragAction.h"

DragAction::DragAction(ApplicationManager* pApp) : Action(pApp) {
	Recordable = true;
	UndoValidity = true;
}

void DragAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ToMove = pManager->IsSelected();

	if (ToMove != NULL) {
		lastLoaction = ToMove->getlocation();
		FigID = ToMove->GetID();
		pOut->PrintMessage("Drag figures tool is selected ");
		CanExecute = true;
	}

	else {
		pOut->PrintMessage("you must select a shape before using the Drag tool");
		CanExecute = false;
	}
}

void DragAction::Execute()
{
	Point  TheOld, MousePoint;

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	if (CanExecute) {

		bool start = false;
		bool buttonDown = false;
		bool Pointinside = false;

		do {
			buttonDown = (pIn->GetWindow()->GetButtonState(LEFT_BUTTON, MousePoint.x, MousePoint.y) == BUTTON_DOWN);
			Pointinside = (ToMove->PointBelong(MousePoint.x, MousePoint.y));
			start = buttonDown && Pointinside;


		} while (!start);
		TheOld.x = MousePoint.x - 1;
		TheOld.y = MousePoint.y - 1;

		while (pIn->GetWindow()->GetButtonState(LEFT_BUTTON, MousePoint.x, MousePoint.y) == buttonstate::BUTTON_DOWN) {


			ToMove->Drag(MousePoint, TheOld);

			TheOld.x = MousePoint.x;
			TheOld.y = MousePoint.y;

		pIn->GetWindow()->GetMouseCoord(MousePoint.x, MousePoint.y);
		//pIn->GetWindow()->SetBuffering(true);
		//pIn->GetWindow()->UpdateBuffer();
		pManager->UpdateInterface();
		}

		//pIn->GetWindow()->SetBuffering(false);
		pManager->UpdateInterface();
		pOut->PrintMessage("Figure moved successfully");
		NewLocation = MousePoint;
	}
}
void DragAction::undo()
{
	Output* pOut = pManager->GetOutput();
	if (CanExecute) {
		pOut->ClearDrawArea();
		pManager->GetFigure(FigID)->Move(lastLoaction);
		pOut->PrintMessage("the move figure action is undoed ");
	}
	else pOut->PrintMessage("you didn't select a figure to move so you can't undo the action ");
}

void DragAction::redo()
{
	Output* pOut = pManager->GetOutput();
	if (CanExecute) {
		pOut->ClearDrawArea();
		pManager->GetFigure(FigID)->Move(NewLocation);
		pOut->PrintMessage("the move figure action is redoed ");
	}
	else pOut->PrintMessage("you didn't select a figure to move so you can't redo the action ");
}
