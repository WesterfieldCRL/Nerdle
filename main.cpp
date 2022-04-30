//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/15/2022
//Date Last Modified: 4/28/2022



/*
Data Abstraction:
Input: 
Process:
Output: 
Assumptions:
*/

#include <iostream>
#include <sstream>
#include <cstring>
#include "SDL_Plotter.h"

//Tile.h includes Point.h, color.h, and drawObject.h
#include "Tile.h"
#include "equationManip.h"

//Compile using: plotter++ -oNameOfFile main.cpp SDL_Plotter.cpp -I /usr/include/SDL2/ -lSDL2 -lGL -lSDL2_mixer
//Point.cpp, equationManip.cpp, drawObject.cpp, Tile.cpp

using namespace std;

int main(int argc, char ** argv)
{

    //Data Abastraction:

    stringstream user;
    stringstream master;
    char userInput[8];
    char key;
    char BACKSPACE = 5;
    bool resetInput = true;
    SDL_Plotter plotter(800,800);
    int tilesX = 8;
    int tilesY = 6;
    int tileWidth = 50;
    int tileHeight = 50;
    int tileXLocation = 225;
    int tileYLocation = 50;
    int currTileX = 0;
    int currTileY = 0;
    bool endOfIndex = false;

    int compare[8];

    Color black(0,0,0);
    Color lightBrown(171,125,79);
    Color white(255,255,255);
    Color red(255,40,40);
    Color green(40,255,40);
    Color darkRed(94,29,25);
    Color yellow(194,168,0);

    Tile tiles[tilesX][tilesY];
    Point point(tileXLocation,tileYLocation);

    srand(time(0));


    //Set position of tiles
    for (int y = 0; y < tilesY; y++)
    {
        for (int x = 0; x < tilesX; x++)
        {
            tiles[x][y].setLocation(point);
            tiles[x][y].setColor(lightBrown);
            tiles[x][y].setWidth(tileWidth);
            tiles[x][y].setHeight(tileHeight);
            //n letting tile know not to draw any char
            tiles[x][y].setLetter('n');
            point.x += tileWidth+10;
        }
        point.y += tileHeight+10;
        point.x = tileXLocation;
    }

    generateEquation(master);

    point = tiles[currTileX][currTileY].getLocation();

    while (!plotter.getQuit())
    {
        plotter.update();

        if (resetInput)
        {
            for (int i = 0; i < 8; i++)
            {
                userInput[i] = 'n';
            }
            resetInput = false;
        }



        //getting user input
        if(plotter.kbhit())
        {
            key = plotter.getKey();
            if (key=='0'||key=='1'||key=='2'||key=='3'||key=='4'||key=='5'||key=='6'||key=='7'||key=='8'||key=='9'||key=='+'||key=='-'||key=='*'||key=='/'||key=='=')
            {
                tiles[currTileX][currTileY].setLetter(key);
                userInput[currTileX] = key;
                currTileX++;
                if (currTileX > 7)
                {
                    currTileX = 7;
                    endOfIndex = true;
                }
            }
            else if (key == SDL_SCANCODE_RETURN && currTileX == 7)
            {
                user.str(userInput);
                if (isValidEquation(user))
                {
                    resetInput = true;
                    currTileX = 0;
                    currTileY++;
                    compareEquations(master, user, compare);
                    for (int i = 0; i < 8; i++)
                    {
                        if (compare[i] == 0)
                        {
                            tiles[i][currTileY-1].setColor(darkRed);
                        }
                        else if (compare[i] == 1)
                        {
                            tiles[i][currTileY-1].setColor(yellow);
                        }
                        else
                        {
                            tiles[i][currTileY-1].setColor(green);
                        }
                    }
                }
                user.str("");
                user.clear();
            }
            else if (key == BACKSPACE)
            {
                if (currTileX == 7&&endOfIndex)
                {
                    userInput[currTileX] = 'n';
                    endOfIndex = false;;
                }
                else
                {
                    currTileX--;
                    userInput[currTileX] = 'n';
                    if (currTileX < 0)
                    {
                        currTileX = 0;
                    }
                }
            }
        }



        for (int i = 0; i < 8; i++)
        {
            tiles[i][currTileY].setLetter(userInput[i]);
        }


        //Update Tiles
        for (int y = 0; y < tilesY; y++)
        {
            for (int x = 0; x < tilesX; x++)
            {
                tiles[x][y].draw(plotter, black);
            }
        }

        drawOutline(point,tileWidth,tileHeight,plotter,red);
        point = tiles[currTileX][currTileY].getLocation();
        drawOutline(point,tileWidth,tileHeight,plotter,red);
    }
}