//Author: Wesley Anastasi
//Assignment Title: Program 21
//Assignment Description: Point Struct
//Due Date: 4/6/2022
//Date Created: 4/4/2022
//Date Last Modified: 4/4/2022

#include "Point.h"

int x, y;
    
Point::Point(int xInput, int yInput)
{
    x = xInput;
    y = yInput;
}

void Point::display(ostream& out) const
{
    out << "(" << x << "," << y << ")" << endl;        
}


double Point::distance(const Point& point) const
{
    double distance;
    int diffx = pow(x-point.x,2);
    int diffy = pow(y-point.y,2);
    distance = sqrt(diffx + diffy);
    return distance;
}

Point Point::midPoint(const Point& point) const
{   
    double xCoord = (x+point.x)/2.0;
    double yCoord = (y+point.y)/2.0;
    if (xCoord != int(xCoord))
    {
        if (xCoord >= 0)
        {
            xCoord = int(xCoord)+1;
        }
        else
        {
            xCoord = int(xCoord)-1;
        }
    }
    if (yCoord != int(yCoord))
    {
        if (yCoord >= 0)
        {
            yCoord = int(yCoord)+1;
        }
        else
        {
            yCoord = int(yCoord)-1;
        }
    }
    Point mid(xCoord, yCoord);
    return mid;
}