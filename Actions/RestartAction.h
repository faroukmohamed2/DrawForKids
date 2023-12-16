#ifndef _RESTART_H
#define _RESTART_H
#include "Action.h"
class Restart : public Action
{
	bool restart;
public:
	Restart(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif

