//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/17/2022
//Date Last Modified: 4/18/2022

#include "drawObject.h"

void drawLine(Line line, SDL_Plotter& plotter, Color color)
{
    Point p;
    //gets the coordinates of a box containg the line, with x1,y1 being the top left,
    //and x2, y2 being the bottom right
    int x1, x2, y1, y2;
    if (line.getFirstPoint().x <= line.getSecondPoint().x)
    {
        x1 = line.getFirstPoint().x;
        x2 = line.getSecondPoint().x;
    }
    else
    {
        x1 = line.getSecondPoint().x;
        x2 = line.getFirstPoint().x;
    }

    if (line.getFirstPoint().y <= line.getSecondPoint().y)
    {
        y1 = line.getFirstPoint().y;
        y2 = line.getSecondPoint().y;
    }
    else
    {
        y1 = line.getSecondPoint().y;
        y2 = line.getFirstPoint().y;
    }

    //loops through each pixel in the box and check if it is on the line.
    //if it is on the line, then it is drawn.
    for (int y = y1; y <= y2; y++)
    {
        for (int x = x1; x <= x2; x++)
        {
            p.x = x;
            p.y = y;
            if (line.isPointOnLine(p))
            {
                plotter.plotPixel(p.x,p.y, color.R, color.G, color.B);
            }
        }
    }
}

void drawQuadrilateral(const Point p1, const Point p2, const Point p3, const Point p4, SDL_Plotter& plotter, Color color)
{
    //same as in drawLine, find the box that the quadrilateral resides in
    //int x1,x2,y1,y2;
    //Point points[2];
    //Line line;
    Line line1(p1,p2);
    Line line2(p2,p3);
    Line line3(p3,p4);
    Line line4(p4,p1);
    drawLine(line1, plotter, color);
    drawLine(line2, plotter, color);
    drawLine(line3, plotter, color);
    drawLine(line4, plotter, color);
    bool sorted = false;
    int xNums[4] = {p1.x, p2.x, p3.x, p4.x};
    int yNums[4] = {p1.y, p2.y, p3.y, p4.y};
    //sort x and y to fine the top left point and the bottom right point of the box
    while (!sorted)
    {
        sorted = true;
        for (int i = 0; i < 3; i++)
        {
            if (xNums[i] > xNums[i+1])
            {
                swap(xNums[i], xNums[i+1]);
                sorted = false;
            }
            if (yNums[i] > yNums[i+1])
            {
                swap(yNums[i], yNums[i+1]);
                sorted = false;
            }
        }
    }
    //after I started this I realized that I dont have a function for checking if two lines intersect,
    //which this function was going to depend on.
}

void drawCircle(Point middle, int radius);

void drawHalfCircle(Point middle, Point top, int radius);