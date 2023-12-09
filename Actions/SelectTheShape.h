#ifndef _SELECT_THE_SHAPE
#define _SELECT_THE_SHAPE
#include "Action.h"
class SelectTheShape : public Action
{
	Point p;
	int RecCount, TriCount, HexCount, SquCount, CircCount, FigCount;
	enum shapes { REC, TRI, SQU, CIRC, HEX, NUM };
public:
	SelectTheShape(ApplicationManager* pApp);
	bool IsExist(int);
	int GetValidShape();
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif
