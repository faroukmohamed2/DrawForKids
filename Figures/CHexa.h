#pragma once


#include "CFigure.h"

class CHexa : public CFigure
{
private:
	Point Center;
	Point ResizableEdge;
	int length = 100;
	static int HexCount;
public:
	CHexa(Point, GfxInfo FigureGfxInfo);
	CHexa(int id);
	CFigure* clone();
	static int GetHexCount();

	Point** GetResizablePointsAsArray(int& count);
	void SetResizablePointAtIndex(int i, Point& p);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	void GetCorners(Point [] , Point );
	void Move(Point);
	Point getlocation();
	virtual void PrintInfo(Output*pOut);
	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual ~CHexa();
};
