#include "CRectangle.h"
int CRectangle::RecCount = 0;
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	RecCount++;
	

}

CRectangle::CRectangle(int id) : CFigure(id) {}

CFigure* CRectangle::clone() {
	return new CRectangle(*this);
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


void CRectangle::PrintInfo(Output*pOut)
{
	string ID , type , Height , Width ,TheCenter,msg;
	Point Center;

	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;

	ID = to_string(this->ID);
	type = "Rectangle";
	Height = to_string(abs(Corner1.y - Corner2.y));
	Width = to_string(abs(Corner1.x - Corner2.x));
	TheCenter = '(' + to_string(Center.x) + ',' + to_string(Center.y) + ')';

	msg = "Shape ID: " + ID + "   Type:" + type + "   center:" + TheCenter + "   Height: " + Height + "   Width: " + Width;
	
	pOut->PrintMessage(msg);
} 


string CRectangle::GetName() const {
	return "RECT";
}


void CRectangle::Save(ofstream& file) {
	SavePoint(file, Corner1);
	SavePoint(file, Corner2);
	CFigure::Save(file);

}

void CRectangle::Load(ifstream& file) {
	LoadPoint(file, Corner1);
	LoadPoint(file, Corner2);
	CFigure::Load(file);

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

Point CRectangle::getlocation()
{
	Point Center;

	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	return Center;
}


int CRectangle::GetRecCount()
{
	return RecCount;
}

CRectangle::~CRectangle()
{
	RecCount--;
}




