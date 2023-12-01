#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

void Input::getValidDrawPoint(Point& P) const
{
	while ((P.y < UI.ToolBarHeight) || (P.y > UI.height - UI.StatusBarHeight))
	{
		GetPointClicked(P.x, P.y);
	}
}


string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	pWind->FlushKeyQueue();
	while(1)
	{
		pWind->WaitKeyPress(Key);
		pWind->FlushMouseQueue();
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		if (x < UI.MenuItemWidth * 13 && y < UI.ToolBarHeight) {

			int ClickedItemXIndex = (x / UI.MenuItemWidth);
			int CliekedItemYIndex = (y / UI.MenuItemHeight);

			int itemIndex = ClickedItemXIndex * 2 + CliekedItemYIndex;
			if (itemIndex > 4) {
				if (itemIndex == 5)return EMPTY;
				itemIndex--;
			}
			if (itemIndex > 17) {
				if (itemIndex == 18)return EMPTY;
				itemIndex--;
			}

			ActionType action = (ActionType)(itemIndex + DRW_RECT);
			if (action > EMPTY) return EMPTY;

			return action;

		}
		else if (y < UI.ToolBarHeight) {

			int ClickedItemXIndex = ((UI.width - x) / (UI.MenuItemWidth * 1.5));
			if (ClickedItemXIndex > 1) return EMPTY;

			ActionType action = (ActionType)(EMPTY - ClickedItemXIndex - 1);
			return action;

		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (((x) / (UI.MenuItemWidth * 3)) - (x - UI.MenuItemWidth * 2) / (UI.MenuItemWidth * 3)) * (x / (UI.MenuItemWidth * 3));
			if (x < (UI.MenuItemWidth * 2))
				return FIG_TYP;
			if (x > (UI.width - UI.MenuItemWidth * 2))
				return EXIT;
			if (x > (UI.width - UI.MenuItemWidth * 2 * 2))
				return TO_DRAW;
			switch (ClickedItemOrder)
			{
			case FIG_COLOR: return FIG_COL;
			case FIG_TYPE_COLOR: return FIG_TYP_COL;
			case RESTART: return RESET;
			default: return EMPTY;
			}

		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		return STATUS;	//just for now. This should be updated
	}
}
/////////////////////////////////
	
Input::~Input()
{
}
