#include "CSquare.h"

int CSquare::SquCount = 0;
CSquare::CSquare(Point TheMiddle, GfxInfo FigureGfxInfo) : CFigure (FigureGfxInfo)
{
	Center = TheMiddle;
	Corner.x = Center.x + HalfSquareLength;
	Corner.y = Center.y + HalfSquareLength;
	SquCount++;
}

CSquare::CSquare(int id) : CFigure(id) {
	SquCount++;
}

CFigure* CSquare::clone() {
	return new CSquare(*this);
}

Point** CSquare::GetResizablePointsAsArray(int& count) {
	SetCenterAndUpdateCorner(Center);

	count = 1;
	return new Point * [] {&Corner};
}


void CSquare::Draw(Output* pOut) const
{

	int length = max(Corner.x - Center.x, Corner.y - Center.y);
	Point otherPoint = Center;
	otherPoint.x -= length;
	otherPoint.y -= length;
	Point point = Center;
	point.x += length;
	point.y += length;

	pOut->DrawRect(point, otherPoint, FigGfxInfo, Selected);
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

void CSquare::SetCenterAndUpdateCorner(Point center) {
	HalfSquareLength = max(Corner.x - Center.x, Corner.y - Center.y);
	Center = center;
	Corner = Center;
	Corner.x += HalfSquareLength;
	Corner.y += HalfSquareLength;
}


void CSquare::Save(ofstream& file) {

	SavePoint(file, Center);
	SavePoint(file, Corner);
	file << HalfSquareLength << " ";
	CFigure::Save(file);

}

void CSquare::Load(ifstream& file) {
	LoadPoint(file, Center);
	LoadPoint(file, Corner);
	file >> HalfSquareLength;
	CFigure::Load(file);
}

void CSquare::Move(Point NewLocation)
{
	/*Point offset;
	offset.x = NewLocation.x - Center.x;
	offset.y = NewLocation.y - Center.y;

	Center.x = NewLocation.x;
	Center.y = NewLocation.y;

	Corner.x -= offset.x;
	Corner.y -= offset.y;*/
	SetCenterAndUpdateCorner(NewLocation);
}

void CSquare::Drag(Point NewLocation, Point OldLocation)
{
	double DiffrenceX = NewLocation.x - OldLocation.x;
	double DiffrenceY = NewLocation.y - OldLocation.y;

	Center.x += DiffrenceX;
	Center.y += DiffrenceY;

	Corner.x += DiffrenceX;
	Corner.y += DiffrenceY;


}

Point CSquare::getlocation()
{
	return Center;
}

int CSquare::GetSquCount()
{
	return SquCount;
}

CSquare::~CSquare()
{
	SquCount--;
}



