#include "SelectColorShape.h"
#include "SelectTheColor.h"
#include "../ApplicationManager.h"
#include "../DEFS.h"
#include <cstdlib>
#include "../Figures/CCircle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CHexa.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
SelectColorShape::SelectColorShape(ApplicationManager* pApp):Action(pApp)
{
	FigCount = pManager->GetFigCount();
	shapes = new CFigure * [FigCount];
	colors = new color[FigCount];
	CountValid = 0;
	TrueAns = 0;
	WrongAns = 0;
	col = new int[FigCount];
	sh = new int[FigCount];
	for (int i = 0; i < FigCount; i++)
	{
		shapes[i] = pManager->GetFigure(i);
		colors[i] = pManager->GetFigColor(i);
	}
	CountCols();
	Countsh();
	UndoValidity = false;//making the action non-undoable
}

void SelectColorShape::CountCols()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (colors[i] == RED)
			col[i] = RD;
		else if (colors[i] == BLUE)
			col[i] = BLU;
		else if (colors[i] == GREEN)
			col[i] = GRN;
		else if (colors[i] == ORANGE)
			col[i] = ORNGE;
		else if (colors[i] == BLACK)
			col[i] = BLCK;
		else if (colors[i] == YELLOW)
			col[i] = YLLOW;
		else
			col[i] = -1;
	}
}

void SelectColorShape::Countsh()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (dynamic_cast<CHexa*>(shapes[i]))
			sh[i] = HEX;
		else if (dynamic_cast<CSquare*>(shapes[i]))
			sh[i] = SQU;
		else if (dynamic_cast<CRectangle*>(shapes[i]))
			sh[i] = REC;
		else if (dynamic_cast<CCircle*>(shapes[i]))
			sh[i] = CIRC;
		else if (dynamic_cast<CTriangle*>(shapes[i]))
			sh[i] = TRI;

	}
}

void SelectColorShape::GetValidColShape()
{
	do
	{
		randindcol = rand() % FigCount;
		randindsh = rand() % FigCount;
	} while (randindcol != randindsh);
	randcol = col[randindcol];
	randshape = sh[randindsh];
	for (int i = 0; i < FigCount; i++)
	{
		if (randcol == col[i] && randshape == sh[i])
			CountValid++;
	}
}

void SelectColorShape::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	string outmsg;
	Input *pIn = pManager->GetInput();

	switch (randcol)
	{
	case RD:
		outmsg = "Select all Red ";
		break;
	case BLU:
		outmsg = "Select all Blue ";
		break;
	case BLCK:
		outmsg = "Select all Black ";
		break;
	case ORNGE:
		outmsg = "Select all Orange ";
		break;
	case YLLOW:
		outmsg = "Select all Yellow ";
		break;
	case GRN:
		outmsg = "Select All Green ";
		break;
	default:
		outmsg = "Select All Uncolored ";
	}
	switch (randshape)
	{
	case REC:
		pOut->PrintMessage(outmsg + "Rectangles");
		break;
	case TRI:
		pOut->PrintMessage(outmsg + "Triangles");
		break;
	case SQU:
		pOut->PrintMessage(outmsg + "Squares");
		break;
	case CIRC:
		pOut->PrintMessage(outmsg + "Circles");
		break;
	case HEX:
		pOut->PrintMessage(outmsg + "Hexagons");
		break;
	}
	pIn->GetPointClicked(p.x, p.y);

}

void SelectColorShape::Execute()
{
	int i = 0;
	CFigure** pick = new CFigure * [FigCount];
	Output* pOut = pManager->GetOutput();
	pManager->show();
	pManager->UpdateInterface();

	if (FigCount == 0)
		pOut->PrintMessage("Please Draw Some Colored Shapes");
	else
	{
		GetValidColShape();
		while (1)
		{
			ReadActionParameters();
			pick[i] = pManager->GetFigure(p.x, p.y);
			while (pick[i] == NULL)
			{
				if (EndExecute() > 0)
				{
					pOut->PrintMessage("True Answers: " + to_string(TrueAns) + " Wrong Answers: " + to_string(WrongAns));
					break;
				}
				ReadActionParameters();
				pick[i] = pManager->GetFigure(p.x, p.y);
			}

			if (EndExecute() > 0)
			{
				pOut->PrintMessage("True Answers: " + to_string(TrueAns) + " Wrong Answers: " + to_string(WrongAns));
				break;
			}

			if (pick[i])
			{
				pick[i]->SetHide(true);
				pManager->UpdateInterface();
			}
			if (col[pick[i]->GetId()] == randcol && sh[pick[i]->GetId()] == randshape)
			{
				TrueAns++;
				CountValid--;
			}
			else
				WrongAns++;
			if (CountValid == 0)
			{
				pOut->PrintMessage("True Answers: " + to_string(TrueAns) + " Wrong Answers: " + to_string(WrongAns));
				break;
			}
		}
		delete pick;
	}
}
int SelectColorShape::EndExecute()
{

	if (p.y < UI.ToolBarHeight)
	{
		if (p.x < (UI.width - UI.MenuItemWidth * 2) && p.x >(UI.width - UI.MenuItemWidth * 2 * 2))
			return TO_DRAW;
		if (p.x > UI.MenuItemWidth * 9 && p.x < UI.MenuItemWidth * 11)
			return RESET;
		if (p.x > 0 && p.x < UI.MenuItemWidth * 2)
			return FIG_TYP;
		if (p.x > UI.MenuItemWidth * 3 && p.x < UI.MenuItemWidth * 5)
			return FIG_COL;
		return -1;
	}
	return -1;
}

SelectColorShape::~SelectColorShape()
{
	delete shapes;
	delete colors;
	delete col;
	delete sh;
}
