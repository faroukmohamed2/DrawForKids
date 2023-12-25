#include "StartRecordingAction.h"
#include "../../ApplicationManager.h"

StartRecordingAction::StartRecordingAction(ApplicationManager* pApp) :Action(pApp) { UndoValidity = false; }

void StartRecordingAction::ReadActionParameters() {

}

//Execute action (code depends on action type)
void StartRecordingAction::Execute() {
	Output* out = pManager->GetOutput();
	if (pManager->GetFigCount() == 0) {
		pManager->StartRecording();
		out->PrintMessage("Recording started.");
	}
	else {
		out->PrintMessage("Board must be empty before recording, Press clear icon.");
	}
}
