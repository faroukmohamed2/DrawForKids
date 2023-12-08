#include "CHexa.h"

CHexa::CHexa(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}

CHexa::CHexa(int id) : CFigure(id) {}


void CHexa::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawHexa(Center, FigGfxInfo, Selected);
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

void CHexa::GetCorners(Point Corners [6] , Point P1)
{
	float l = 100;            // P1 is center 
	
	Corners[3].x = (P1.x) + l;
	Corners[0].x = (P1.x) - l;
	Corners[0].y = Corners[3].y = P1.y;
	Corners[1].x = Corners[5].x = (P1.x) - (l / 2);
	Corners[2].x = Corners[4].x = (P1.x) + (l / 2);
	Corners[4].y = Corners[5].y = (P1.y) + (0.8660254 * l);
	Corners[1].y = Corners[2].y = (P1.y) - (0.8660254 * l);
}
string CHexa::GetName() const {
	return "HEXA";
}

void CHexa::Save(ofstream& file){
	SavePoint(file, Center);
	CFigure::Save(file);

}

void CHexa::Load(ifstream& file) {
	LoadPoint(file, Center);
	CFigure::Load(file);

}
