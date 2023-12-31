#pragma once

#include "CFigure.h"
 
class CTriangle : public CFigure
{
private:
	Point Corner1, Corner2, Corner3;
	static int TriCount;
public:
	CTriangle(Point, Point, Point , GfxInfo FigureGfxInfo);
	CTriangle(int id);

	CFigure* clone();

	Point** GetResizablePointsAsArray(int& count);
	void SetPointAtIndex(int index, Point& point);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	void Move(Point);
	void Drag(Point, Point);
	virtual void PrintInfo(Output* pOut);
	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	Point getlocation();
	static int GetTriCount();
	virtual ~CTriangle();
};
