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

    char nerdleLetters[6] = {'N', 'E', 'R', 'D', 'L', 'E'};
    char winnerLetter[6] = {'W', 'I', 'N', 'N', 'E', 'R'};
    char loserLetter[6] = {'L', 'O', 'S', 'E', 'R', '!'};
    
    Tile titleTiles[6];
    Point titlep(tileXLocation,tileYLocation-tileHeight);

    srand(time(0));

    //Input/Process/Output:

    //create title files
    for (int i = 0; i < 6; i++)
    {
        titleTiles[i].setLocation(titlep);
        titleTiles[i].setColor(white);
        titleTiles[i].setWidth(40);
        titleTiles[i].setHeight(40);
        titleTiles[i].setLetter(nerdleLetters[i]);
        titleTiles[i].draw(plotter, black);
        titlep.x += 45;
    }

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


        //Input:
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

        //Process/Output;
        if (buttonPress && currTileY < 6)
        {
            buttonPress = false;
            //if the enter/return key is pressed and the active tile is at the end
            if (key == SDLK_RETURN && currTileX == 7)
            {
                //make sure stringstream is empty and fill it with the cstring with the input
                user.str("");
                user.clear();
                user.str(userInput);
                //checks if the equation is valid
                if (isValidEquation(user))
                {
                    //resetInput and move active tile to the front
                    resetInput = true;
                    currTileX = 0;

                    //get an array of ints from the compareEquations function
                    compareEquations(master, user, compare);
                    //if the int at index i is 0, then it does not exist in the equation
                    //if it is 1 then it exists but is in the wrong place
                    //if it is 2 then it is in the correct place
                    //then set the color accordingly
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
                    //move too the next row
                    currTileY++;
                }
                else //if the equation is not valid change all tiles to red briefly then change them back
                {
                    for (int i = 0; i < tilesX; i++)
                    {
                        tiles[i][currTileY].setColor(red);
                        tiles[i][currTileY].draw(plotter, black);
                    }
                    plotter.update();
                    //using sleep so that user cannot input anything untill back to normal
                    plotter.Sleep(1000);
                    for (int i = 0; i < tilesX; i++)
                    {
                        tiles[i][currTileY].setColor(lightBrown);
                        tiles[i][currTileY].draw(plotter, black);
                    }
                    plotter.update();
                }
            }
            else if (key == SDLK_DELETE) //if the key is backspace
            {
                //if active tile is end of index and is filled
                //set tile char to the empty variable
                //the bool is for when the active tile is the end of the row,
                //but it is filled
                if (currTileX == 7&&endOfIndex)
                {
                    userInput[currTileX] = 'n';
                    endOfIndex = false;
                }
                else //if the active tile is end of index and the tile is not filled
                {
                    //move the active tile backwards and set its character to nothing
                    currTileX--;
                    userInput[currTileX] = 'n';
                    //if the active tile has been moved before the front of the row then make it stay on the end
                    if (currTileX < 0)
                    {
                        currTileX = 0;
                    }
                }
                //erase the tile's char
                //and update the tiles drawing on the plotter
                tiles[currTileX][currTileY].setLetter('n');
                tiles[currTileX][currTileY].draw(plotter, black);
            }
            else if (key != SDLK_RETURN)
            {
                //needs to make sure its not the enter key because the first if will only trigger
                //if the active tile is at the end.

                //sets the active tile to whatever key was pressed
                tiles[currTileX][currTileY].setLetter(key);
                //sets the cstring at the current tile index to the char
                userInput[currTileX] = key;
                //draws the tile with the new char
                tiles[currTileX][currTileY].draw(plotter, black);
                //moves the active tile forwards
                currTileX++;
                //if the active tile is past the end move it to the end
                //endOfIndex is used for determining if the active tile is one the end and filled with a char
                //needed for the backspace
                if (currTileX > 7)
                {
                    currTileX = 7;
                    endOfIndex = true;
                }
            }
            //update the plotter
            plotter.update();
        }

        //upon a end condition, either getting the equation right or running out of turns
        if (win || currTileY > 5)
        {
            //erases the character from all colored tiles
            for (int y = 0; y < currTileY; y++)
            {
                for (int x = 0; x < tilesX; x++)
                {
                    tiles[x][y].setLetter('n');
                    tiles[x][y].draw(plotter, black);
                }
            }
            //if some tiles are not colored, erase them
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
            if (currTileY > 5)
            {
                for (int i = 0; i < 6; i++)
                {
                    titleTiles[i].setLetter(loserLetter[i]);
                    titleTiles[i].draw(plotter, darkRed);
                }
            }
            else
            {
                for (int i = 0; i < 6; i++)
                {
                    titleTiles[i].setLetter(winnerLetter[i]);
                    titleTiles[i].draw(plotter, green);
                }
            }
            plotter.update();
            plotter.Sleep(3000);
            plotter.setQuit(true);
        }

    }


    


    return 1;
}
