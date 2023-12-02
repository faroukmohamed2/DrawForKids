#include "CSquare.h"

CSquare::CSquare(Point TheMiddle, GfxInfo FigureGfxInfo) : CFigure (FigureGfxInfo)
{
	Center = TheMiddle; 
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool CSquare::PointBelong(int x, int y)
{
	const int SquareLength = 70; 

	double MaxX = Center.x + SquareLength;
	double MaxY = Center.y + SquareLength;
	double MinX = Center.x - SquareLength;
	double MinY = Center.y - SquareLength;

	if (MaxX > x && MinX < x && MaxY > y && MinY < y)
		return true;

	return false;
}
