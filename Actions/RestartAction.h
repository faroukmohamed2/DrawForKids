#ifndef _RESTART_H
#define _RESTART_H
#include "Action.h"
class Restart : public Action
{
	bool restart;
public:
	Restart(ApplicationManager* pApp);
	Action* clone() const { return new Restart(*this); }

	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif

