#include <iostream>
#include <fstream>
#include <cstring>
#include "SDL_Plotter.h"

//Tile.h includes Point.h, color.h, and drawObject.h
#include "Tile.h"
#include "equationManip.h"

//Data Abstraction
ifstream file;
char letters [6] = {'N', 'E', 'R', 'D', 'L', 'E'};
int letterPop = 0;

for (int y = 0; y < tilesY; y++)
    {
        for (int x = 0; x < tilesX; x++)
        {
            tiles[x][y].setLocation(point);
            tiles[x][y].setColor(white);
            tiles[x][y].setWidth(tileWidth);
            tiles[x][y].setHeight(tileHeight);
            tiles[x][y].setLetter(letters[letterPop]);
            point.x += tileWidth+10;
            letterPop++;
        }
        point.y += tileHeight+10;
        point.x = tileXLocation;
    }
