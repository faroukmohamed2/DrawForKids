#include "StopRecordingAction.h"
#include "../../ApplicationManager.h"

StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) :Action(pApp) {}

void StopRecordingAction::ReadActionParameters() {

}

//Execute action (code depends on action type)
void StopRecordingAction::Execute() {
	Output* out = pManager->GetOutput();
	if (pManager->IsRecording()) {
		pManager->StopRectording();
		out->PrintMessage("Recording stopped.");
	}
	else {
		out->PrintMessage("Start recording first.");
	}
}