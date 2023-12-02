#include "CCircle.h"
#include <cmath>

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	this->P1= P1;
	this->P2 = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCircle(P1, P2, FigGfxInfo, Selected);
}

bool CCircle::PointBelong(int x, int y)
{
	float Radius = sqrt(pow((P1.x) - (P2.x), 2) + pow((P1.y) - (P2.y), 2));

	x -= P1.x;
	y -= P1.y;

	if ((float)(pow(x, 2) + pow(y, 2)) <= (float)pow(Radius, 2))
		return true;
	return false;
}
