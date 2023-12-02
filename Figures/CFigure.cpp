#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

bool CFigure::IsInTriangle(Point P1, Point P2, Point P3, Point Comparer)
{

	double A1 = CalcAreaTriangle(P1, P2, Comparer);
	double A2 = CalcAreaTriangle(P1, Comparer, P3);
	double A3 = CalcAreaTriangle(Comparer, P2, P3);
	double A = CalcAreaTriangle(P1, P2, P3);

	return (A == A1 + A2 + A3);
}

double CFigure::CalcAreaTriangle(Point P1, Point P2, Point P3 )
{

	double Area = abs((P1.x * (P2.y - P3.y) + P2.x * (P3.y - P1.y) + P3.x * (P1.y -P2.y)) / 2.0);

	return Area;
}

