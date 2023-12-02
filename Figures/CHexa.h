#pragma once


#include "CFigure.h"

class CHexa : public CFigure
{
private:
	Point Center;

public:
	CHexa(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	void GetCorners(Point [] , Point );

};
