#pragma once

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point P1;
	Point P2;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle(int id);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);

	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

};