#include "SelectTheColor.h"
#include "../ApplicationManager.h"
#include "../DEFS.h"
#include <cstdlib>
#include "../Figures/CCircle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CHexa.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CTriangle.h"
SelectTheColor::SelectTheColor(ApplicationManager* pApp): Action(pApp)
{
	reds = 0;
	blues = 0;
	yellows = 0;
	greens = 0;
	oranges = 0;
	blacks = 0;
	uncol = 0; 
	WrongAns = 0;
	TrueAns = 0;
	FigCount = pManager->GetFigCount();
	CountColors();
	UndoValidity = false;
}
void SelectTheColor::CountColors()
{
	colors = new color[FigCount];
	for (int i = 0; i < FigCount; i++)
		colors[i] = pManager->GetFigColor(i);
	for (int i = 0; i < FigCount; i++)
	{
		if (colors[i] == RED)
			reds++;
		else if (colors[i] == YELLOW)
			yellows++;
		else if (colors[i] == ORANGE)
			oranges++;
		else if (colors[i] == BLACK)
			blacks++;
		else if (colors[i] == GREEN)
			greens++;
		else if (colors[i] == BLUE)
			blues++;
		else
			uncol++;
	}

}
int SelectTheColor::GetValidColor()
{
	do
	{
		randcol = rand() % NUM;
	} while (randcol == NotExist(randcol));
	return randcol;
}

int SelectTheColor::NotExist(int rand)
{
	if (rand == RD && reds == 0)
		return RD;
	if (rand == BLU && blues == 0)
		return BLU;
	if (rand == GRN && greens == 0)
		return GRN;
	if (rand == BLCK && blacks == 0)
		return BLCK;
	if (rand == YLLOW && yellows == 0)
		return YLLOW;
	if (rand == ORNGE && oranges == 0)
		return ORNGE;
}

void SelectTheColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	if (FigCount != 0)
	{
		switch (randcol)
		{
		case RD:
			pOut->PrintMessage("Select all Red Shapes");
			break;
		case BLU:
			pOut->PrintMessage("Select all Blue Shapes");
			break;
		case BLCK:
			pOut->PrintMessage("Select all Black Shapes");
			break;
		case ORNGE:
			pOut->PrintMessage("Select all Orange Shapes");
			break;
		case YLLOW:
			pOut->PrintMessage("Select all Yellow Shapes");
			break;
		case GRN:
			pOut->PrintMessage("Select All Green Shapes");
			break;
		}
		pIn->GetPointClicked(p.x, p.y);

	}
}




void SelectTheColor::Execute()
{
	int i = 0;
	CFigure** pick = new CFigure * [FigCount];
	Output* pOut = pManager->GetOutput();
	pManager->show();
	pManager->UpdateInterface();

	if (FigCount == 0 || uncol == FigCount)
		pOut->PrintMessage("Please Draw Some Colored Shapes");
	else
	{
		GetValidColor();
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
			Result(pick[i]);
			if (randcol == NotExist(randcol))
			{

				pOut->PrintMessage("True Answers: " + to_string(TrueAns) + " Wrong Answers: " + to_string(WrongAns));
				break;
			}
			i++;
		}
	}
	delete pick;
}

void SelectTheColor::Result(CFigure* pick)
{
	if (pick->GetFigColor() == RED && randcol == RD)
	{
		TrueAns++;
		reds--;
	}
	else if (pick->GetFigColor() == ORANGE && randcol == ORNGE)
	{
		TrueAns++;
		oranges--;
	}
	else if (pick->GetFigColor() == YELLOW && randcol == YLLOW)
	{
		TrueAns++;
		yellows--;
	}
	else if (pick->GetFigColor() == BLACK && randcol == BLCK)
	{
		TrueAns++;
		blacks--;
	}
	else if (pick->GetFigColor() == GREEN && randcol == GRN)
	{
		TrueAns++;
		greens--;
	}
	else if (pick->GetFigColor() == BLUE && randcol == BLU)
	{
		TrueAns++;
		blues--;
	}
	else
		WrongAns++;
}
int SelectTheColor::EndExecute()
{

	if (p.y < UI.ToolBarHeight)
	{
		if (p.x < (UI.width - UI.MenuItemWidth * 2) && p.x >(UI.width - UI.MenuItemWidth * 2 * 2))
			return TO_DRAW;
		if (p.x > UI.MenuItemWidth * 9 && p.x < UI.MenuItemWidth * 11)
			return RESET;
		if (p.x > 0 && p.x < UI.MenuItemWidth * 2)
			return FIG_TYP;
		if (p.x > UI.MenuItemWidth * 6 && p.x < UI.MenuItemWidth * 8)
			return FIG_TYP_COL;
		return -1;
	}
	return -1;
}
SelectTheColor::~SelectTheColor()
{
	delete colors;
}
