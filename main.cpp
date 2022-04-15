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

#include "SDL_Plotter.h"

//Compile using: g++ main.cpp SDL_Plotter.cpp -I /usr/include/SDL2/ -lSDL2 -lGL -lSDL2_mixer

using namespace std;

int main(int argc, char ** argv)
{

    SDL_Plotter g(1000,1000);
    int x,y; 
    int red, green, blue;


    while (!g.getQuit()){

    	g.update();

    	if(g.kbhit()){
    	    g.getKey();
    	}

    }
}