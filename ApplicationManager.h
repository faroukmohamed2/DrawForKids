#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
//#include "Figures/CSquare.h"
#include"Actions/Action.h"
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	int FigID = 0;
private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* SelectedFig; //Pointer to the selected figure
	Action* last5Actions[5];
	int CountofUndoed;
	int ActionsCount;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	int id = -1;
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
	CFigure* IsSelected() const;
	void DeleteFigure(int);          //Search for a figure given a point inside the figure
	void show();
	void hide(int);
	color GetFigColor(int);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void addAction(Action* ptr);
	void UndoLastAction();
	void RedoLastAction();
	void ReloadFigures() const;



	







	//Save system
	void SaveAll(ofstream &file) const;
	void LoadAll(CFigure** list, int count);
	int GetFigCount() const;


};

#endif