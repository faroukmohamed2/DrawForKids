#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class SaveAction :
    public Action
{
    string name;
    
public:
    SaveAction(ApplicationManager* pApp);
    void Execute();
    void ReadActionParameters();
};

