#include "SelectTheShape.h"
#include "../ApplicationManager.h"
#include "../DEFS.h"
#include <cstdlib>
#include <ctime>
#include "../Figures/CCircle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CHexa.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
using namespace std;
SelectTheShape::SelectTheShape(ApplicationManager *pApp):Action(pApp)
{

	CircCount = CCircle::GetCircCount();
	SquCount = CSquare::GetSquCount();
	HexCount = CHexa::GetHexCount();
	TriCount = CTriangle::GetTriCount();
	RecCount = CRectangle::GetRecCount();
	FigCount = pManager->GetFigCount();

}

int SelectTheShape::NotExist(int rand)
{
	if (rand == SQU && SquCount == 0)
		return SQU;
	if (rand == REC && RecCount == 0)
		return REC;
	if (rand == CIRC && CircCount == 0)
		return CIRC;
	if (rand == TRI && TriCount == 0)
		return TRI;
	if (rand == HEX && HexCount == 0)
		return HEX;
}
void SelectTheShape::GetValidShape()
{
	do
	{
		randshape = rand() % NUM;
	} while (randshape == NotExist(randshape));

}

void SelectTheShape::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	if (FigCount != 0)
	{
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

	}

}

void SelectTheShape::Execute()
{
	int TrueAns = 0, WrongAns = 0;
	CFigure** pick = new CFigure * [FigCount];
	Output* pOut = pManager->GetOutput();
	if (FigCount == 0)
		pOut->PrintMessage("Please Draw Some Shapes");
	else
	{
		GetValidShape();
		for (int i = 0; i < FigCount; i++)
		{
			ReadActionParameters();
			pick[i] = pManager->GetFigure(p.x, p.y);
			if (EndExecute() == TO_DRAW)
			{
				pManager->ExecuteAction(TO_DRAW);
				break;
			}
			else if (EndExecute() == RESET)
			{
				pManager->ExecuteAction(RESET);
				break;
			}
			while (pick[i] == NULL)
			{
				ReadActionParameters();
				pick[i] = pManager->GetFigure(p.x, p.y);
			}
			if (pick[i])
			{
				pick[i]->ChngDrawClr(UI.BkGrndColor);
				if (pick[i]->IsFilled())
					pick[i]->ChngFillClr(UI.BkGrndColor);
			}
			pManager->UpdateInterface();
			if (dynamic_cast<CRectangle*>(pick[i]) && randshape == REC)
			{
				TrueAns++;
				RecCount--;
			}
			else if (dynamic_cast<CTriangle*>(pick[i]) && randshape == TRI)
			{
				TrueAns++;
				TriCount--;
			}
			else if (dynamic_cast<CCircle*>(pick[i]) && randshape == CIRC)
			{
				TrueAns++;
				CircCount--;
			}
			else if (dynamic_cast<CHexa*>(pick[i]) && randshape == HEX)
			{
				TrueAns++;
				HexCount--;
			}
			else if (dynamic_cast<CSquare*>(pick[i]) && randshape == SQU)
			{
				TrueAns++;
				SquCount--;
			}
			else
				WrongAns++;


			if (randshape == NotExist(randshape))
			{

				pOut->PrintMessage("True Answers: " + to_string(TrueAns) + " Wrong Answers: " + to_string(WrongAns));
				break;
			}

		}
	}
}



ActionType SelectTheShape::EndExecute()
{

	if (p.y < UI.ToolBarHeight)
	{
		if (p.x < (UI.width - UI.MenuItemWidth * 2) && p.x >(UI.width - UI.MenuItemWidth * 2 * 2))
			return TO_DRAW;
		if (p.x > UI.MenuItemWidth * 9 && p.x < UI.MenuItemWidth * 11)
			return RESET;
	}
}