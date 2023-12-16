#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include"Actions/Action.h"
//#include "Figures/CSquare.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	Action* actionlist[MaxFigCount];
	CFigure* SelectedFig; //Pointer to the selected figure
	int actionsCount;
	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
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
	CFigure* IsSelected() const;
	CFigure* DeleteFigure(int);          //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void ReloadFigures() const;

	//Save system
	void SaveAll(ofstream &file) const;
	void LoadAll(CFigure** list, int count);
	
	void UndoLastAction();
	void RedoLastAction();
	
};

#endif