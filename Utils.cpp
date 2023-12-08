#include "Utils.h"
#include <iostream>
#include <string>
#include <fstream>
#include "CMUgraphicsLib/colors.h"
#include "Figures/CFigure.h"
#include "Figures/CCircle.h"

//CFigure* NameToFigure(std::string id) {
//	if (id == "circle")
//		return CCircle();
//	else if (id == "hexa")
//		return RED;
//	else if (id == "rectangle")
//		return BLUE;
//	else if (id == "square")
//		return BLACK;
//	else if (id == "triangle")
//		return YELLOW;
//}

std::string ColorToName(color color) {
	if (color == GREEN)
		return "GREEN";
	else if (color == RED)
		return "RED";
	else if (color == BLUE)
		return "BLUE";
	else if (color == BLACK)
		return "BLACK";
	else if (color == YELLOW)
		return "YELLOW";
	else if (color == ORANGE)
		return "ORANGE";
	else
		return "NONE";
}

color NameToColor(std::string id) {
	if (id == "GREEN")
		return GREEN;
	else if (id == "RED")
		return RED;
	else if (id == "BLUE")
		return BLUE;
	else if (id == "BLACK")
		return BLACK;
	else if (id == "YELLOW")
		return YELLOW;
	else if (id == "ORANGE")
		return ORANGE;
	else
		return PINK;
}

std::ofstream& operator<<(std::ofstream& out, color& color) {
	out << ColorToName(color);
	return out;
}

std::ifstream& operator>>(std::ifstream& in, color& color) {
	std::string id;
	in >> id;
	color = NameToColor(id);
	return in;
}