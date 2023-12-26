#include "CHexa.h"
int CHexa::HexCount = 0;
CHexa::CHexa(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
	ResizableEdge = Center;
	ResizableEdge.x += length;
	HexCount++;
}

CHexa::CHexa(int id) : CFigure(id) {
	HexCount++;
}

CFigure* CHexa::clone() {
	return new CHexa(*this);
}

Point** CHexa::GetResizablePointsAsArray(int& count) {
	count = 1;
	return new Point * [] {&ResizableEdge};
}

void CHexa::SetResizablePointAtIndex(int i, Point& point) {
	
	length = point.x - Center.x;
	point = Center;
	point.x += length;

	CFigure::SetResizablePointAtIndex(i, point);
}

int CHexa::GetHexCount()
{
	return HexCount;
}


void CHexa::Draw(Output* pOut) const
{
	pOut->DrawHexa(Center, length, FigGfxInfo, Selected);
}

bool CHexa::PointBelong(int x , int y )
{
	Point Corners[6];
	Point P;
	P.x = x;  P.y = y;
	GetCorners(Corners, Center);

	if (Corners[2].x > x && Corners[5].x < x && Corners[2].y < y && Corners[5].y > y) // middle rectangle
		return true;
	else if (CFigure::IsInTriangle(Corners[2], Corners[3], Corners[4], P))
		return true;
	else if (CFigure::IsInTriangle(Corners[5], Corners[0], Corners[1], P))
		return true;

	return false;
}

void CHexa::Move(Point NewLocation)
{
	Center.x = NewLocation.x;
	Center.y = NewLocation.y;
}
void CHexa::Drag(Point NewLocation, Point OldLocation)
{
	double DiffrenceX = NewLocation.x - OldLocation.x;
	double DiffrenceY = NewLocation.y - OldLocation.y;

	Center.x += DiffrenceX;
	Center.y += DiffrenceY;

	ResizableEdge = Center;
	ResizableEdge.x += length;

}
Point CHexa::getlocation()
{
	return Center;
}
void CHexa::PrintInfo(Output*pOut)
{
	string ID, type, center , msg;
	ID = to_string(this->ID);
	type = "Hexagon";
	center = '(' + to_string(Center.x) + ',' + to_string(Center.y) + ')';
	msg = "Shape ID: " + ID + "   Type: " + type + "   Center: " + center;
	
	pOut->PrintMessage(msg);
}



void CHexa::GetCorners(Point Corners [6] , Point P1)
{
	           // P1 is center 
	
	Corners[3].x = (P1.x) + length;
	Corners[0].x = (P1.x) - length;
	Corners[0].y = Corners[3].y = P1.y;
	Corners[1].x = Corners[5].x = (P1.x) - (length / 2);
	Corners[2].x = Corners[4].x = (P1.x) + (length / 2);
	Corners[4].y = Corners[5].y = (P1.y) + (0.8660254 * length);
	Corners[1].y = Corners[2].y = (P1.y) - (0.8660254 * length);
}
string CHexa::GetName() const {
	return "HEXA";
}

void CHexa::Save(ofstream& file){
	SavePoint(file, Center);
	file << length << " ";
	CFigure::Save(file);

}

void CHexa::Load(ifstream& file) {
	LoadPoint(file, Center);
	file >> length;
	CFigure::Load(file);
}

CHexa::~CHexa()
{
	HexCount--;
}
