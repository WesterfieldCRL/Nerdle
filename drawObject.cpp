//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/17/2022
//Date Last Modified: 4/19/2022

#include "drawObject.h"

void drawRectangle(Point topLeft, int width, int height, SDL_Plotter& plotter, Color color)
{
    //starts at the x and y coordinates and loops till the width and height.
    for (int y = topLeft.y; y < height+topLeft.y; y++)
    {
        for (int x = topLeft.x; x < width+topLeft.x; x++)
        {
            plotter.plotPixel(x,y,color.R,color.G,color.B);
        }
    }
}

void drawCircle(Point middle, int r, SDL_Plotter& plotter, Color color)
{
    int x, y;
    //loops through a square of size r*2
    for (int i = 0; i < r*2; i++)
    {
        for (int j = 0; j < r*2; j++)
        {
            //translating x and y to points based on a circle with center (0,0)
            x = i-r;
            y = j-r;

            //formula for graphing a circle is (x-h)^2 + (y-k)^2 = r^2
            //where (h,k) is the center of a circle and r is its radius.
            //since in this case the center is (0,0)
            //a point on the circle would fulfill x^2 + y^2 = r^2
            //since the center is (0,0), and it is being 'graphed' on standard axes
            //any point where x^2 + y^2 < r^2 will be inside the circle.
            if (x*x + y*y < r*r)
            {
                //adds the middle coords to x and y for placement on the plotter
                plotter.plotPixel(x+middle.x, y+middle.y, color.R, color.G, color.B);   
            }
        }
    }
}

void drawHalfCircle(Point middle, Point top, int radius);