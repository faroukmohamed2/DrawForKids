#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ResizeAction :
    public Action
{
	int figId;
	int pointIndexToMove;
	Point EndPoint;
	Point StartPoint;

public:
	ResizeAction(ApplicationManager* pApp);
	Action* clone() const { return new ResizeAction(*this); }

	void ReadActionParameters();
	void Execute();
	void undo();
	void redo();
};

