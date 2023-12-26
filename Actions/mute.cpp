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
	if (pManager->GetSoundState())//checking the current sound state if the sound is on
	{
		pManager->MuteSound();// mute the sound and making the sound state is false
		output->PrintMessage("the mute action is excuted ");
	}
	else output->PrintMessage("you have already mute the sound ");//in the case the user is already mute the sound and clicked mute again
}