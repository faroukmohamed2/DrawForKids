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
#include <thread>
#include "Actions/ChangeColorAction.h"
#include "Actions/ChangeFillAction.h"
#include "Actions/DeleteFigAction.h"
#include "Actions/MoveAction.h"
#include "Actions/SelectTheShape.h"
#include "Actions/RestartAction.h" 
#include "Actions/SelectTheColor.h"
#include "Actions/SelectColorShape.h"
#include "Actions/UndoAction.h"
#include "Actions/RedoAction.h"
#include "Actions/Rercording/StartRecordingAction.h"
#include "Actions/Rercording/StopRecordingAction.h"
#include "Actions/Rercording/PlayRecordAction.h"
#include"Actions/ClearAllAction.h"
#include<Windows.h>
#include "Actions/ResizeAction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	CountofUndoed = 0;
	ActionsCount = 0;
	SelectedFig = NULL;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	

	for (int i = 0; i < 5; i++)
		last5Actions[i] = NULL;
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
		{  PlaySound("Rectangle.wav", NULL, SND_SYNC);
			pAct = new AddRectAction(this);
		 }
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
		case DRW_Hexa:
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

		case DRW_Red:
			pAct = new ChangeColorAction(this, DRW_Red);
			break;
		case DRW_Green:
			pAct = new ChangeColorAction(this, DRW_Green);
			break;
		case DRW_Orange:
			pAct = new ChangeColorAction(this, DRW_Orange);
			break;
		case DRW_Yellow:
			pAct = new ChangeColorAction(this, DRW_Yellow);
			break;
		case DRW_Blue:
			pAct = new ChangeColorAction(this, DRW_Blue);
			break;
		case DRW_Black:
			pAct = new ChangeColorAction(this, DRW_Black);
			break;
		case Fill_Tool:
			pAct = new ChangeFillAction(this, Fill_Tool);
			break;
		case Pencile_Tool:
			pAct = new ChangeFillAction(this, Pencile_Tool);
			break;
		case Delete:
			pAct = new DeleteFigAction(this);
			break;
		case Move_Tool:
			pAct = new MoveAction(this);
			break;
		case FIG_TYP:
			pAct = new SelectTheShape(this);
			break;
		case FIG_COL:
			pAct = new SelectTheColor(this);
			break;
		case RESET:
			pAct = new Restart(this);
			break;
		case FIG_TYP_COL:
			pAct = new SelectColorShape(this);
			break;
		case UNDO:
			pAct = new UndoAction(this);
			break;
		case REDO:
			pAct = new RedoAction(this);
			break;
		case START_RECORD:
			pAct = new StartRecordingAction(this);
			break;
		case STOP_RECORD:
			pAct = new StopRecordingAction(this);
			break;
		case PLAY_RECORD:
			pAct = new PlayRecordAction(this);
			break;
		case ClearBoard:
			pAct = new ClearAllAction(this);
			break;
		case RESIZE_FIGURE:
			pAct = new ResizeAction(this);
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
		addAction(pAct);
		if (!pAct->isRecordable() && !pAct->GetUndoValidity())//we check that we didn't need the action to be recorded or undided
		{
			delete pAct;
		}
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

int ApplicationManager::GetFigCount() const
{

	return FigCount ;
}
//==================================================================================//
//						       undo and redo System Functions				    	//
//==================================================================================//

void ApplicationManager::addAction(Action* ptr)
{
	if (isRecording && ptr->isRecordable()) {//adding action to the record history
		if (RecordedActionCount < MaxRecordActionCount) {
			RecordedAction[RecordedActionCount++] = ptr;
		}
		else {
			pOut->PrintMessage("Recording limit exceeded, Recording stopped.");
			delete ptr;
			StopRectording();
		}
	}

	if (ptr->GetUndoValidity())//check that the current action is able to be undid
	{

		while (CountofUndoed != 0)//if we add an action we check that we remove that undid actions before it
		{
			delete last5Actions[ActionsCount - 1];//delete the undid action
			CountofUndoed--;//decrement the number of undidactions
			ActionsCount--;//decrement the number of actions in the last5actions array
		}


		if (ActionsCount < 5)//if the array of actions is not full
		{
			last5Actions[ActionsCount++] = ptr;//put the current action in the last empty element
		}

		else {//if the array of actions is full
			delete last5Actions[0];//delete the first element is the array because now we can't it
			for (int i = 0; i < 4; i++)
			{
				last5Actions[i] = last5Actions[i + 1];//replace every element with the next element
			}

			last5Actions[4] = ptr;//now we will assign the last action with current action
		}
	}

}


void ApplicationManager::UndoLastAction()
{
	int i = ActionsCount - CountofUndoed - 1;//a counter used to know what is the current index that we in
	if (ActionsCount == 0 || i < 0)//checking that we don't make any actions or the number of undos is>5
	{
		pOut->PrintMessage("you can't undo anymore");
		return;
	}

	last5Actions[i]->undo();//otherwise we will call the virtual function of the undo of the current action
	                        ////every actions is responsible to undo itself (the app manager only call the function)///
	CountofUndoed++;       ////increment the count of the undid actions
}




void ApplicationManager::RedoLastAction()
{
	if (CountofUndoed == 0) {//checking that if there isn't any undid actions

		pOut->PrintMessage("you can't redo");
		return;
	}
	last5Actions[ActionsCount - CountofUndoed]->redo();//otherwise we will call the virtual function of the redo of the current action
	////every actions is responsible to redo itself (the app manager only call the function)///
	CountofUndoed--; ////decrement the count of the undid actions
}
















//==================================================================================//
//						       Record System Functions								//
//==================================================================================//
bool ApplicationManager::IsRecording() const {
	return isRecording;
}

bool ApplicationManager::IsRecordClipAvailable() const {
	return RecordedActionCount != 0;
}

void ApplicationManager::ClearAll()
{
	for (int i = 0; i < FigCount; i++)//delete all the figures
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	for (int i = 0; i < ActionsCount; i++)//reset the undo and redo history
	{
		delete last5Actions[i];
		last5Actions[i] = NULL;
	}
	ActionsCount = 0;
	CountofUndoed = 0;
	FigID = 0;
	id = -1;
	if (SelectedFig != NULL)
	{
		delete SelectedFig;
		SelectedFig = NULL;
   }
	
	
	pOut->ClearDrawArea();
	pOut->PrintMessage("you clear all figures");
}

void ApplicationManager::ClearRecordingHistory()
{
	for (int i = 0; i < RecordedActionCount; i++)//reset recording history
	{
		if(RecordedAction)
			delete RecordedAction[i];
		RecordedAction[i] = NULL;
	}
	RecordedActionCount = 0;
}


void ApplicationManager::StartRecording(){
	isRecording = true;
}
void ApplicationManager::StopRectording(){
	isRecording = false;
}
void ApplicationManager::PlayRecord(){
	for (int i = 0; i < RecordedActionCount; i++) {
		AddAction(RecordedAction[i]);
		RecordedAction[i]->redo();
		//delete RecordedAction[i];
		pOut->PrintMessage(to_string(i / 60) + ":" + to_string(i % 60) + " / " + to_string(RecordedActionCount / 60) + ":" + to_string(RecordedActionCount % 60));
		UpdateInterface();
		Sleep(1 * 1000);
	}

	//RecordedActionCount = 0;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
int ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
	return FigID++;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	
	bool PointBelong = false;

	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i] != NULL) {
			PointBelong = FigList[i]->PointBelong(x, y);
			if (PointBelong) {

				return FigList[i];
			}
		}
	}

	
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}

CFigure* ApplicationManager::GetFigure(int id)
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->GetID() == id)
			return FigList[i];
	return NULL;
}


CFigure* ApplicationManager::GetSelectedFigure() const {
	return SelectedFig;
}

CFigure* ApplicationManager::IsSelected() const
{
	for (int i = 0; i < FigCount; i++)
		if (FigList[i]->IsSelected())
			return FigList[i];
	return NULL;
}
void ApplicationManager::DeleteFigure(int deleteID)
{
	int toDelete = 0;
	for (int i = 0; i < FigCount; i++) {

		if (FigList[i]->GetId() == deleteID) {
			toDelete = i;
			break;
		}
	}
	//delete FigList[toDelete];
	FigList[toDelete] = NULL;

	while (toDelete != FigCount - 1) {

		FigList[toDelete] = FigList[toDelete + 1];
		FigList[toDelete + 1] = NULL;
		toDelete++;
	}
	FigCount--;
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
		if (FigList[i]  && !FigList[i]->IsHide())
			FigList[i]->Draw(pOut);
				//Call Draw function (virtual member fn)
}





void ApplicationManager::show()
{
	for (int i = 0; i < FigCount; i++)
		FigList[i]->SetHide(false);
}


color ApplicationManager::GetFigColor(int i)
{
	if (FigList[i])
		return FigList[i]->GetFigColor();
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
