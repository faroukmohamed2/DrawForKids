#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItemGR // the shapes 
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT, //Recangle item in menu
	ITM_Circ,
	ITM_Square,
	ITM_Hexa,
	ITM_Trig,
	// group 1 count = 5 

	ITM_Red,
	ITM_Orange,
	ITM_Blue,
	ITM_Yellow,
	ITM_Green,
	ITM_Black,
	// group 2 count = 6 

	ITM_Border,
	ITM_Move,
	ITM_Fill,
	ITM_Undo,
	ITM_Delete,
	ITM_Redo,
	ITM_ClearALL,
	ITM_ResizeFigure,
	ITM_Drag,
	// group 3 count = 9

	ITM_Start,
	ITM_Select,
	ITM_Stop,
	ITM_Save,
	ITM_Play,
	ITM_Load,
	ITM_Sound,
	ITM_Mute,
	// group 4 count = 8



	ITM_Game,
	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT			//no. of menu items ==> This should be the last line in this enum

};

#define NumGR1 5
#define NumGR2 6
#define NumGR3 9
#define NumGR4 8


enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	//TODO: Add more items names here
	FIG_TYPE,
	FIG_COLOR,
	FIG_TYPE_COLOR,
	RESTART,
	SWITCH_DRAW,
	ITM_EXIT_PLAY,		//Exit item
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth,	//Width of each item in toolbar menu
	    MenuItemHeight;


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;	
	bool FillState;//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif