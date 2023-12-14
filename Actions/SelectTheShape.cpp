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
int SelectTheShape::GetValidShape()
{
	int randshape;
	do
	{
		randshape = rand() % NUM;
	} while (randshape == NotExist(randshape));

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
