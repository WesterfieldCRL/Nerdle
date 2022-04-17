//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 
//Date Last Modified: 

#include "Tile.h"

Tile::Tile()
{
    width = 1;
    height = 1;
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
    //create character class
    for (int y = p.y; y < height; y++)
    {
        for (int x = p.x; x < width; x++)
        {
            plotter.plotPixel(x,y,color.R,color.G,color.B);
        }
    }
}