#include "mute.h"
#include "..\ApplicationManager.h"
mute::mute(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false;//making this action is non undoable
}

void mute::ReadActionParameters()
{
}

void mute::Execute()
{
	Output* output = pManager->GetOutput();
	if (pManager->GetSoundState())
	{
		pManager->MuteSound();
		output->PrintMessage("the mute action is excuted ");
	}
	else output->PrintMessage("you have already mute the sound ");
}