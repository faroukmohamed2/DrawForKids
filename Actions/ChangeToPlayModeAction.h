#ifndef _PLAYMODEACTION_H
#define _PLAYMODEACTION_H
#include "Action.h"
class ChangeToPlayModeAction : public Action
{
public:
	ChangeToPlayModeAction(ApplicationManager* pApp);
	Action* clone() const { return new ChangeToPlayModeAction(*this); }

	virtual void ReadActionParameters();
	virtual void Execute();
};

#endif // !_PLAYMODEACTION_H
