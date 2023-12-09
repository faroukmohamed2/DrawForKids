#ifndef _SELECT_THE_SHAPE
#define _SELECT_THE_SHAPE
#include "Action.h"
class SelectTheShape : public Action
{
	Point p;
public:
	SelectTheShape(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif
