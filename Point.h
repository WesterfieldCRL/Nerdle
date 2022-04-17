//Author: Wesley Anastasi
//Assignment Title: Program 21
//Assignment Description: Point Struct
//Due Date: 4/6/2022
//Date Created: 4/4/2022
//Date Last Modified: 4/4/2022

#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x, y;

    /*
    * description: constructer for the point
    * return: point with default values (0,0)
    * precondition: none or two integers exist
    * postcondition: a point has been created with deafult values (0,0)
    *                or values (x,y)
    *
    */

    Point(int = 0, int = 0);

    /*
    * description: displays the Point Object in the following format: (x,y)
    * return: void
    * precondition: ostream exists and can be used
    * postcondition: the Point Object has been displayed
    *
    */

    void display(ostream&) const;

    /*
    * description: returns the distance between two Point Objects
    * return: double
    * precondition: two Point Object exists
    * postcondition: the distance between two Point Objects has been returned
    *
    */

    double distance(const Point&) const;

    /*
    * description: returns the midpoint between two Point Objects.
                   If the midpoint has decimal coordinates 
                   the values should be rounded to the nearest integer.
    * return: Point
    * precondition: two Point Object exists
    * postcondition: a Point has been returned with x and y being the 
    *                midPoint of the input.
    *
    */

    Point midPoint(const Point&) const;
};

#endif // POINT_H_INCLUDED