//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/15/2022
//Date Last Modified: 4/19/2022



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
#include <chrono>

//Compile using: plotter++ -oNameOfFile main.cpp SDL_Plotter.cpp -I /usr/include/SDL2/ -lSDL2 -lGL -lSDL2_mixer
//Point.cpp, equationManip.cpp, drawObject.cpp, Tile.cpp

using namespace std;

int main(int argc, char ** argv)
{

    auto start = chrono::steady_clock::now();
    SDL_Plotter plotter(500,500);
    Color gray(82,80,52);
    Color red(255,20,20);
    Color white(255,255,255);
    int drawWidth = 40;
    int drawHeight = 50;
    bool test = false;
    int xSpeed = 1;
    int ySpeed = 2;
    Point point(50,50);
    Tile tile(point, 50, 50, gray);
    auto now = chrono::steady_clock::now();

    while (!plotter.getQuit())
    {
        plotter.update();
        now = chrono::steady_clock::now();
        drawOne(point, drawWidth, drawHeight, plotter, red, white);
        if (chrono::duration_cast<chrono::milliseconds>(now-start).count() >= 16.7)
        {
            point.x+=xSpeed;
            point.y+=ySpeed;
            if (point.x < 0 || point.x + drawWidth > plotter.getCol())
            {
                xSpeed *= -1;
            }
            if (point.y < 0 || point.y + drawHeight> plotter.getRow())
            {
                ySpeed *= -1;
            }
            start = chrono::steady_clock::now();
        }
        drawOne(point, drawWidth, drawHeight, plotter, red, gray);
        if(plotter.kbhit())
        {
            plotter.getKey();
        }
    }
}