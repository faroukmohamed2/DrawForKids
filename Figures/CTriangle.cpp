#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
		
	pOut->DrawTrig(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

bool CTriangle::PointBelong(int x , int y )
{
	Point P4;
	P4.x = x; P4.y = y;

	return (CFigure::IsInTriangle(Corner1 , Corner2 , Corner3 , P4 ));
}

void CTriangle::Move(Point NewLocation)
{

	double DiffrenceX = NewLocation.x - Corner1.x;
	double DiffrenceY = NewLocation.y - Corner1.y;

	Corner1.x = NewLocation.x;
	Corner1.y = NewLocation.y;

	Corner2.x += DiffrenceX;
	Corner2.y += DiffrenceY;
	Corner3.x += DiffrenceX;
	Corner3.y += DiffrenceY;
}






