#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSquareAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddHexaAction.h"
#include "Actions/SelectAction.h"
#include "Actions/SaveAction.h"
#include "Actions/ChangeToPLayModeAction.h"
#include "Actions/ChangeToDrawModeAction.h"
#include "Actions/LoadAction.h"
#include <fstream>
#include <iostream>
#include <string>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	cout << ActType << endl;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case TO_PLAY:
			pAct = new ChangeToPlayModeAction(this);
			break;
		case TO_DRAW:
			pAct = new ChangeToDrawModeAction(this);
			break;
		case DRW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRW_Square:
			pAct = new AddSquareAction(this);
			break;
		case DRW_Circ:
			pAct = new AddCircleAction(this);
			break;
		case DRW_Trig:
			pAct = new AddTriAction(this);
			break;
		case DRW_Hexa :
			pAct = new AddHexaAction(this);
			break;
		case Selection_Tool:
			pAct = new SelectAction(this);
			break;
		case SAVE_RECORD:
			pAct = new SaveAction(this);
			break;
		case LOAD_RECORD:
			pAct = new LoadAction(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		//delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						       Save System Functions								//
//==================================================================================//
void ApplicationManager::SaveAll(ofstream &file) const {
	file << FigCount << endl;
	for (int i = 0; i < FigCount; i++) {
		file << FigList[i]->GetName() << " ";
		file << FigList[i]->GetId() << " ";
		FigList[i]->Save(file);
		file << endl;
	}
	pOut->PrintMessage("Saved " + std::to_string(FigCount) + " Figures");
}

void ApplicationManager::LoadAll(CFigure** list, int count) {
	for (int i = 0; i < MaxFigCount; i++) {
		if (FigList[i] != nullptr)
			delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = count;

	for (int i = 0; i < count; i++)
		FigList[i] = list[i];
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//CSquare* TheShape = NULL;
	bool PointBelong = false;

	for (int i = FigCount - 1; i >= 0; i--) {

		//TheShape = dynamic_cast <CSquare*> (FigList[i]);
		PointBelong = FigList [i]->PointBelong(x, y);
		if (PointBelong) {

			return FigList[i];
		}
	}
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	Point p1, p2; //Draw white background
	p1.y = UI.ToolBarHeight;
	p2.x = UI.width;
	p2.y = UI.height - UI.StatusBarHeight;
	GfxInfo gfxInfo;
	gfxInfo.FillClr = UI.BkGrndColor;
	pOut->DrawRect(p1, p2, gfxInfo);

	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
