#ifndef _COLOR_SHAPE_H
#define _COLOR_SHAPE_H
#include "Action.h"
#include "SelectTheColor.h"
#include "SelectTheShape.h"
#include "../Figures/CFigure.h"
#include "../DEFS.h"
class SelectColorShape : public Action
{
	int FigCount;
	CFigure** shapes;
	color* colors;
	Point p;
	int randshape, randcol, randindcol, randindsh;
	int TrueAns, WrongAns;
	int CountValid;
	int* col;
	int* sh;
	enum Col { RD, BLU, GRN, BLCK, ORNGE, YLLOW, NUMs };
	enum shapes { REC, TRI, SQU, CIRC, HEX, NUM };
public:
	SelectColorShape(ApplicationManager* pApp);
	Action* clone() const { return new SelectColorShape(*this); }

	void CountCols();
	void Countsh();
	void GetValidColShape();
	virtual void ReadActionParameters();
	virtual void Execute();
	int EndExecute();
	~SelectColorShape();
};
#endif
