#pragma once

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point P1;
	Point P2;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	void Move(Point);

};