#include "CHexa.h"

CHexa::CHexa(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CHexa::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawHexa(Center, FigGfxInfo, Selected);
}