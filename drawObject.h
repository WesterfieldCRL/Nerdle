//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/17/2022
//Date Last Modified: 4/28/2022

#ifndef DRAWOBJECT_H_INCLUDED
#define DRAWOBJECT_H_INCLUDED

#include <iostream>
#include "Point.h"
#include "color.h"
#include "SDL_Plotter.h"
#include <fstream>
#include <cassert>
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

void drawRectangle(const Point& topLeft, int width, int height, SDL_Plotter&, const Color&);

/*
* description: draws a circle given the middlePoint and the radius
* return: void
* precondition: radius must be greater than zero, and the Point must be in the middle of the circle
* postcondition: all of the objects are unchanged
*
*/

void drawCircle(const Point& middle, int radius, SDL_Plotter&, const Color&);

/*
 * description: opens the aproppriate file for the character, and calls drawArray
 * return: void
 * precondition: some char, Point, SDL_Plotter and Color exist
 * postcondition: none
 *
*/

void drawChar(char, const Point&, SDL_Plotter&, const Color&, int size = 1);

/*
 * description: gets instructions from a file on drawing a char.
 * return: void
 * precondition: some Point, SDL_Plotter, Color, ifstream, and integer exist
 *               the file must have been opened and must be formatted properly
 * postcondition: none
 *
*/

void drawArray(const Point&, SDL_Plotter&, const Color&, ifstream&, int size);

void drawOutline(const Point& topLeft, int width, int height, SDL_Plotter& plotter, const Color& color);

#endif // DRAWOBJECT_H_INCLUDED