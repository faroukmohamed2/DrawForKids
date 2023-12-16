#include "SaveAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include <fstream>
#include <iostream>

SaveAction::SaveAction(ApplicationManager* pApp) : Action(pApp){}


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
	ofstream file(name);
	
	file << output->getCrntDrawColor() << " ";
	file << output->getCrntFillColor() << " ";
	
	file << endl;

	pManager->SaveAll(file);
}
