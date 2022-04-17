//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 
//Date Last Modified: 

#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <iostream>
#include "Point.h"
#include "color.h"
#include "SDL_Plotter.h"

using namespace std;


class Tile
{
    private:
    Point p;
    int width;
    int height;
    Color color;
    char letter; 

    public:

    /*
    * description: constructs a tile object with default values for everything
    * return: tile object
    * precondition: none
    * postcondition: a tile object has been created
    *
    */

    Tile();

    /*
    * description: sets the location of the tile
    * return: void
    * precondition: a point object exists
    * postcondition: the point object is unchanged
    *
    */

    void setLocation(const Point&);

    /*
    * description: sets the width of the tile
    * return: void
    * precondition: some integer exists
    * postcondition: none
    *
    */

    void setWidth(int);

    /*
    * description: sets the height of the tile
    * return: void
    * precondition: some integer exists
    * postcondition: none
    *
    */

    void setHeight(int);

    /*
    * description: sets the color of the tile
    * return: void
    * precondition: some color object exists
    * postcondition: none
    *
    */

    void setColor(const Color&);

    /*
    * description: sets the character of the tile
    * return: void
    * precondition: some char exists
    * postcondition: none
    *
    */

    void setLetter(char);

    /*
    * description: returns the top left corner of the tile
    * return: point object
    * precondition: none
    * postcondition: a point object has been returned
    *
    */

    Point getLocation() const;

    /*
    * description: returns the width of the tile
    * return: integer
    * precondition: none
    * postcondition: a integer has been returned
    *
    */

    int getWidth() const;

    /*
    * description: returns the height of the tile
    * return: integer
    * precondition: none
    * postcondition: a integer has been returned
    *
    */

    int getHeight() const;

    /*
    * description: returns the color of the tile
    * return: color object
    * precondition: none
    * postcondition: a color object has been returned
    *
    */

    Color getColor() const;

    /*
    * description: returns the letter of the tile
    * return: char
    * precondition: none
    * postcondition: a char has been returned
    *
    */

    char getLetter() const;

    /*
    * description: draws the tile
    * return: void
    * precondition: a SDL_Plotter object exists
    * postcondition: the tile is unchanged
    *
    */

    void draw(SDL_Plotter&) const;

};


#endif // TILE_H_INCLUDED