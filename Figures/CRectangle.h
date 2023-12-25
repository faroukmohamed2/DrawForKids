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

	CFigure* clone();

	Point** GetResizablePointsAsArray(int& count);

	virtual void Draw(Output* pOut) const;
	virtual bool PointBelong(int, int);
	virtual void PrintInfo(Output* pOut);

	string GetName() const;
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	void Move(Point);
	Point getlocation();
	static int GetRecCount();
	virtual ~CRectangle();
};

#endif