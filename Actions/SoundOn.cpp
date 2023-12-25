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
	if (!pManager->GetSoundState())
	{
		pManager->enableSound();
		output->PrintMessage("now the sound is enabled");
	}
	else output->PrintMessage("you have already enabled the sound ");
}
