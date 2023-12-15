#pragma once

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
	const int HalfSquareLength = 70;   // this is hal
	static int SquCount;

public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare(int id);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	virtual void PrintInfo(Output*pOut);
	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	void Move(Point);
	static int GetSquCount();
	virtual ~CSquare();
};