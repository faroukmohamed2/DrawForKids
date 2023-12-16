#pragma once


#include "CFigure.h"

class CHexa : public CFigure
{
private:
	Point Center;

public:
	CHexa(Point, GfxInfo FigureGfxInfo);
	CHexa(int id);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	void GetCorners(Point [] , Point );
	void Move(Point);

	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);

};
