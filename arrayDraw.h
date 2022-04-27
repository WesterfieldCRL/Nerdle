//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/20/2022
//Date Last Modified: 4/20/2022

#ifndef ARRAYDRAW_H_INCLUDED
#define ARRAYDRAW_H_INCLUDED

#include "Point.h"
#include "SDL_Plotter.h"
#include "color.h"
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

/*
 * description:
 * return:
 * precondition:
 * postcondition:
 *
*/

void drawChar(char, const Point&, SDL_Plotter&, const Color&, int size = 1);

void drawArray(const Point&, SDL_Plotter&, const Color&, ifstream&, int size);


#endif // ARRAYDRAW_H_INCLUDED