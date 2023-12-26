#include "SoundOn.h"
#include "..\ApplicationManager.h"
SoundOn::SoundOn(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false;//making this action is non undoable
}

void SoundOn::ReadActionParameters()
{
}

void SoundOn::Execute()
{
	Output* output = pManager->GetOutput();
	if (!pManager->GetSoundState())//checking the current sound state if the sound is muted
	{
		pManager->enableSound();//enable the sound and making the sound state is true
		output->PrintMessage("now the sound is enabled");
	}
	else output->PrintMessage("you have already enabled the sound ");//in the case the user is already enable the sound and clicked SoundOn again
}

