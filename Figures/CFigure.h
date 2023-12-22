#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>
#include "../Utils.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	bool hide;
	/// Add more parameters if needed.
	
	void SavePoint(ofstream& OutFile, Point& point);

	void LoadPoint(ifstream& OutFile, Point& point);
public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure(int id);

	virtual CFigure* clone() = 0;

	bool IsFilled();
	virtual string GetName() const = 0;
	int GetId() const;
	void SetHide(bool);
	bool IsHide() const;
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual void PrintInfo(Output* pOut) = 0;

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	color GetFigColor() const;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual bool PointBelong(int x , int y) = 0;
	virtual Point getlocation() { return Point(); }
	 bool IsInTriangle(Point , Point , Point , Point );
	 double CalcAreaTriangle(Point, Point, Point);
	 void SetId(int);
	 int GetID();
	 void Delete(Output* pOut) ;
	 bool getfillstate();
	 virtual void Move(Point) = 0;
	 
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual ~CFigure() = 0;
	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif