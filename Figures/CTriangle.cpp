#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTrig(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

bool CTriangle::PointBelong(int x , int y )
{
	Point P4;
	P4.x = x; P4.y = y;

	return (CFigure::IsInTriangle(Corner1 , Corner2 , Corner3 , P4 ));
}
