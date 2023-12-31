#include <fstream>
#include <string>

#include "LoadAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "../Utils.h"
#include "../Figures/CCircle.h"
#include "../Figures/CHexa.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp) 
{ UndoValidity = false;//making the action non-undoable
}	//constructor

	//Reads parameters required for action to execute (code depends on action type)
void LoadAction::ReadActionParameters() {
	Input* input = pManager->GetInput();
	Output* output = pManager->GetOutput();

	output->PrintMessage("Enter file name: ");

	name = input->GetSrting(output) + ".dfk";
}

//Execute action (code depends on action type)
void LoadAction::Execute() {
	pManager->ClearAll();
	pManager->StopRectording();
	Input* input = pManager->GetInput();
	Output* output = pManager->GetOutput();

	try{
	ReadActionParameters();
	
	ifstream file(name);


	color draw, fill;
	int count;

	file >> draw;

	string fillId;
	file >> fillId;
	if (fillId == "NO-FILL")
		UI.FillState = false;
	else {
		output->setCrntFillColor(NameToColor(fillId));
		UI.FillState = true;
	}

	file >> count;

	output->setCrntDrawColor(draw);


	CFigure** figurs = new CFigure*[count];

	for (int i = 0; i < count; i++) {
		string shapeType;
		int id;
		file >> shapeType >> id;
		if (shapeType      == "CIRC")
			figurs[i] = new CCircle(id);
		else if (shapeType == "HEXA")
			figurs[i] = new CHexa(id);
		else if (shapeType == "RECT")
			figurs[i] = new CRectangle(id);
		else if (shapeType == "SQUA")
			figurs[i] = new CSquare(id);
		else if (shapeType == "TRIA")
			figurs[i] = new CTriangle(id);

		figurs[i]->Load(file);
	}

	pManager->LoadAll(figurs, count);
	pManager->show();
	pManager->UpdateInterface();

	output->PrintMessage("Loaded " + std::to_string(count) + " Figures");

	}
	catch (exception e) {
		output->PrintMessage("Load: Something went wrong, Please check the file name.");
	}

}