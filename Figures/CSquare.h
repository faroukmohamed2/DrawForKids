#pragma once

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Corner;
	Point Center;
	int HalfSquareLength = 70;   // this is hal
	static int SquCount;

	void SetCenterAndUpdateCorner(Point center);


public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare(int id);

	Point** GetResizablePointsAsArray(int& count);
	void SetPointAtIndex(int index, Point& point);

	CFigure* clone();

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	virtual void PrintInfo(Output*pOut);
	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	void Move(Point);
	Point getlocation();
	static int GetSquCount();
	virtual ~CSquare();
};