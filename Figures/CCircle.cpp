#include "CCircle.h"
#include <cmath>
#include <fstream>
int CCircle::CircCount = 0;

CFigure* CCircle::clone() {
	return new CCircle(*this);
}

int CCircle::GetCircCount()
{
	return CircCount;
}
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	this->P1= P1;
	this->P2 = P2;
	CircCount++;
}
CCircle::CCircle(int id) : CFigure(id) {
	CircCount++;
}


void CCircle::Draw(Output* pOut) const
{

	pOut->DrawCircle(P1, P2, FigGfxInfo, Selected);
}

Point** CCircle::GetResizablePointsAsArray(int& count) {
	count = 1;
	return new Point*[]{&P2};
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

void CCircle::Move(Point NewLocation)
{
	double DiffrenceX = NewLocation.x - P1.x;
	double DiffrenceY = NewLocation.y - P1.y;
	P1.x = NewLocation.x;
	P1.y = NewLocation.y;
	P2.x += DiffrenceX;
	P2.y += DiffrenceY;

	


}
void CCircle::Drag(Point NewLocation, Point OldLocation)
{
	double DiffrenceX = NewLocation.x - OldLocation.x;
	double DiffrenceY = NewLocation.y - OldLocation.y;

	P1.x += DiffrenceX;
	P1.y += DiffrenceY;
	P2.x += DiffrenceX;
	P2.y += DiffrenceY;


}

void CCircle::PrintInfo(Output*pOut)
{
	float Radius = sqrt(pow((P1.x) - (P2.x), 2) + pow((P1.y) - (P2.y), 2));
	string ID, type, radius, center , msg;
	ID = to_string(this->ID);
	type = "Circle";
	radius = to_string(Radius);
	center = '(' + to_string(P1.x) + ',' + to_string(P1.y) + ')';
	msg = "Shape ID: " + ID + "   Type: " + type + "   Center: " + center + "   Radius: " + radius;
	pOut->PrintMessage(msg);
}

Point CCircle::getlocation()
{
	return P1;
}

string CCircle::GetName() const {
	return "CIRC";
}


void CCircle::Save(ofstream &file) {
	SavePoint(file, P1);
	SavePoint(file, P2);
	CFigure::Save(file);
}

void CCircle::Load(ifstream& file) {
	LoadPoint(file, P1);
	LoadPoint(file, P2);
	CFigure::Load(file);
}

CCircle::~CCircle()
{
	CircCount--;
}
