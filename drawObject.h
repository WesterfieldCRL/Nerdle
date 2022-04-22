//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/17/2022
//Date Last Modified: 4/21/2022

#ifndef DRAWOBJECT_H_INCLUDED
#define DRAWOBJECT_H_INCLUDED

#include <iostream>
#include "Point.h"
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

void drawRectangle(const Point& topLeft, int width, int height, SDL_Plotter&, const Color&);

/*
* description: draws a circle given the middlePoint and the radius
* return: void
* precondition: radius must be greater than zero, and the Point must be in the middle of the circle
* postcondition: all of the objects are unchanged
*
*/

void drawCircle(const Point& middle, int radius, SDL_Plotter&, const Color&);

//Note: the following functions are for proof of concept purpuses
//The goal is to eventually merge these into a class or one function,
//so that you provide the function with a character and it plots the character

void drawOne(const Point& topLeft, int width, int height, SDL_Plotter&, const Color& background, const Color& foreground);

void drawTwo(const Point& topLeft, int width, int height, SDL_Plotter&, Color background, const Color& foreground);

void drawThree(const Point& topLeft, int width, int height, SDL_Plotter&, const Color& background, const Color& foreground);

#endif // DRAWOBJECT_H_INCLUDED