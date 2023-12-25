#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"

//Add Rectangle Action class
class AddRectAction: public Action
{
private:
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
	int ID;
public:
	AddRectAction(ApplicationManager *pApp);
	Action* clone() const { return new AddRectAction(*this); }
	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;

	virtual  void undo();//the undo of add rectangle action
	virtual void redo();//the redo of add rectangle action
	
};

#endif