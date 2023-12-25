#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class SaveAction :
    public Action
{
    string name;
    
public:
    SaveAction(ApplicationManager* pApp);
    Action* clone() const { return new SaveAction(*this); }

    void Execute();
    void ReadActionParameters();
};

