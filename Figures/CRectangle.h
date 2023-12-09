#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	static int RecCount;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	CRectangle(int id);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);

	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	void Move(Point);
	static int GetRecCount();
	virtual ~CRectangle();
};

#endif