#include "SaveAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include <fstream>
#include <iostream>

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp) { UndoValidity = false;//making the action non-undoable
}


void SaveAction::ReadActionParameters () {
	Input* input = pManager->GetInput();
	Output* output = pManager->GetOutput();

	output->PrintMessage("Enter file name: ");

	name = input->GetSrting(output) + ".dfk";
}

void SaveAction::Execute() {
	ReadActionParameters();

	Input* input = pManager->GetInput();
	Output* output = pManager->GetOutput();

	try {
		ofstream file(name);
		file.clear();
		file << output->getCrntDrawColor() << " ";

		if (UI.FillState)
			file << output->getCrntFillColor() << " ";
		else
			file << "NO-FILL" << " ";

		file << endl;
		pManager->SaveAll(file);
	}
	catch (exception e) {
		output->PrintMessage("Save: Something went wrong, Please check the file name.");
	}
}
