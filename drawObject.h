//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/17/2022
//Date Last Modified: 4/18/2022

#ifndef DRAWOBJECT_H_INCLUDED
#define DRAWOBJECT_H_INCLUDED

#include <iostream>
#include "Point.h"
#include "Line.h"
#include "color.h"
#include "SDL_Plotter.h"
using namespace std;


/*
* description: draws a line given a line object.
* return: void
* precondition: a line object, a SDL_Plotter, and a color object exist
* postcondition: all of the objects are unchanged.
*
*/

void drawLine(Line, SDL_Plotter&, Color);

/*
* description:
* return:
* precondition:
* postcondition:
*
*/

void drawQuadrilateral(const Point topRight, const Point topLeft, const Point bottomRight, const Point bottomLeft, SDL_Plotter&, Color);

/*
* description:
* return:
* precondition:
* postcondition:
*
*/

void drawCircle(Point middle, int radius);

/*
* description:
* return:
* precondition:
* postcondition:
*
*/

void drawHalfCircle(Point middle, Point top, int radius);




#endif // DRAWOBJECT_H_INCLUDED