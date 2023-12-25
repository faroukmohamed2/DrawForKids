#pragma once
#pragma once
#include "Action.h"

class mute : public Action {
public:


	mute(ApplicationManager* pApp);
	Action* clone() const { return new mute(*this); }

	virtual void ReadActionParameters();
	void Execute();









};