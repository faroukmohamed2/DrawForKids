#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	hide = false;
}

CFigure::CFigure(int id)
{
	ID = id;
	Selected = false;
}

bool CFigure::IsFilled()
{
	if (FigGfxInfo.isFilled)
		return true;
	return false;
}

int CFigure::GetId() const {
	return ID;
}

void CFigure::SetHide(bool Hide)
{
	hide = Hide;
}

bool CFigure::IsHide() const
{
	return hide;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

color CFigure::GetFigColor() const
{
	return FigGfxInfo.FillClr;
}

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

void CFigure::SetResizablePointAtIndex(int index, Point& point) {
	int count;
	Point** points = GetResizablePointsAsArray(count);
	if (index < count) {
		*points[index] = point;
	}
}

void CFigure::SavePoint(ofstream& OutFile, Point &point) {
	OutFile << point.x << " ";
	OutFile << point.y << " ";
}

void CFigure::LoadPoint(ifstream& file, Point &point) {
	file >> point.x;
	file >> point.y;
}

void CFigure::Save(ofstream& OutFile) {
	OutFile << FigGfxInfo.DrawClr << " ";

	if (FigGfxInfo.isFilled)
		OutFile << FigGfxInfo.FillClr << " ";
	else
		OutFile << "NO-FILL" << " ";
}

void CFigure::Load(ifstream& InFile) {


	InFile >> FigGfxInfo.DrawClr;

	string fillId;
	InFile >> fillId;
	if (fillId == "NO-FILL")
		FigGfxInfo.isFilled = false;
	else
		FigGfxInfo.FillClr = NameToColor(fillId);


}

void CFigure::SetId(int id)
{
	ID = id;
}

int CFigure::GetID()
{
	return ID;
}

void CFigure::Delete(Output* pOut)
{
	FigGfxInfo.isFilled = false;
	ChngDrawClr(UI.BkGrndColor);
	this->Draw(pOut);
	ChngFillClr(UI.BkGrndColor);
	this->Draw(pOut);
}
bool CFigure::getfillstate()
{
	return FigGfxInfo.isFilled;
}

color CFigure::GetborderColor()
{
	return FigGfxInfo.DrawClr;
}

CFigure::~CFigure() {}





