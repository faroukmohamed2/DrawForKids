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
	void ReadActionParameters();
	void Execute();
	void undo();
	void redo();
};

