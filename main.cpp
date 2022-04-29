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
#include "Tile.h"
#include "Point.h"
#include "equationManip.h"
#include "SDL_Plotter.h"
#include "drawObject.h"

//Compile using: plotter++ -oNameOfFile main.cpp SDL_Plotter.cpp -I /usr/include/SDL2/ -lSDL2 -lGL -lSDL2_mixer
//Point.cpp, equationManip.cpp, drawObject.cpp, Tile.cpp

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter plotter(1000,1000);
    Color gray(82,80,52);
    Color red(255,20,20);
    Color white(255,255,255);
    int width = 350;
    int height = 500;
    bool test = false;
    int xSpeed = 1;
    int ySpeed = 2;
    Point point(200,200);
    Tile tile(point, 50, 50, gray, '2');

    while (!plotter.getQuit())
    {
        plotter.update();

        //use clock()?

        tile.draw(plotter);

        if(plotter.kbhit())
        {
            plotter.getKey();
        }
    }
}