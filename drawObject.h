//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/17/2022
//Date Last Modified: 4/19/2022

#ifndef DRAWOBJECT_H_INCLUDED
#define DRAWOBJECT_H_INCLUDED

#include <iostream>
#include "Point.h"
#include "Line.h"
#include "color.h"
#include "SDL_Plotter.h"
using namespace std;


/*
* description: draws a Rectangle given a point and two ints
* return: void
* precondition: a point object, two integers, a SDL_Plotter, and a Color exist.
                the point should also be the topLeft coordinate of the rectangle
                and the integers must be greater than zero.
* postcondition: all of the objects are unchanged.
*
*/

void drawRectangle(Point topLeft, int width, int height, SDL_Plotter&, Color);

/*
* description: draws a circle given the middlePoint and the radius
* return: void
* precondition: radius must be greater than zero, and the Point must be in the middle of the circle
* postcondition: all of the objects are unchanged
*
*/

void drawCircle(Point middle, int radius, SDL_Plotter&, Color);

#endif // DRAWOBJECT_H_INCLUDED