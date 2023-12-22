#include "StartRecordingAction.h"
#include "../ApplicationManager.h"

StartRecordingAction::StartRecordingAction(ApplicationManager * pApp) :Action(pApp) {}

void StartRecordingAction::ReadActionParameters() {

}

//Execute action (code depends on action type)
void StartRecordingAction::Execute() {
	pManager->StartRecording();
}
