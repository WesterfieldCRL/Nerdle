
//Author: Wesley Anastasi, Madison Thomas, Seth Kacura, Chris Garcia, Christian Saldana, Daigon Fontenot
//Assignment Title: Nerdle
//Assignment Description: create Nerdle w/ SDL plotter
//Due Date: 5/5/2022
//Date Created: 4/15/2022
//Date Last Modified: 5/5/2022

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

void drawChar(char character, const Point& p, SDL_Plotter& plotter, const Color& color, int size)
{
    ifstream file;
    switch (character)
    {
        case '0':
            file.open("zero.dat");
            break;
        case '1':
            file.open("one.dat");
            break;
        case '2':
            file.open("two.dat");
            break;
        case '3':
            file.open("three.dat");
            break;
        case '4':
            file.open("four.dat");
            break;
        case '5':
            file.open("five.dat");
            break;
        case '6':
            file.open("six.dat");
            break;
        case '7':
            file.open("seven.dat");
            break;
        case '8':
            file.open("eight.dat");
            break;
        case '9':
            file.open("nine.dat");
            break;
        case 'N':
            file.open("N.dat");
            break;
        case 'E':
            file.open("E.dat");
            break; 
        case 'R':
            file.open("R.dat");
            break;
        case 'D':
            file.open("D.dat");
            break;
        case 'L':
            file.open("L.dat");
            break;
        case 'I':
            file.open("I.dat");
            break;
        case 'W':
            file.open("W.dat");
            break;
        case 'O':
            file.open("O.dat");
            break;
        case 'S':
            file.open("S.dat");
            break;
        case '!':
            file.open("Exclamation.dat");
            break;
        case '+':
            file.open("plus.dat");
            break;
        case '-':
            file.open("minus.dat");
            break;
        case '/':
            file.open("divide.dat");
            break;
        case '*':
            file.open("multiply.dat");
            break;
        case '=':
            file.open("equals.dat");
            break;
        case SDLK_DELETE:
            file.open("back.dat");
            break;
        case SDLK_RETURN:
            file.open("enter.dat");
            break;
        default:
            file.open("characterNotFound");
            break;
    }
    assert(file);
    drawArray(p, plotter, color, file, size);
}

void drawArray(const Point& point, SDL_Plotter& plotter, const Color& color, ifstream& file, int size)
{
    int row;
    int col;
    int num;
    file >> row >> col;
    //spaces the pixels size distance apart, then creates a pixel of 2*size width.
    for (int y = 0; y < row * size; y+=size)
    {
        for (int x = 0; x < col * size; x+=size)
        {
            file >> num;
            if (num == 1)
            {
                for (int i = -size; i < size; i++)
                {
                    for (int j = -size; j < size; j++)
                    {
                        plotter.plotPixel(x + point.x + j, y + point.y + i, color.R, color.G, color.B);
                    }
                }
            }
        }
    }

    file.close();
}

void drawOutline (const Point& topLeft, int width, int height, SDL_Plotter& plotter, const Color& color)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if (x ==0 || y == 0 || x == width-1 || y == height-1)
            {
                plotter.plotPixel(x+topLeft.x, y + topLeft.y, color.R, color.G, color.B);
            }
        }
    }
}
