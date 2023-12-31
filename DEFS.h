#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{  //A click on the status bar
    FIG_TYP,
    FIG_COL,
    FIG_TYP_COL,
    RESET,

    DRAWING_AREA,    //A click on the drawing area
    STATUS,            //A click on the status bar

    ///TODO: Add the other action types of the two modes
    DRW_RECT, //Recangle item in menu
    DRW_Circ,
    DRW_Square,
    DRW_Hexa,
    DRW_Trig,
    // group 1 count = 5

    DRW_Red,
    DRW_Orange,
    DRW_Blue,
    DRW_Yellow,
    DRW_Green,
    DRW_Black,
    // group 2 count = 6 

    Pencile_Tool,
    Move_Tool,
    Fill_Tool,
    UNDO,
    Delete,
    REDO,
    ClearBoard,
    RESIZE_FIGURE,
    DRAG,
    // group 3 count = 9

    START_RECORD,
    Selection_Tool,
    STOP_RECORD,
    SAVE_RECORD,
    PLAY_RECORD,
    LOAD_RECORD,
    Sound_ON,
    MUTE,
    // group 4 count = 8

    TO_DRAW,        //Switch interface to Draw mode
    TO_PLAY,        //Switch interface to Play mode
    EXIT,            //Exit

    EMPTY,            //A click on empty place in the toolbar
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr = WHITE;	//FiHITEll color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif