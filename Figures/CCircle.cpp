#include "CCircle.h"

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