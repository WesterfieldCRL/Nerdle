//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 
//Date Last Modified: 



/*
Data Abstraction:
Input: 
Process:
Output: 
Assumptions:
*/

#include <iostream>
#include "Tile.h"
#include "equationManip.h"
#include "SDL_Plotter.h"

//Compile using: plotter++ -oNameOfFile main.cpp SDL_Plotter.cpp -I /usr/include/SDL2/ -lSDL2 -lGL -lSDL2_mixer

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter plotter(500,500);
    int x,y; 
    int red, green, blue;
    Tile tile;
    Point point(50,50);
    Color gray(82,80,52);
    tile.setColor(gray);
    tile.setHeight(100);
    tile.setWidth(100);
    tile.setLocation(point);

    while (!plotter.getQuit()){

    	plotter.update();

        tile.draw(plotter);

    	if(plotter.kbhit()){
    	    plotter.getKey();
    	}

    }
}