#pragma once

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point P1;
	Point P2;
	static int CircCount;
public:
	static int GetCircCount();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle(int id);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	void Move(Point);
	virtual void PrintInfo(Output*pOut);

	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual ~CCircle();
};