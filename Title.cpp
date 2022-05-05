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

Tile titleTiles [titleX] [titleY];
Point titlep(titleXlocation,titleYlocation);

//create title files
for (int y = 0; y < tilesY; y++)
    {
        for (int x = 0; x < tilesX; x++)
        {
            titleTiles[x][y].setLocation(titlep);
            titleTiles[x][y].setColor(white);
            titleTiles[x][y].setWidth(tileWidth);
            titleTiles[x][y].setHeight(tileHeight);
            titleTiles[x][y].setLetter(letters[letterPop]);
            titlep.x += tileWidth+10;
            letterPop++;
        }
        titlep.y += tileHeight+10;
        titlep.x = tileXLocation;
    }

//draw title
for (int y = 0; y < keyYnum; y++)
{
    for (int x = 0; x < keyXnum; x++)
    {
        keyboard[x][y].draw(plotter, black);
    }
}
