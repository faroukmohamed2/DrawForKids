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
	CircCount = 0;
	SquCount = 0;
	HexCount = 0;
	TriCount = 0;
	RecCount = 0;
	FigCount = 0;
	CircCount += CCircle::GetCircCount();
	SquCount += CSquare::GetSquCount();
	HexCount += CHexa::GetHexCount();
	TriCount += CTriangle::GetTriCount();
	RecCount += CRectangle::GetRecCount();
	FigCount += pManager->GetFigCount();

}

bool SelectTheShape::IsExist(int shape)
{
	if (shape == 0)
		return false;
	else
		return true;
}
int SelectTheShape::GetValidShape()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int randshape = rand() % NUM;
	bool test = true;
	while (test)
	{
		if (IsExist(SquCount) && randshape == SQU)
		{
			test = false;
		}
		else
		{
			while (randshape == SQU)
			{
				randshape = rand() % NUM;
			}
		}

		if (IsExist(RecCount) && randshape == REC)
		{
			test = false;
		}
		else
		{
			while (randshape == REC)
			{
				randshape = rand() % NUM;
			}
		}
		if (IsExist(TriCount) && randshape == TRI)
		{
			test = false;
		}
		else
		{
			while (randshape == TRI)
			{
				randshape = rand() % NUM;
			}
		}
		if (IsExist(CircCount) && randshape == CIRC)
		{
			test = false;
		}
		else
		{
			while (randshape == CIRC)
			{
				randshape = rand() % NUM;
			}
		}
		if (IsExist(HexCount) && randshape == HEX)
		{
			test = false;
		}
		else
		{
			while (randshape == HEX)
			{
				randshape = rand() % NUM;
			}
		}
	}
		return randshape;
}

void SelectTheShape::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (FigCount == 0)
		pOut->PrintMessage("Please Draw Some Shapes");
	else
	{
		int randshape = GetValidShape();
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
	ReadActionParameters();
	CFigure* pick = pManager->GetFigure(p.x, p.y);
}
