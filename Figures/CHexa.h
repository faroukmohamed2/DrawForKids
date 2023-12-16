#pragma once


#include "CFigure.h"

class CHexa : public CFigure
{
private:
	Point Center;
	static int HexCount;
public:
	CHexa(Point, GfxInfo FigureGfxInfo);
	CHexa(int id);
	static int GetHexCount();
	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	void GetCorners(Point [] , Point );
	void Move(Point);
	virtual void PrintInfo(Output*pOut);
	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual ~CHexa();
};
