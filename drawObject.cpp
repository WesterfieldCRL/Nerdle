//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/17/2022
//Date Last Modified: 4/21/2022

#include "drawObject.h"

void drawRectangle(const Point& topLeft, int width, int height, SDL_Plotter& plotter, const Color& color)
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

void drawCircle(const Point& middle, int r, SDL_Plotter& plotter, const Color& color)
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

void drawOne(const Point& topLeft, int width, int height, SDL_Plotter& plotter, const Color& background, const Color& foreground)
{
    int stemSpacing = width/3;
    int bottomRectSpacing = height/7;
    int noseHeight = height/7;
    int noseSlope = 2;
    int xNum = stemSpacing;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if ((x > stemSpacing && x < width-stemSpacing) || (y > height-bottomRectSpacing))
            {
                plotter.plotPixel(x + topLeft.x, y + topLeft.y, foreground.R, foreground.G, foreground.B);
            }
        }
    }
    //assembling the nose of the 1
    //needs to be rewritten because it cant be resized unlike the rest of the function
    for (int y = 0; xNum >= 0; y++)
    {
        Point temp(xNum + topLeft.x, y + topLeft.y);
        drawRectangle(temp, noseSlope, noseHeight, plotter, foreground);
        xNum-=noseSlope;
    }
}

void drawTwo(const Point& topLeft, int width, int height, SDL_Plotter& plotter, Color background, const Color& foreground)
{
    Point middle(topLeft.x+width/2, topLeft.y+width/2);
    double xFactor;
    drawCircle(middle, width/2, plotter, foreground);
    drawCircle(middle, width/4,plotter, background);
    middle.x = topLeft.x;
    drawRectangle(middle, width, width/2, plotter, background);

    //drawing middle of 2
    middle.x = topLeft.x + (width-width/4);
    xFactor = static_cast<double>(width-(width/2-width/4))/((height-height/5)-(width/2));
    for (int i = width/2; i < (height-height/5); i++)
    {
        middle.y = i + topLeft.y;
        drawRectangle(middle, width/2-width/4, 1, plotter, foreground);
        
    }

    middle.x = topLeft.x;
    middle.y = topLeft.y + (height-height/5);
    drawRectangle(middle, width, height/5, plotter, foreground);
}

//this is mainly here for testing purposes
void drawOutline (const Point& topLeft, int width, int height, SDL_Plotter& plotter, const Color& background, const Color& foreground)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x ==0 || y == 0 || x == width-1 || y == height-1)
            {
                plotter.plotPixel(x+topLeft.x, y + topLeft.y, foreground.R, foreground.G, foreground.B);
            }
        }
    }
}