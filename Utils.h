#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "CMUgraphicsLib/colors.h"
#include "Figures/CFigure.h"

#ifndef UTILS_H
#define UTILS_H

//CFigure* NameToFigure(std::string id);

std::string ColorToName(color color);

color NameToColor(std::string id);

std::ofstream& operator<<(std::ofstream& out, color& color);

std::ifstream& operator>>(std::ifstream& in, color& color);

#endif // UTILS_H
