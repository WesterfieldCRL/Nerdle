//Author: Wesley Anastasi
//Assignment Title: Program 23
//Assignment Description: Line class
//Due Date: 4/11/2022
//Date Created: 4/6/2022
//Date Last Modified: 4/6/2022

#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include <ostream>
#include <iostream>
#include "Point.h"
#include <cmath>

using namespace std;


class Line{
	private:
		Point p1, p2;

	public:

		/*
		* description: constructor: set p1 and p2 to Points a and b
					   respectivley
		* return: Line Object
		* precondition: none
		* postcondition: a Line object has been created
		*
		*/

		Line(Point=Point(1,1), Point=Point(0,0));

		/*
		* description: sets point 1
		* return: void 
		* precondition: a line object exists
		* postcondition: the object is unchanged
		*
		*/

 		void setFirstPoint(const Point&);

		/*
		* description: sets point 2
		* return: void
		* precondition: a line object exists
		* postcondition: the object is unchanged
		*
		*/

		void setSecondPoint(const Point&);

		/*
		* description: returns a copy of point 1
		* return: Point obejct
		* precondition: a Line object exists
		* postcondition: the object is unchanged
		*
		*/

		Point getFirstPoint() const;

		/*
		* description: returns a copy of point 2
		* return: Point object
		* precondition: a Line object exists
		* postcondition: the object is unchanged
		*
		*/

		Point getSecondPoint() const;

		/*
		* description: returns true if the line has a slope
		* return: boolean
		* precondition: a Line Object exists
		* postcondition: the object is unchanged
		*
		*/

		bool hasSlope() const;

		/*
		* description: returns the slope of the line
		* return: double
		* precondition: a Line objec exists
		* postcondition: the object is unchanged
		*
		*/

        double slope() const;

		/*
		* description: returns the y-intercept
		* return: double
		* precondition: a Line object exists
		* postcondition: the object is unchanged
		*
		*/

		double yIntercept() const;

		/*
		* description: returns true if the lines are parallel
		* return: boolean
		* precondition: two Line objects exist
		* postcondition: none of the objects have been changed
		*
		*/

		bool isParallel(const Line&) const;

		/*
		* description: returns true if the lines are collinear
		* return: boolean
		* precondition: two Line Object's exist
		* postcondition: none of the objects have been chnaged
		*
		*/
	
		bool isCollinear(const Line&) const;

		/*
		* description: returns true if the lines are perpendicular
		* return: boolean
		* precondition: two Line Object's exist
		* postcondition: none of the objects have been changed
		*
		*/

		bool isPerpendicular(const Line&) const;

		/*
		* description: returns the Point where the two lines intersect
		* return: Point Object
		* precondition: two Line Object's exist and intersect
		* postcondition: none of the Line Object's have been changed
		*
		*/

		Point intersect(const Line&) const;

		/*
		* description: prints line in slope intercept form
		* return: void
		* precondition: there exists some output stream
		* postcondition: nothing has been changed, and the 
						 formula has been outputted
		*
		*/

		void display(ostream&) const;
};


#endif // LINE_H_INCLUDED