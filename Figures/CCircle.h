#pragma once

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point P1;
	Point P2;
	static int CircCount;
public:
	CFigure* clone();

	static int GetCircCount();
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle(int id);
	
	Point** GetResizablePointsAsArray(int& count);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	void Move(Point);
	void Drag(Point, Point);
	virtual void PrintInfo(Output*pOut);
	virtual Point getlocation();
	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual ~CCircle();
};