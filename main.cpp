//Author: Wesley Anastasi, Madison Thomas, Seth Kacura, Chris Garcia, Christian Saldana, Daigon Fontenot
//Assignment Title: Nerdle
//Assignment Description: create Nerdle w/ SDL plotter
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

    SDL_Plotter plotter(800,800);
    stringstream user;
    stringstream master;
    char userInput[8];
    char key;
    bool resetInput = true;
    bool buttonPress = false;
    bool endOfIndex = false;
    bool win = false;
    bool inside;
    int tilesX = 8;
    int tilesY = 6;
    int tileWidth = 50;
    int tileHeight = 50;
    int tileXLocation = 150;
    int tileYLocation = 200;
    int currTileX = 0;
    int currTileY = 0;
    int keyXlocation = 150;
    int keyYlocation = 600;
    int keyXnum = 9;
    int keyYnum = 2;
    int cursX, cursY;
    int compareSum;

    int compare[8];

    Color black(0,0,0);
    Color gray(100,100,100);
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

    //Input/Process:

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

    //draw keyboard
    for (int y = 0; y < 2; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            keyboard[x][y].draw(plotter, black);
        }
    }

    generateEquation(master);

    cout << master.str() << endl;

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

    //while the plotter is not told to quit
    while (!plotter.getQuit())
    {
        //sets userInput to = nnnnnnnn
        //since n tells the tile class to not draw a char
        if (resetInput)
        {
            for (int i = 0; i < 8; i++)
            {
            key = plotter.getKey();
                userInput[i] = 'n';
            }
            resetInput = false;
        }


        //getting user input

        if(plotter.kbhit())
        {
            key = plotter.getKey();
            //if key is a valid input run the main event block
            //checks for the askii values between * and 9 and excludes , and .
            //the SDLK's and = are not in that range so they get seperate statements
            if ((key >= 42 && key <= 57 && key != ',' && key != '.')||key == SDLK_RETURN||key == SDLK_DELETE||key == '=')
            {
                buttonPress = true;
            }
        }

        if (buttonPress && currTileY < 6)
        {
            buttonPress = false;
            if (key == SDLK_RETURN && currTileX == 7)
            {
                user.str(userInput);
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
            else if (key == SDLK_DELETE)
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
            else if (key != SDLK_RETURN)
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

        //Takes values from the compare array, if equal to 16 (total possible with all 2s)
        //returns a win condition
        compareSum=0;
        for (int i = 0; i < 8; i++)
        {
            compareSum = compareSum+compare[i];
        }

        if(compareSum == 16){
            win = true;
        }

        //sets removes characters from all used tiles and clears all unsued ones
        if (win || currTileY > 5)
        {
            for (int y = 0; y < currTileY; y++)
            {
                for (int x = 0; x < tilesX; x++)
                {
                    tiles[x][y].setLetter('n');
                    tiles[x][y].draw(plotter, black);
                }
            }
            if (currTileY < 6)
            {
                for (int y = currTileY; y < 6; y++)
                {
                    for (int x = 0; x < tilesX; x++)
                    {
                        tiles[x][y].setColor(white);
                        tiles[x][y].draw(plotter,black);
                    }
                }
            }
            plotter.update();
        }

    }


    


    return 1;
}
