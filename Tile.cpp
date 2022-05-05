//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/17/2022
//Date Last Modified: 4/29/2022

#include "Tile.h"

Tile::Tile()
{
    width = 1;
    height = 1;
    letter = '1';
}

Tile::Tile(const Point& point, int w, int h, const Color& c, char character)
{
    p = point;
    width = w;
    height = h;
    color = c;
    letter = character;
}

void Tile::setLocation(const Point& otherP)
{
    p.x = otherP.x;
    p.y = otherP.y;
}



void Tile::setWidth(int n)
{
    width = n;
}



void Tile::setHeight(int n)
{
    height = n;
}



void Tile::setColor(const Color& otherColor)
{
    color = otherColor;
}



void Tile::setLetter(char c)
{
    letter = c;
}



Point Tile::getLocation() const
{
    return p;
}



int Tile::getWidth() const
{
    return width;
}



int Tile::getHeight() const
{
    return height;
}



Color Tile::getColor() const
{
    return color;
}



char Tile::getLetter() const
{
    return letter;
}



void Tile::draw(SDL_Plotter& plotter, Color alt) const
{
    //made using width and height = 50, cannot vouch for other sizes.
    drawRectangle(p, width, height, plotter, color);
    if (letter != 'n')
    {
        Point temp(p.x+width/8,p.y+width/8);
        drawChar(letter, temp, plotter, alt,width/16);
    }
}

bool Tile::inside(int x, int y)
{
    bool returnValue = false;
    for (int i = p.y; i < height+p.y; i++)
    {
        for (int a = p.x; a < width+p.x; a++)
        {
            if (x == a && y == i)
            {
                returnValue = true;
            }
        }
    }
    return returnValue;
}
