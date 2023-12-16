#include "CSquare.h"

CSquare::CSquare(Point TheMiddle, GfxInfo FigureGfxInfo) : CFigure (FigureGfxInfo)
{
	Center = TheMiddle; 
}

CSquare::CSquare(int id) : CFigure(id) {}

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
string CSquare::GetName() const {
	return "SQUA";
}
void CSquare::Save(ofstream& file) {

	SavePoint(file, Center);
	CFigure::Save(file);

}

void CSquare::Load(ifstream& file) {
	LoadPoint(file, Center);
	CFigure::Load(file);

}

void CSquare::Move(Point NewLocation)
{
	Center.x = NewLocation.x;
	Center.y = NewLocation.y;
}


