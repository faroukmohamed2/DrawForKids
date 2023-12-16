#pragma once

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1, Corner2, Corner3;

public:
	CTriangle(Point, Point, Point , GfxInfo FigureGfxInfo);
	CTriangle(int id);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	void Move(Point);

	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};
