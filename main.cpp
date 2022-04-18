//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/15/2022
//Date Last Modified: 4/17/2022



/*
Data Abstraction:
Input: 
Process:
Output: 
Assumptions:
*/

#include <iostream>
#include "Tile.h"
#include "drawObject.h"
#include "equationManip.h"
#include "SDL_Plotter.h"

//Compile using: plotter++ -oNameOfFile main.cpp SDL_Plotter.cpp -I /usr/include/SDL2/ -lSDL2 -lGL -lSDL2_mixer
//Point.cpp, Line.cpp, equationManip.cpp, drawObject.cpp, Tile.cpp

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter plotter(500,500);
    Tile tile;
    Point point1(50,50);
    Point point2(50,100);
    Point point3(100,50);
    Point point4(100,100);
    Line line1(point1, point2);
    Color gray(82,80,52);
    Color red(255,20,20);
    bool test = false;
    tile.setColor(gray);
    tile.setHeight(100);
    tile.setWidth(100);
    tile.setLocation(point1);


    while (!plotter.getQuit()){

    	plotter.update();

        //drawLine(line1, plotter, red);
        drawQuadrilateral(point1, point2, point3, point4, plotter, gray);

    	if(plotter.kbhit()){
    	    plotter.getKey();
    	}

    }
}