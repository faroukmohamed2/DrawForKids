#include "CSquare.h"
int CSquare::SquCount = 0;
CSquare::CSquare(Point TheMiddle, GfxInfo FigureGfxInfo) : CFigure (FigureGfxInfo)
{
	Center = TheMiddle; 
	SquCount++;
}

CSquare::CSquare(int id) : CFigure(id) {}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

bool CSquare::PointBelong(int x, int y)
{

	double MaxX = Center.x + HalfSquareLength;
	double MaxY = Center.y + HalfSquareLength;
	double MinX = Center.x - HalfSquareLength;
	double MinY = Center.y - HalfSquareLength;

	if (MaxX > x && MinX < x && MaxY > y && MinY < y)
		return true;

	return false;
}
void CSquare::PrintInfo(Output*pOut)
{
	string ID, type, center, length , msg;
	ID = to_string(this->ID);
	type = "square";
	center = '(' + to_string(Center.x) + ',' + to_string(Center.y) + ')';
	length = to_string(2 * HalfSquareLength);
	msg = "Shape ID: " + ID + "   Type: " + type + "   Center: " + center + "   Length: " + length;
	pOut->PrintMessage(msg);

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

int CSquare::GetSquCount()
{
	return SquCount;
}

CSquare::~CSquare()
{
	SquCount--;
}



