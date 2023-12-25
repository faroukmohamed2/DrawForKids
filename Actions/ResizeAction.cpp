#include "ResizeAction.h"
#include <cmath>
#include <limits>
#include <iostream>

ResizeAction::ResizeAction(ApplicationManager* pApp) : Action(pApp) {};
void ResizeAction::ReadActionParameters() {
	Input* input = pManager->GetInput();
	Output* output = pManager->GetOutput();

	//Get slected figure and read its id
	CFigure* figure = pManager->IsSelected();
	if (!figure) {
		output->PrintMessage("Resize tool: Select figure first.");
		return;
	}
	figId = figure->GetID();

	//Draw a circle on every resizable point
	int pointCount;
	Point** points = figure->GetResizablePointsAsArray(pointCount);

	for (int i = 0; i < pointCount; i++) {
		Point secondPoint = *points[i];
		secondPoint.x += 10;
		GfxInfo info;
		info.FillClr = GREY;
		info.isFilled = true;
		output->DrawCircle(*points[i], secondPoint, info, false);
	}

	//Wait for mouse down to start dragging
	Point mousePoint;
	while (input->GetWindow()->GetButtonState(LEFT_BUTTON, mousePoint.x, mousePoint.y) == buttonstate::BUTTON_UP) {}

	//Find nearest resizable point to the mouse
	int nearestPoint = 0;
	int minDistance = INT_MAX;
	for (int i = 0; i < pointCount; i++) {
		int dis = sqrt(pow(points[i]->x - mousePoint.x, 2) + pow(points[i]->y - mousePoint.y, 2));
		if (dis < minDistance) {
			nearestPoint = i;
			minDistance = dis;
		}
	}
	pointIndexToMove = nearestPoint;
	StartPoint = *points[pointIndexToMove];

	//Claculate dragging offset
	Point offset;
	offset.x = mousePoint.x - points[pointIndexToMove]->x;
	offset.y = mousePoint.y - points[pointIndexToMove]->y;

	//Dragging
	while (input->GetWindow()->GetButtonState(LEFT_BUTTON, mousePoint.x, mousePoint.y) == BUTTON_DOWN) {
		input->GetWindow()->GetMouseCoord(mousePoint.x, mousePoint.y);
		mousePoint.x -= offset.x;
		mousePoint.y -= offset.y;
		figure->SetResizablePointAtIndex(pointIndexToMove, mousePoint);
		pManager->UpdateInterface();
		Sleep(10);
	}



	if (pointCount > 0) {
		input->GetPointClicked(mousePoint.x, mousePoint.y);

		mousePoint.x -= offset.x;
		mousePoint.y -= offset.y;

		EndPoint = mousePoint;

		pManager->UpdateInterface();
	}
}
void ResizeAction::Execute(){
	ReadActionParameters();
	
	CFigure* figure = pManager->GetFigure(figId);
	if (figure) {
		figure->SetResizablePointAtIndex(pointIndexToMove, EndPoint);
	}

}
void ResizeAction::undo() {
	CFigure* figure = pManager->GetFigure(figId);
	if (figure) {
		figure->SetResizablePointAtIndex(pointIndexToMove, StartPoint);
	}
}

void ResizeAction::redo() {
	CFigure* figure = pManager->GetFigure(figId);
	if (figure) {
		figure->SetResizablePointAtIndex(pointIndexToMove, EndPoint);
	}
}
