#ifndef _COLOR_h
#define _COLOR_h
#include "Action.h"
#include "../DEFS.h"
#include "../Figures/CFigure.h"
class SelectTheColor : public Action
{
protected:
	Point p;
	color* colors;
	int FigCount;
	int reds, blues, yellows, oranges, blacks, greens, randcol, uncol;
	int TrueAns, WrongAns;
	enum Col {RD, BLU, GRN, BLCK, ORNGE, YLLOW, NUM};
public:
	SelectTheColor(ApplicationManager* pApp);
	int GetValidColor();
	int NotExist(int);
	virtual void ReadActionParameters(); 
	virtual void Execute();
	void CountColors();
	int EndExecute();
	void Result(CFigure*);
	~SelectTheColor();
};

#endif