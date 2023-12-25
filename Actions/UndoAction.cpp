#include "UndoAction.h"
#include "..\ApplicationManager.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
	UndoValidity = false; //making the action non-undoable
	Recordable = true;
}

void UndoAction::ReadActionParameters()
{

}

void UndoAction::Execute()
{
	if (pManager->GetSoundState())
	{
		PlaySound("Undo.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	pManager->UndoLastAction();
}
