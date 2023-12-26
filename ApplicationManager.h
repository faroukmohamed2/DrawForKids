#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"
#include"Actions/Action.h"
#include<Windows.h>
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200, MaxRecordActionCount = 20 };	//Max no of figures
	int FigID = 0;
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure

	//undo and redo variables
	Action* last5Actions[5];//this array is pointed to that last five actions that excuted (but is undoable)->we use it in the undo and redo
	int CountofUndoed;//the count of the undid actions 
	int ActionsCount;//the current number of the actions in the last five actions array

	//Recording Variables
	bool isRecording = false;
	Action* RecordedAction[MaxRecordActionCount];
	int RecordedActionCount = 0;

	//sound variables
	bool SoundState=true;//it is a boolean expression is used to know the current sound state
						 //its by default  true

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
public:	
	int acttype;//test
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	// -- Figures Management Functions
	int AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const;
	CFigure* GetFigure(int id);
	//int GetFigCount() const;
	CFigure* IsSelected() const;
	CFigure* GetSelectedFigure() const;
	void DeleteFigure(int);          //Search for a figure given a point inside the figure
	void show();
	void hide(int);
	color GetFigColor(int);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	void ReloadFigures() const;


	//undo and redo system
	void addAction(Action* ptr);//this function is used to add an action to the array of the last 5 actions
	void UndoLastAction();//undo the last action in the last five action array(every action is responsible to undo itself)
	void RedoLastAction();//redo the last undid action in the last five action array(every action is responsible to redo itself)






	


	//Save system
	void SaveAll(ofstream &file) const;
	void LoadAll(CFigure** list, int count);
	int GetFigCount() const;

	//RecordSystem
	void StartRecording();
	void StopRectording();
	void PlayRecord();
	bool IsRecording() const;
	bool IsRecordClipAvailable() const;

	//Clear all system
	void ClearAll();//this functon is used to clear the figlist and the the undo and redo history
	void ClearRecordingHistory();//this function is used to clear the recording history

	//Sound system
	void enableSound();//this function is used to enable the sound in the SoundOn Action
	void MuteSound();//this function is used to mute the sound in the MuteSound action
	bool GetSoundState() const;//getter we use to know the current state of the sound 
};

#endif