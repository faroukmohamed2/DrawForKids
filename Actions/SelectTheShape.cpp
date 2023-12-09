#include "SelectTheShape.h"
#include "../ApplicationManager.h"
#include "../DEFS.h"
#include <cstdlib>
#include <ctime>
SelectTheShape::SelectTheShape(ApplicationManager *pApp):Action(pApp)
{}
void SelectTheShape::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	srand(static_cast<unsigned int>(time(nullptr)));
	enum shapes { REC, TRI, SQU, CIRC, HEX, NUM };
	int randshape = rand() % NUM;

	switch (randshape)
	{
	case REC:
		pOut->PrintMessage("Select all Rectangles");
		break;
	case TRI:
		pOut->PrintMessage("Select all Triangles");
		break;
	case SQU:
		pOut->PrintMessage("Select all Squares");
		break;
	case CIRC:
		pOut->PrintMessage("Select all Circles");
		break;
	case HEX:
		pOut->PrintMessage("Select all Hexagons");
		break;
	}
	pIn->GetPointClicked(p.x, p.y);
	pIn->getValidDrawPoint(p);
}

void SelectTheShape::Execute()
{
	ReadActionParameters();
	CFigure *pick = pManager->GetFigure(p.x, p.y);
	int i = pManager->AddFigure(pick);
	int j = 0;
	while (pick)
	{
		ReadActionParameters();
		CFigure* pick = pManager->GetFigure(p.x, p.y);
		int i = pManager->AddFigure(pick);
		pick->ChngDrawClr(UI.BkGrndColor);
		pManager->UpdateInterface();

	}
}
