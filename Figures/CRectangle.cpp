#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::PointBelong(int x , int y )
{
	int MaxX = max(Corner1.x, Corner2.x);
	int MaxY = max(Corner1.y, Corner2.y);
	int MinX = min(Corner1.x, Corner2.x);
	int MinY = min(Corner1.y, Corner2.y);

	if (MaxX > x && MinX < x && MaxY > y && MinY < y)
		return true;
	return false;
	
}

void CRectangle::Move(Point NewLocation)
{
	Point Center;

	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;

	

	double DistanceX = NewLocation.x - Center.x;
	double DistanceY = NewLocation.y - Center.y;

	Corner1.x += DistanceX;
	Corner1.y += DistanceY;

	Corner2.x += DistanceX;
	Corner2.y += DistanceY;

	

}




