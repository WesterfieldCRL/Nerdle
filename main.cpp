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
    Point point1(190,50);
    Point point2(200,50);
    Point point3(50,200);
    Point point4(60,200);
    Line line1(point1, point3);
    Line line2(point2, point4);
    Line line3(point1, point2);
    Line line4(point3, point4);
    Color gray(82,80,52);
    Color red(255,20,20);
    bool test = false;
    tile.setColor(gray);
    tile.setHeight(100);
    tile.setWidth(100);
    tile.setLocation(point1);


    while (!plotter.getQuit()){

    	plotter.update();

        drawLine(line1, plotter, red);
        //drawLine(line2, plotter, red);
        //drawLine(line3, plotter, red);
        //drawLine(line4, plotter, red);

    	if(plotter.kbhit()){
    	    plotter.getKey();
    	}

    }
}