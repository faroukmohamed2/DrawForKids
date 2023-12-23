#ifndef _SELECT_THE_SHAPE
#define _SELECT_THE_SHAPE
#include "Action.h"
#include "RestartAction.h"
#include "ChangeToDrawModeAction.h"
#include "../Figures/CFigure.h"
class SelectTheShape : public Action
{
protected:
	Point p;
	int RecCount, TriCount, HexCount, SquCount, CircCount, FigCount, randshape;
	int TrueAns, WrongAns;
	enum shapes { REC, TRI, SQU, CIRC, HEX, NUM };
public:
	SelectTheShape(ApplicationManager* pApp);
	int NotExist(int);
	void GetValidShape();
	virtual void ReadActionParameters();
	virtual void Execute();
	int EndExecute();
	void Result(CFigure*);
};

#endif
