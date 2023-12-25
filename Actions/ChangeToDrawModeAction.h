#ifndef _CHANGETODRAWMODEACTION_H
#define _CHANGETODRAWMODEACTION_H
#include "Action.h"
class ChangeToDrawModeAction : public Action
{
public:
	ChangeToDrawModeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	
};
#endif
