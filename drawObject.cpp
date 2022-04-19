//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/17/2022
//Date Last Modified: 4/19/2022

#include "drawObject.h"

void drawRectangle(Point topLeft, int width, int height, SDL_Plotter& plotter, Color color)
{
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

    for (int i = 0; i < r*2; i++)
    {
        for (int j = 0; j < r*2; j++)
        {
            x = i-r;
            y = j-r;

            if (x*x + y*y <= r*r)
            {
                plotter.plotPixel(x+middle.x, y+middle.y, color.R, color.G, color.B);   
            }
        }
    }
}

void drawHalfCircle(Point middle, Point top, int radius);