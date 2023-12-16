#ifndef _SELECT_THE_SHAPE
#define _SELECT_THE_SHAPE
#include "Action.h"
#include "RestartAction.h"
#include "ChangeToDrawModeAction.h"
class SelectTheShape : public Action
{
	Point p;
	int RecCount, TriCount, HexCount, SquCount, CircCount, FigCount, randshape;
	enum shapes { REC, TRI, SQU, CIRC, HEX, NUM };
public:
	SelectTheShape(ApplicationManager* pApp);
	int NotExist(int);
	void GetValidShape();
	virtual void ReadActionParameters();
	virtual void Execute();
	ActionType EndExecute();
};

#endif
