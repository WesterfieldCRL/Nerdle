//Author: Wesley Anastasi
//Assignment Title: 
//Assignment Description: 
//Due Date: 
//Date Created: 4/20/2022
//Date Last Modified: 4/20/2022

#include "arrayDraw.h"

void drawRectangleArray(int x, int y, int width, int height, int array[][10], int num)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << array[j][i];
        }
        cout << endl;
    }
}