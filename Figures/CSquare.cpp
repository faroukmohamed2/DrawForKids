#include "CSquare.h"

CSquare::CSquare(Point TheMiddle, GfxInfo FigureGfxInfo) : CFigure (FigureGfxInfo)
{
	Center = TheMiddle; 
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}
