#ifndef _COLOR_h
#define _COLOR_h
#include "Action.h"
#include "../DEFS.h"
class SelectTheColor : public Action
{
	Point p;
	color* colors;
	int FigCount;
	int reds, blues, yellows, oranges, blacks, greens, randcol, uncol;
	enum Col {RD, BLU, GRN, BLCK, ORNGE, YLLOW, NUM};
public:
	SelectTheColor(ApplicationManager* pApp);
	int GetValidColor();
	int NotExist(int);
	virtual void ReadActionParameters(); 
	virtual void Execute();
	void CountColors();
	ActionType EndExecute();
	~SelectTheColor();
};

#endif