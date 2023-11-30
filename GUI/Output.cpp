#include "Output.h"


Output::Output()
{
	MenuItemImagesGR[ITM_RECT]   =(image) "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImagesGR[ITM_Circ]   =(image)"images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImagesGR[ITM_Square] =(image) "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImagesGR[ITM_Hexa]   =(image) "images\\MenuItems\\Menu_Hexa.jpg";
	MenuItemImagesGR[ITM_Trig]   =(image) "images\\MenuItems\\Menu_Trig.jpg";

	MenuItemImagesGR[ITM_Red]    =(image) "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImagesGR[ITM_Orange] =(image) "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImagesGR[ITM_Blue]   =(image) "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImagesGR[ITM_Yellow] =(image) "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImagesGR[ITM_Green]  =(image) "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImagesGR[ITM_Black]  =(image) "images\\MenuItems\\Menu_Black.jpg";

	MenuItemImagesGR[ITM_Border] =(image) "images\\MenuItems\\Menu_Border.jpg";
	MenuItemImagesGR[ITM_Move]   =(image) "images\\MenuItems\\Menu_Move.jpg";
	MenuItemImagesGR[ITM_Fill]   =(image) "images\\MenuItems\\Menu_Fill.jpg";
	MenuItemImagesGR[ITM_Undo]   =(image) "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImagesGR[ITM_Delete] =(image) "images\\MenuItems\\Menu_Del.jpg";
	MenuItemImagesGR[ITM_Redo]   =(image) "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImagesGR[ITM_ClearALL]=(image) "images\\MenuItems\\Menu_Clear.jpg";
	MenuItemImagesGR[ITM_Start]  =(image) "images\\MenuItems\\Menu_Start.jpg";
	MenuItemImagesGR[ITM_Select] =(image) "images\\MenuItems\\Menu_Select.jpg";
	MenuItemImagesGR[ITM_Stop]   =(image) "images\\MenuItems\\Menu_Stop.jpg";
	MenuItemImagesGR[ITM_Save]   =(image) "images\\MenuItems\\Menu_Save.jpg";
	MenuItemImagesGR[ITM_Play]   =(image) "images\\MenuItems\\Menu_Play.jpg";
	MenuItemImagesGR[ITM_Load]   =(image) "images\\MenuItems\\Menu_Load.jpg";

	MenuItemImagesGR[ITM_Game] =(image) "images\\MenuItems\\Menu_Game.jpeg";
	MenuItemImagesGR[ITM_EXIT] =(image) "images\\MenuItems\\Menu_Exit.jpg";

	PlayMenuItems[FIG_TYPE]       =(image) "images\\MenuItems\\fig_type.jpg";
	PlayMenuItems[FIG_COLOR]      =(image) "images\\MenuItems\\fig_color.jpg";
	PlayMenuItems[FIG_TYPE_COLOR] =(image) "images\\MenuItems\\fig_color_type.jpg";
	PlayMenuItems[RESTART]        =(image) "images\\MenuItems\\restart.jpg";
	PlayMenuItems[SWITCH_DRAW]    =(image) "images\\MenuItems\\draw_mode.jpg";
	PlayMenuItems[ITM_EXIT_PLAY]  =(image) "images\\MenuItems\\Menu_Exit.jpg";

	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 60;
	UI.MenuItemWidth = 60;
	UI.MenuItemHeight = 30;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	//CreateDrawToolBar();
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	//Draw White Box in empty spaces
	UI.InterfaceMode = MODE_DRAW;
	pWind->SetPen( WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(UI.MenuItemWidth * 13, 0, UI.width - UI.MenuItemWidth * 2 * 1.5, UI.ToolBarHeight, FILLED);
	

	int Printed = 0; 
	int UpperItems = 0; 
	DrawGROUP(UpperItems,Printed ,NumGR1);
	DrawGROUP (UpperItems, Printed , NumGR2);
	DrawGROUP(UpperItems, Printed , NumGR3);
	DrawGROUP (UpperItems, Printed , NumGR4);
	
	pWind->DrawImage(MenuItemImagesGR[Printed++], UI.width - (3 * UI.MenuItemWidth), 0, 1.5 * UI.MenuItemWidth, (UI.ToolBarHeight));
	pWind->DrawImage(MenuItemImagesGR[Printed], UI.width - (1.5 * UI.MenuItemWidth), 0, 1.5 * UI.MenuItemWidth, UI.ToolBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawGROUP(int& UpperITEMS ,int& Printed , const int ITEMS ) const  {

	int x = 2 * UpperITEMS;
	
	for (int i = Printed; i < ITEMS + Printed; i++) {
		int pX = (x++ / 2) * UI.MenuItemWidth;
		int pY = (UI.ToolBarHeight / 2) * (1 - (x % 2));
		pWind->DrawImage(MenuItemImagesGR[i], pX, pY, UI.MenuItemWidth, (UI.MenuItemHeight));
	}

	//Draw White icons in empty buttons
	if (x % 2 == 1) {
		int pX = ((x) / 2) * UI.MenuItemWidth;
		int pY = (UI.ToolBarHeight / 2);

		pWind->SetPen(WHITE, 1);
		pWind->SetBrush(WHITE);
		pWind->DrawRectangle(pX, pY, pX+UI.MenuItemWidth, pY+UI.MenuItemHeight, FILLED);
	}

	UpperITEMS += (ITEMS+1) / 2;
	Printed += ITEMS; 
}



void Output::CreatePlayToolBar() const
{
	/*output_play_mode*/
	UI.InterfaceMode = MODE_PLAY;
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight, FILLED);

	for (int i = 0; i < PLAY_ITM_COUNT - 2; i++)
		pWind->DrawImage(PlayMenuItems[i], 3 * i * UI.MenuItemWidth, 0, UI.MenuItemWidth * 2, UI.ToolBarHeight);
	pWind->DrawImage(PlayMenuItems[ITM_EXIT_PLAY], UI.width - UI.MenuItemWidth * 2, 0, UI.MenuItemWidth * 2, UI.ToolBarHeight);
	pWind->DrawImage(PlayMenuItems[SWITCH_DRAW], UI.width - UI.MenuItemWidth * 2 * 2, 0, UI.MenuItemWidth * 2, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	/*end_output_play_mode*/
	///TODO: write code to create Play mode menu
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//



void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
//this function takes two points the up-left and the down-right conrners of the rectangle 
//and it take the graphics information of the wanted shape to draw it 
//selected is a boolean express is used for highlighting the shape
{
	color DrawingClr;//the drawing color that will we use
	if (selected)      //if we select the figure
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;//Figure will be drawn with the color stored In RectGfxInfo

	pWind->SetPen(DrawingClr, 1);//set the pen with the draw color and width 1
	drawstyle style;
	if (RectGfxInfo.isFilled)// if we want to fill the figure
	{
		style = FILLED;//we will make the style to filled
		pWind->SetBrush(RectGfxInfo.FillClr);//set the brush with the wanted fill color
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);//call the function that draw a rectangle and we will pass to it the 2 corners and style
	
}


void Output::DrawSquare(Point P1, GfxInfo squareGfxInfo, bool selected) const
//this function take only one point (the center of the square) and we calc the vertices by the geometry of the square
//and it takes the graphics information of the wanted shape to draw it 
//selected is a boolean express is used for highlighting the shape
{
	const int length = 70; //it is a default number that used to calc the vertices of the square with respect to the center "p1"
	color DrawingClr; //the drawing color that we use to draw the border of the shape
	if (selected)     //if we select the figure
		DrawingClr = UI.HighlightColor;//Figure should be drawn highlighted
	else
		DrawingClr = squareGfxInfo.DrawClr;//Figure will be drawn with the color stored In squareGfxInfo

	pWind->SetPen(DrawingClr, 1);//set the pen with the draw color and width 1
	drawstyle style;
	if (squareGfxInfo.isFilled)// if we want to fill the figure
	{
		style = FILLED;//we will make the style to filled
		pWind->SetBrush(squareGfxInfo.FillClr);//set the brush with the wanted fill color
	}
	else
		style = FRAME;


	pWind->DrawRectangle((P1.x) - length, (P1.y) - length, (P1.x) + length, (P1.y) + length, style);//call the function that draw a rectangle and we pass the corners of the square (we calculated them) and style
	CreateDrawToolBar();//we redraw the tool bar becaue of the case . a part of the square is in the region of tool bar
}



void Output::DrawTrig(Point P1, Point P2, Point P3, GfxInfo TrigGfxInfo, bool selected) const
//this function takes three points (the triangle vertices)
//and it takes the graphics information of the wanted shape to draw it 
//selected is a boolean express is used for highlighting the shape

{
	color DrawingClr;
	if (selected)  //if we select the figure
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TrigGfxInfo.DrawClr; //Figure will be drawn with the color stored In TrigGfxInfo

	pWind->SetPen(DrawingClr, 1);  //set the pen with the draw color and width 1
	drawstyle style;
	if (TrigGfxInfo.isFilled) // if we want to fill the figure
	{
		style = FILLED; //we will make the style to filled
		pWind->SetBrush(TrigGfxInfo.FillClr); //set the brush with the wanted fill color
	}
	else
		style = FRAME;


	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);//call the triangle draw function and pass to it the 3 vertices and the style
	
}

void Output::DrawHexa(Point P1, GfxInfo HexaGfxInfo, bool selected) const
//this function takes one point (the hexagon center)
//and it take the graphics information of the wanted shape to draw it 
//selected is a boolean express is used for highlighting the shape

{
	float l = 100;//it is a default number that used to calc the vertices of the hexagon with respect to the center "p1"
	int X[6];//the x components of the vertices
	int Y[6];//the y components of the vertices
/////here we calc the vertices with respect to the center by geometry
	X[3] = (P1.x) + l;
	X[0] = (P1.x) - l;
	Y[0] = Y[3] = P1.y;
	X[1] = X[5] = (P1.x) - (l / 2);
	X[2] = X[4] = (P1.x) + (l / 2);
	Y[4] = Y[5] = (P1.y) + (0.8660254 * l);
	Y[1] = Y[2] = (P1.y) - (0.8660254 * l);
/////////

	color DrawingClr;
	if (selected)  //if we select the figure
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexaGfxInfo.DrawClr; //Figure will be drawn with the color stored In HexaGfxInfo

	pWind->SetPen(DrawingClr, 1);   //set the pen with the draw color and width 1
	drawstyle style;
	if (HexaGfxInfo.isFilled) // if we want to fill the figure
	{
		style = FILLED; //we will make the style to filled
		pWind->SetBrush(HexaGfxInfo.FillClr); //set the brush with the wanted fill color
	}
	else
		style = FRAME;


	pWind->DrawPolygon(X, Y, 6, style);//we call the polygon draw function and pass two X and y components arrays , number of vertices "6" and the style
	CreateDrawToolBar();//we redraw the tool bar becaue of the case . a part of the hexagon is in the region of tool bar
}

void Output::DrawCircle(Point P1, Point P2, GfxInfo circleGfxInfo, bool selected) const
//this function takes two points (the center of the circle and another one point on the circle)
//and it takes the graphics information of the wanted shape to draw it 
//selected is a boolean express is used for highlighting the shape
{
	float Radius = sqrt(pow((P1.x) - (P2.x), 2) + pow((P1.y) - (P2.y), 2));//calc the radius of the circle because we need it in the circle drawing function
	color DrawingClr;
	if (selected)  //if we select the figure
		DrawingClr = UI.HighlightColor;  //Figure should be drawn highlighted
	else
		DrawingClr = circleGfxInfo.DrawClr; //Figure will be drawn with the color stored In circlrGfxInfo

	pWind->SetPen(DrawingClr, 1); //set the pen with the draw color and width 1
	drawstyle style;
	if (circleGfxInfo.isFilled) // if we want to fill the figure
	{
		style = FILLED; //we will make the style to filled
		pWind->SetBrush(circleGfxInfo.FillClr); //set the brush with the wanted fill color
	}
	else
		style = FRAME;


	pWind->DrawCircle(P1.x, P1.y, Radius, style); // call the circle draw function and pass to it (center , radius"calculated") and style
	CreateDrawToolBar(); //we redraw the tool bar becaue of the case . a part of the circle is in the region of tool bar
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

