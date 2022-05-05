//Author: Wesley Anastasi
<<<<<<< HEAD
//Assignment Title:
//Assignment Description:
=======
//Assignment Title: Nerdle
//Assignment Description: create Nerdle w/ SDL plotter
>>>>>>> 2d0b627e72573f6601a1f77c581d2a0feca34f8f
//Due Date: 5/5/2022
//Date Created: 4/15/2022
//Date Last Modified: 5/5/2022



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
#include <time.h>
#include "SDL_Plotter.h"

//Tile.h includes Point.h, color.h, and drawObject.h
#include "Tile.h"
#include "equationManip.h"

//Compile using: plotter++ -oNameOfFile main.cpp SDL_Plotter.cpp -I /usr/include/SDL2/ -lSDL2 -lGL -lSDL2_mixer
//Point.cpp, equationManip.cpp, drawObject.cpp, Tile.cpp

using namespace std;

int main(int argc, char ** argv)
{

    //Data Abstraction:

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
    int tileXLocation = 150;
    int tileYLocation = 50;
    int currTileX = 0;
    int currTileY = 0;

    int keyXlocation = 150;
    int keyYlocation = 600;
    int keyXnum = 9;
    int keyYnum = 2;
    //char keyIn [19] = {'0','1','2','3','4','5','6','7','8','9','+','-','*','/','=',5,SDL_SCANCODE_RETURN,'n'};
    int keyPop=0;
    int cursX, cursY;
    //Point cursor(cursX, cursY);


    bool endOfIndex = false;
    bool inside;

    int compare[8];
    int compareSum = 0;

    Color black(0,0,0);
    Color lightBrown(171,125,79);
    Color white(255,255,255);
    Color red(255,40,40);
    Color green(40,255,40);
    Color darkRed(94,29,25);
    Color yellow(194,168,0);

    Tile tiles[tilesX][tilesY];
    Tile keyboard [keyXnum] [keyYnum];
    Point Keyp(keyXlocation,keyYlocation);
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

    for (int y= 0; y < keyYnum; y++)
    {
        for (int x= 0; x < keyXnum; x++)
        {
            keyboard [x][y].setLocation(Keyp);
            keyboard [x][y].setColor(lightBrown);
            keyboard [x][y].setWidth(tileWidth);
            keyboard [x][y].setHeight(tileHeight);
            //keyboard [x][y].setLetter(keyIn[keyPop]);
            Keyp.x += tileWidth+10;
            keyPop++;
        }
        Keyp.y += tileHeight+10;
        Keyp.x = tileXLocation;
    }


    //draw keyboard
    for (int y = 0; y < keyYnum; y++)
    {
        for (int x = 0; x < keyXnum; x++)
        {
            keyboard[x][y].draw(plotter, black);
        }
    }

    generateEquation(master);

    point = tiles[currTileX][currTileY].getLocation();

    //draw main game board
    for (int y = 0; y < tilesY; y++)
    {
        for (int x = 0; x < tilesX; x++)
        {
            tiles[x][y].setLetter('n');
            tiles[x][y].draw(plotter, black);
        }
    }

    plotter.update();

    cout << userInput << endl;

    while (!plotter.getQuit())
    {
        if (resetInput)
        {
            for (int i = 0; i < 8; i++)
            {
                userInput[i] = 'n';
            }
            resetInput = false;
            cout << userInput << endl;
        }



        //getting user input
        if((plotter.getMouseClick(cursX, cursY)) && currTileY < 6)
        {
            inside = false;
            for (int x=0; x<keyXnum; x++)
            {
                for (int y=0; y<keyYnum; y++)
                {
                    if(keyboard[x][y].inside(cursX,cursY))
                       {
                           key=keyboard[x][y].getLetter();
                           inside = true;
                       }
                }
            }
            if (inside)
            {
                if (key == SDL_SCANCODE_RETURN && currTileX == 7)
                {
                    user.str(userInput);
                    cout << userInput << endl;
                    if (isValidEquation(user))
                    {
                        resetInput = true;
                        currTileX = 0;

                        compareEquations(master, user, compare);
                        for (int i = 0; i < 8; i++)
                        {
                            if (compare[i] == 0)
                            {
                                tiles[i][currTileY].setColor(darkRed);
                            }
                            else if (compare[i] == 1)
                            {
                                tiles[i][currTileY].setColor(yellow);
                            }
                            else
                            {
                                tiles[i][currTileY].setColor(green);
                            }
                            tiles[i][currTileY].draw(plotter, black);
                        }
                        currTileY++;
                    }
                    /*else if(!isValidEquation(user))
                    {
                        resetInput = true;
                        currTileX = 0;
                    }*/
                    user.str("");
                    user.clear();
                }
                else if (key == BACKSPACE)
                {
                    if (currTileX == 7&&endOfIndex)
                    {
                        userInput[currTileX] = 'n';
                        endOfIndex = false;
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
                    tiles[currTileX][currTileY].setLetter('n');
                    tiles[currTileX][currTileY].draw(plotter, black);
                }
                else if (key != SDL_SCANCODE_RETURN)
                {
                    tiles[currTileX][currTileY].setLetter(key);
                    userInput[currTileX] = key;
                    currTileX++;
                    if (currTileX > 7)
                    {
                        currTileX = 7;
                        endOfIndex = true;
                        tiles[currTileX][currTileY].draw(plotter, black);
                    }
                    else
                    {
                        tiles[currTileX-1][currTileY].draw(plotter, black);
                    }
                }
                key = 'n';
                plotter.update();
            }

        }
    }
}