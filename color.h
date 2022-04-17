//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 
//Date Last Modified: 

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include <iostream>
using namespace std;


struct Color
{
    int R, G, B;

    /*
    * description:
    * return:
    * precondition:
    * postcondition:
    *
    */

    Color(int r=0, int g=0, int b=0)
    {
        R = r;
        G = g;
        B = b;
    }
};

#endif // COLOR_H_INCLUDED