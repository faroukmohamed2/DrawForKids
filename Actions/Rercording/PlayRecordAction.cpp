#include "PlayRecordAction.h"
#include "../../ApplicationManager.h"

PlayRecordAction::PlayRecordAction(ApplicationManager* pApp) :Action(pApp) { UndoValidity = false; }

void PlayRecordAction::ReadActionParameters() {

}

//Execute action (code depends on action type)
void PlayRecordAction::Execute() {
	Output* out = pManager->GetOutput();
	if (pManager->IsRecordClipAvailable() && !pManager->IsRecording()) {
		out->PrintMessage("Started playing the record ...");
		pManager->ClearAll();
		pManager->PlayRecord();
		out->PrintMessage("Finished playing, You can start drawing now.");
	}
	else {
		out->PrintMessage("No recording to be played.");
	}
}