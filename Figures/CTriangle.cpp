#include "CTriangle.h"
int CTriangle::TriCount = 0;
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	TriCount++;
}

CTriangle::CTriangle(int id) : CFigure(id) {
	TriCount++;
}

CFigure* CTriangle::clone() {
	return new CTriangle(*this);
}

Point** CTriangle::GetResizablePointsAsArray(int& count) {
	count = 3;
	return new Point * [] {&Corner1, &Corner2, &Corner3};
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
string CTriangle::GetName() const {
	return "TRIA";
}
void CTriangle::Save(ofstream& file) {
	SavePoint(file, Corner1);
	SavePoint(file, Corner2);
	SavePoint(file, Corner3);
	CFigure::Save(file);

}

void CTriangle::Load(ifstream& file) {
	LoadPoint(file, Corner1);
	LoadPoint(file, Corner2);
	LoadPoint(file, Corner3);
	CFigure::Load(file);

}

Point CTriangle::getlocation()
{
	Point Center;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
	return Center;
}


void CTriangle::Move(Point NewLocation)
{
	Point Center;
	Center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	Center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;


	double DiffrenceX = NewLocation.x - Center.x;
	double DiffrenceY = NewLocation.y - Center.y;

	Corner1.x += DiffrenceX;
	Corner1.y += DiffrenceY;

	Corner2.x += DiffrenceX;
	Corner2.y += DiffrenceY;

	Corner3.x += DiffrenceX;
	Corner3.y += DiffrenceY;
}
void CTriangle::Drag(Point NewLocation, Point OldLocation)
{
	double DiffrenceX = NewLocation.x - OldLocation.x;
	double DiffrenceY = NewLocation.y - OldLocation.y;

	Corner1.x += DiffrenceX;
	Corner1.y += DiffrenceY;

	Corner2.x += DiffrenceX;
	Corner2.y += DiffrenceY;

	Corner3.x += DiffrenceX;
	Corner3.y += DiffrenceY;
}
void CTriangle::PrintInfo(Output*pOut)
{
	string ID, type, corner1 , corner2 , corner3 , msg;
	ID = to_string(this->ID);
	type = "Trinagle";
	corner1 = '(' + to_string(Corner1.x) + ',' + to_string(Corner1.y) + "),";
	corner2 = '(' + to_string(Corner2.x) + ',' + to_string(Corner2.y) + "),";
	corner3=  '(' + to_string(Corner3.x) + ',' + to_string(Corner3.y) + ')' ;
	msg = "Shape ID: " + ID + "    Type: " + type + "   Corners:" + corner1 + corner2 + corner3;
	pOut->PrintMessage(msg);
}
int CTriangle::GetTriCount()
{
	return TriCount;
}
CTriangle::~CTriangle()
{
	TriCount--;
}





