#pragma once

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare(int id);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);

	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
};