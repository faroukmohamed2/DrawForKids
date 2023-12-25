#pragma once
#include "Action.h"

class SoundOn : public Action {
public:


	SoundOn(ApplicationManager* pApp);
	Action* clone() const { return new SoundOn(*this); }

	virtual void ReadActionParameters();
	void Execute();









};