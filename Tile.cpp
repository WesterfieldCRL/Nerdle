//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/17/2022
//Date Last Modified: 4/21/2022

#include "Tile.h"

Tile::Tile()
{
    width = 1;
    height = 1;
}

Tile::Tile(const Point& point, int w, int h, const Color& c)
{
    p = point;
    width = w;
    height = h;
    color = c;
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



void Tile::draw(SDL_Plotter& plotter) const
{
    //create draw functions for characters
    drawRectangle(p, width, height, plotter, color);
}