#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   // forward declaration

class Input		//The application manager should have a pointer to this class
{
private:
	window *pWind;	//Pointer to the Graphics Window
public:
	Input(window *pW);		//Consturctor
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting(Output* pO) const ;	 //Returns a string entered by the user
	void getValidDrawPoint(Point& P) const;//check that the point that we click in the drawing area (neither tool nor status bar) 
	ActionType GetUserAction() const; //Read the user click and map to an action
	window* GetWindow() { return pWind; }
	~Input();
};

#endif